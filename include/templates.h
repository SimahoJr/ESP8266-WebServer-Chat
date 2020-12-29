#include <Arduino.h>
#include "SmallFS.h"
#include "config.h"

#ifndef USE_SERIAL
#define USE_SERIAL Serial
#endif /* Serial */

String indexHTML();