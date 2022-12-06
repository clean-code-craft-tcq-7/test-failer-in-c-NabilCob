#ifndef MISALIGNED_H_
#define MISALIGNED_H_

//Macro, Enum and structure definition
#define MAX_COLORPAIR_NAME_CHARS (16)

//Function declaration
int printColorMap(void (*GetColorPattern)(char*, int, int));
void GetColorPattern(char* colorPattern, int majorIndex, int minorIndex);

#endif
