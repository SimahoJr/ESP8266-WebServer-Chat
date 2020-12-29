#include <SmallFS.h>

long timezone = 2;
byte daysavetime = 1;

bool little_begin(){
  // USE_SERIAL.println("Formatting LittleFS filesystem");
  // LittleFS.format();
  USE_SERIAL.println();
  USE_SERIAL.println();
  USE_SERIAL.println("Mount LittleFS");
  if (!LittleFS.begin()) {
    USE_SERIAL.println("LittleFS mount failed");
    return false;
  }
  else{
    USE_SERIAL.println("LittleFS Mounted");
    USE_SERIAL.println();
    return true;
  }
}
bool little_getLocalTime(struct tm * info, uint32_t ms) {
  uint32_t count = ms / 10;
  time_t now;

  time(&now);
  localtime_r(&now, info);

  if (info->tm_year > (2016 - 1900)) {
    return true;
  }

  while (count--) {
    delay(10);
    time(&now);
    localtime_r(&now, info);
    if (info->tm_year > (2016 - 1900)) {
      return true;
    }
  }
  return false;
}


void little_listDir(const char * dirname) {
  USE_SERIAL.printf("Listing directory: %s\n", dirname);

  Dir root = LittleFS.openDir(dirname);

  while (root.next()) {
    File file = root.openFile("r");
    USE_SERIAL.print("  FILE: ");
    USE_SERIAL.print(root.fileName());
    USE_SERIAL.print("  SIZE: ");
    USE_SERIAL.print(file.size());
  }
  USE_SERIAL.println();
  USE_SERIAL.println();
}


String little_readFile(const char * path) {
  String read_contents = "";
  USE_SERIAL.printf("Reading file: %s\n", path);
  File file = LittleFS.open(path, "r");
  if (!file) {
    USE_SERIAL.println("Failed to open file for reading");
    read_contents = "Failed to Read";
    return read_contents;
  }
  else{
    while (file.available()) {
      // USE_SERIAL.write(file.read());
      read_contents += file.readString();
    }
    USE_SERIAL.println("Read Successifully");
    USE_SERIAL.print("  ");
    USE_SERIAL.println();
    file.close();
    // USE_SERIAL.println(read_contents);
    return read_contents;
  }
  
}

void little_writeFile(const char * path, const char * message) {
  USE_SERIAL.printf("Writing file: %s\n", path);

  File file = LittleFS.open(path, "w");
  if (!file) {
    USE_SERIAL.println("Failed to open file for writing");
    return;
  }
  if (file.print(message)) {
    USE_SERIAL.println("File written");
  } else {
    USE_SERIAL.println("Write failed");
  }
  delay(2000); // Make sure the CREATE and LASTWRITE times are different
  file.close();
}

void little_appendFile(const char * path, const char * message) {
  USE_SERIAL.printf("Appending to file: %s\n", path);

  File file = LittleFS.open(path, "a");
  if (!file) {
    USE_SERIAL.println("Failed to open file for appending");
    return;
  }
  if (file.print(message)) {
    USE_SERIAL.println("Message appended");
  } else {
    USE_SERIAL.println("Append failed");
  }
  file.close();
}

void little_renameFile(const char * path1, const char * path2) {
  USE_SERIAL.printf("Renaming file %s to %s\n", path1, path2);
  if (LittleFS.rename(path1, path2)) {
    USE_SERIAL.println("File renamed");
  } else {
    USE_SERIAL.println("Rename failed");
  }
}

void little_deleteFile(const char * path) {
  USE_SERIAL.printf("Deleting file: %s\n", path);
  if (LittleFS.remove(path)) {
    USE_SERIAL.println("File deleted");
  } else {
    USE_SERIAL.println("Delete failed");
  }
}