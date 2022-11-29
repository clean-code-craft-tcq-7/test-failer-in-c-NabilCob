#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "Tshirts.h"
#include "Misaligned.h"
#include "Alerter.h"
#include "Testfunctions.h"

extern int alertFailureCount;


//TC1 - Test size function
void TestTshirtSize(void){

    assert(size(37) == 'S');
    assert(size(40) == 'M');
    assert(size(43) == 'L');
    assert(size(0) == '\0');
    assert(size(-1) == '\0');
    assert(size(38) == 'M');
    assert(size(42) == 'L');

}

//TC2 - Test print color pattern function
void TestPrintColourPattern(void){
    assert(printColorMap(GetExpectedColorPair) == 25);

}

//TC3 - Test alerter function
void TestAlerterFunction(void){
    alertInCelcius(400.5);
    assert(alertFailureCount == 1);
    alertInCelcius(303.6);
    assert(alertFailureCount == 2);
}

//Get Expected color pattern
char* GetExpectedColorPair(int majorIndex, int minorIndex){

    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    static char ExpectedColorPairNames[MAX_COLORPAIR_NAME_CHARS];
    int numberOfMinorColors =  sizeof(minorColor) / sizeof(minorColor[0]);
    memset(ExpectedColorPairNames, 0, MAX_COLORPAIR_NAME_CHARS);
    sprintf(ExpectedColorPairNames, "%d | %s | %s\n", majorIndex * numberOfMinorColors + minorIndex + 1
                                           , majorColor[majorIndex], minorColor[minorIndex]);
    return ExpectedColorPairNames;
}




