#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "misaligned.h"

//Function to print color pattern
int printColorMap(void (*GetColorPattern)(char*, int, int)) {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;
    char colorPairNames[MAX_COLORPAIR_NAME_CHARS];
    memset(colorPairNames, 0, MAX_COLORPAIR_NAME_CHARS);
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            sprintf(colorPairNames, "%d | %s | %s\n", i * 5 + j + 1, majorColor[i], minorColor[j]);
            //Display color patterns
            printf("\n%s",colorPairNames);
            if(GetColorPattern != 0){
                (*GetColorPattern)(colorPairNames, i, j);
            }
        }
    }
    return i * j;
}

//Get Expected color pattern
void GetColorPattern(char* colorPattern, int majorIndex, int minorIndex){

    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    static char ExpectedColorPairNames[MAX_COLORPAIR_NAME_CHARS];
    int numberOfMinorColors =  sizeof(minorColor) / sizeof(minorColor[0]);
    memset(ExpectedColorPairNames, 0, MAX_COLORPAIR_NAME_CHARS);
    sprintf(ExpectedColorPairNames, "%d | %s | %s\n", majorIndex * numberOfMinorColors + minorIndex + 1
                                           , majorColor[majorIndex], minorColor[minorIndex]);
    //Assertion for color pattern
    assert(memcmp(colorPattern, ExpectedColorPairNames, MAX_COLORPAIR_NAME_CHARS) == 0);
}


//Main function
int main(void){

    assert(printColorMap(GetColorPattern) == 25);
    printf("\nmisaligned file - Bye");
    return 0;
}









