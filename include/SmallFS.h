#include <Arduino.h>
#include <LittleFS.h>
#include <config.h>

#ifndef USE_SERIAL
#define USE_SERIAL Serial
#endif /* Serial */

bool little_getLocalTime(struct tm * info, uint32_t ms);
void little_listDir(const char * dirname);
String little_readFile(const char * path);
void little_writeFile(const char * path, const char * message);
void little_appendFile(const char * path, const char * message);
void little_renameFile(const char * path1, const char * path2);
void little_deleteFile(const char * path);
bool little_begin();

