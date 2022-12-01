#ifndef ALERTER_H_
#define ALERTER_H_

//Structure, enum and macro definitions
typedef int (*networkAlerter_Funcptr)(float);

//Function declaration
void alertInCelcius(float farenheit);
int networkAlertStub(float celcius);

#endif
