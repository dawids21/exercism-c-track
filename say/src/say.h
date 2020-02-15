#ifndef SAY_H
#define SAY_H

#include <stdint.h>

#define BUFFER 200
#define CHUNK 30
#define MAX_NUM_OF_CHUNKS 5

int say(int64_t input, char **ans);

#endif
