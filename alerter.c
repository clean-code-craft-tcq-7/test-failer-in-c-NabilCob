#include <stdio.h>
#include <assert.h>
#include "config.h"
#include "alerter.h"

//Variable to holder failure count on alert
int alertFailureCount = 0;

#ifdef STUB
// Stub function for network alerter
int networkAlertStub(float celcius) {
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    // Return 200 for ok
    // Return 500 for not-ok
    // stub always succeeds and returns 200
    if(celcius > 100.0){
        return 500;
    }
    else{
        return 200;
    }
}
#endif

//Function to caculate Celcius from farenheit
void alertInCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode;
#ifdef STUB
    returnCode = networkAlertStub(celcius);
#endif
    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 0;
    }
}


//Main function
int main(void){
     alertInCelcius(400.5);
#ifdef TEST
    assert(alertFailureCount == 1);
#endif
    
    alertInCelcius(303.6);
#ifdef TEST
    assert(alertFailureCount == 1);
#endif
    printf("\n alerter file - Bye");
}


