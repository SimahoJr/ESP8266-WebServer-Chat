Little FS on VS Code: https://docs.platformio.org/en/latest/platforms/espressif8266.html#selecting-appropriate-filesystem

https://diyprojects.io/esp8266-upload-data-folder-spiffs-littlefs-platformio/#.X8Djxi2w2qA

PLUG AND UNPLUG

The SPIFFS file system is used by default in order to keep legacy project compatible. To choose LittleFS as the file system, it should be explicitly specified using board_build.filesystem option in “platformio.ini” (Project Configuration File), for example:
[env:myenv]
platform = espressif8266
framework = arduino
board = ...
board_build.filesystem = littlefs
More information about pros and cons of each file system can be found in the official documentation.
Uploading files to Filesystem
Warning
Please make sure to read ESP8266 Flash layout information first.
1.	Create new project using PlatformIO IDE or initialize project using PlatformIO Core (CLI) and pio project init (if you have not initialized it yet)
2.	Create data folder (it should be on the same level as src folder) and put files here. Also, you can specify own location for data_dir
3.	Run “Upload File System image” task in PlatformIO IDE or use PlatformIO Core (CLI) and pio run --targetcommand with uploadfs target.
To upload file system image using OTA update please specify upload_port / --upload-port as IP address or mDNS host name (ending with the *.local). For the details please follow to Over-the-Air (OTA) update.
By default, will be used default LD Script for the board where is specified file system offsets (start, end, page, block). You can override it using Flash Size.
Active discussion is located in issue #382.

