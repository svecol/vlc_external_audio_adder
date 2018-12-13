# vlc_external_audio_adder
A program aimed to make adding external audio tracks to a video in [VLC](https://www.videolan.org) easier.

 This program is meant to make VLC media player to automatically play external audio files with corresponding video. It gets video file path as an argument and looks for audio files with the same name (or prefix + same name + posfix) in the same folder and its subfolders. Then it runs vlc with specific arguments, e.g.:

`"C:/Program Files/VideoLAN/VLC/vlc.exe" "file:///path_to_the_video/video_name.mkv" :input-slave="file:///path_to_the_video/subfolder1/video_name.mka"#"file:///path_to_the_video/subfolder2/video_name.mka" :file-caching=300`
 
 The same result can be achieved in vlc gui by going to file->open multiple files, checking "show more options" and "play another media synchronously" checkboxes and then chosing audio files, but this can be rather time-consuming.
 
 ## How to use
  1. Download zip archieve from [here](https://github.com/wc011/vlc_external_audio_adder/releases/download/v0.1.0/vlc_external_audio_adder.zip) or from the "release" section above, and unpack the archive.
  1. Place the executive file vlc_external_audio_adder.exe and vlc_external_audio_adder.ini somewhere in same directory.
  1. In .ini file write path of your vlc.exe program (e.g."C:/Program Files/VideoLAN/VLC/vlc.exe"). It has to have slashes (/) and not backslashes (\).
  1. Select video file you want to play. External audio tracks have to be in the same folder or its subfolders and have similar names (e.g. smth_s01e02.mkv and smth_s01e02.mka).
  1. Right-click the video file, choose "Open with" in context menu and select "vlc_external_audio_adder.exe".
  1. Have nice time watching the video!
  
  ## Things to do
  Any help with improving the code and its functionality is much appreciated!
  - [ ] Realisation of ability to automatically add external subtitles
  - [ ] Test on Linux
  
  ## Useful stuff
  * In vlc you can easily change subtitles and audio track by pressing "V" and "B" correspondingly.
  * [VLC command line help](https://wiki.videolan.org/VLC_command-line_help/)
  
  # vlc_external_audio_adder - описание на русском
Программа, призванная облегчить добавление внешних аудио дорожек к видео в [VLC](https://www.videolan.org).

 Эта программа автоматически находит и подклчает внешние дорожки к видеофайлу в VLC. Путь к видеофайлу она получает в виде аргумента при запуске, после чего ищет аудиофайлы с похожими названиями в соседних папках (например, в папке Sound и подпапках - так часто организованны раздачи на торрентах). Затем она запускает vlc с соответствующими аргументами, например вот так: 

`"C:/Program Files/VideoLAN/VLC/vlc.exe" "file:///path_to_the_video/video_name.mkv" :input-slave="file:///path_to_the_video/subfolder1/video_name.mka"#"file:///path_to_the_video/subfolder2/video_name.mka" :file-caching=300`
 
 Того же самого эффекта можно добиться в графическом интерфейсе VLC, если открыть меню Файл -> Открыть несколько файлов, нажать "Показать больше опций" и "Проигрывать синхронно", а затем выбрать нужные аудио файлы. Однако делать это каждый раз вручную может быть довольно муторно.
 
 ## Использование
  1. Скачайте архив с программой отсюда [here](https://github.com/wc011/vlc_external_audio_adder/releases/download/v0.1.0/vlc_external_audio_adder.zip) или из раздела release сверху. Распакуйте архив.
  1. Разместите исполняемый файл vlc_external_audio_adder.exe и vlc_external_audio_adder.ini где-нибудь в одной папке.
  1. В .ini файле впишите Ваш адрес программы VLC.exe (например, "C:/Program Files/VideoLAN/VLC/vlc.exe"). Адрес должен содержать только прямые слешы (/), а не обратыные (\).
  1. Выберите видео, которое хотите проиграть. Внешние аудио дорожки должны находиться пососедству и иметь похожие имена файлов. (например, smth_s01e02.mkv и smth_s01e02.mka).
  1. Нажмите на видео файл правой кнопкой мыши, выберите Открыть с помощью и выберите "vlc_external_audio_adder.exe".
  1. Наслаждайтесь просмотром!
  
  ## Что ещё можно сделать
  Приветствуется любая помощь по улучшению кода и функционала программы!
  - [ ] Реализовать возможность автоматического подключения субтиров
  - [ ] Проверить на Linux
  
  ## Полезное 
  * В VLC при просмотре можно легко менять субтитры и аудио дорожку кнопками "V" и "B" соответственно.
  * [Справка по командам командной строки VLC](https://wiki.videolan.org/VLC_command-line_help/)
  
  
