#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "Config.h"
#include "Misaligned.h"


//Function to print color pattern
int printColorMap(char * (*GetExpectedColorPair)(int, int)) {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;
    char colorPairNames[MAX_COLORPAIR_NAME_CHARS];
    memset(colorPairNames, 0, MAX_COLORPAIR_NAME_CHARS);


    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            sprintf(colorPairNames, "%d | %s | %s\n", i * 5 + j, majorColor[i], minorColor[i]);
            assert(memcmp(colorPairNames, GetExpectedColorPair(i, j), MAX_COLORPAIR_NAME_CHARS)
                            == 0);

        }
    }
    return i * j;
}






