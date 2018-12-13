/*
* vlc_external_audio_adder.cpp
*  Created on: 8 dec. 2018.
*  Author: wc011
*
* This program is meant to make vlc media player to automatically play external audio files with
* corresponding video. It gets video file path as an argument and looks for audio files with the same name
* (or prefix + same name + posfix) in the same folder and its subfolders. Then it runs vlc specific
* arguments, e.g.:
*
* "C:/Program Files/VideoLAN/VLC/vlc.exe" "file:///path_to_the_video/video_name.mkv" :input-slave="file:///path_to_the_video/subfolder1/video_name.mka"#"file:///path_to_the_video/subfolder2/video_name.mka" :file-caching=300
*
* The same result can be achieved in vlc gui by going to file->open multiple files, checking "show more options"
* and "play another media synchronously" and then chosing audio files, but it can be rather time-consuming.
*
* There has to be an .ini file in the same directory, as the .exe. Ini has to have following lines in it:
[default]
vlc_path=C:/Program Files/VideoLAN/VLC/vlc.exe
* 
* https://github.com/wc011/vlc_external_audio_adder
*
* wc011/vlc_external_audio_adder is licensed under the GNU General Public License v3.0
*/

#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <experimental/filesystem>
#include <Windows.h>

using namespace std;
using namespace std::experimental::filesystem;

vector <path> look_for_files_name_extensions(const path& dir, const path& name, set<path> extensions)
{
	vector <path> result;
	for (auto& p : recursive_directory_iterator(dir))
	{
		if (( is_regular_file(p) ) && (extensions.find(path(p).extension()) != extensions.end()) && (name.wstring().find(path(p).stem().wstring() ) != wstring::npos))
		{
			result.push_back(p);
		}
	}
	return result;
}

path path_for_vlc()
{
	wchar_t buf[256];
	GetPrivateProfileString(L"default",
		L"vlc_path",
		L"C:/Program Files/VideoLAN/VLC/vlc.exe",
		buf,
		256,
		L"./vlc_external_audio_adder.ini");
	return path(buf);
}

int main(int argc, char **argv)
{
	path vlc = path_for_vlc();

	//Check the input
	if (argc != 2)
	{
		cerr << "You have to specify 1 video file path as argument to open!\n";
		return 1;
	}

	path video_path(argv[1]);
	if (! is_regular_file(video_path))
	{
		cerr << "The argument must be a file path!\n";
		return 1;
	}

	//Form a wstirng with arguments to pass to VLC
	wstring cmd_to_run;
	//cmd_to_run = L'"' + vlc.c_str() + L'"';
	cmd_to_run += L" \"file:///";
	cmd_to_run += video_path.c_str();
	cmd_to_run += L"\"";

	//Look for external audio in the same directory and its subdirectories
	set <path> audio_extensions{ ".ac3", ".mka", ".mp3" };
	vector <path> external_audio_paths = look_for_files_name_extensions(video_path.parent_path(),
		video_path.stem(), audio_extensions);
	if (external_audio_paths.size() > 0)
	{
		cmd_to_run += L" :input-slave=";
		for (auto& p : external_audio_paths)
		{
			cmd_to_run += L"\"file:///";
			cmd_to_run += p.c_str();
			cmd_to_run += L"\"#";
		}
		cmd_to_run.pop_back(); // delete unnecessary #-character

		cmd_to_run += L" :file-caching=1500";
	}
	ShellExecute(NULL, L"open", vlc.c_str(), cmd_to_run.c_str(), video_path.parent_path().c_str(), SW_SHOWDEFAULT);
	return 0;
}