#include <stdio.h>
#include <assert.h>
#include "alerter.h"

//Variable to holder failure count on alert
int alertFailureCount = 0;

// Stub function for network alerter
int networkAlertStub(float celcius) {
    printf("\nALERT: Temperature is %.1f celcius.\n", celcius);
    // Return 200 for ok
    // Return 500 for not-ok
    // stub always succeeds and returns 200
    if(celcius > 38.1){
        return 500;
    }
    else{
        return 200;
    }
}

//Function to caculate Celcius from farenheit
void alertInCelcius(float farenheit, int (*networkAlerter)(float)) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode;
    if(networkAlerter != 0){
        returnCode = (*networkAlerter)(celcius);
    }
    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 1;
    }
}

//Main function
int main(void){
    alertInCelcius(97, networkAlertStub);
    alertInCelcius(100.5, networkAlertStub);
    alertInCelcius(303.6, networkAlertStub);
    assert(alertFailureCount == 1);

    printf("\nalerter file - Bye");
    return 0;
}



