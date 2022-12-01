#include <stdio.h>
#include <assert.h>
#include "tshirts.h"


//Function returns the size
char size(int cms) {
    char sizeName = '\0';
    if(cms < 38) {
        sizeName = 'S';
    } else if(cms > 38 && cms < 42) {
        sizeName = 'M';
    } else if(cms > 42) {
        sizeName = 'L';
    }
    return sizeName;
}

//Main Function
int main(void)
{
    assert(size(37) == 'S');
    assert(size(40) == 'M');
    assert(size(43) == 'L');
    assert(size(0) == '\0');
    assert(size(-1) == '\0');
    assert(size(38) == 'M');
    assert(size(42) == 'L');

    printf("n tshirts file - Bye");
    return 0;
}
