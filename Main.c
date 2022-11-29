#include <stdio.h>
#include "Config.h"

#ifdef TEST
#include "Testfunctions.h"
#endif

//Main Function
int main(void) {

#ifdef TEST
    //TC1 - Test size function
    //TestTshirtSize();
    //TC2 - Test print color pattern function
    TestPrintColourPattern();
    //TC3 - Test alerter function
    //TestAlerterFunction();
#endif
    printf("\n Bye");

    return 0;
}
