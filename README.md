How Do i upload?
Using platfromio on VS Code; Clone the repository and open using platformio.
1. Connect the ESP
2. Upload Data
3. Upload Code
Done

Using Platformio CLI (Not Tried)
Please make sure to read ESP8266 Flash layout information first.
1.	Create new project using PlatformIO IDE or initialize project using PlatformIO Core (CLI) and pio project init (if you have not initialized it yet)
2.	Create data folder (it should be on the same level as src folder) and put files here. Also, you can specify own location for data_dir
3.	Run “Upload File System image” task in PlatformIO IDE or use PlatformIO Core (CLI) and pio run --targetcommand with uploadfs target.
To upload file system image using OTA update please specify upload_port / --upload-port as IP address or mDNS host name (ending with the *.local). For the details please follow to Over-the-Air (OTA) update.
By default, will be used default LD Script for the board where is specified file system offsets (start, end, page, block). You can override it using Flash Size.


Little FS on VS Code: https://docs.platformio.org/en/latest/platforms/espressif8266.html#selecting-appropriate-filesystem
https://diyprojects.io/esp8266-upload-data-folder-spiffs-littlefs-platformio/#.X8Djxi2w2qA

