#ifndef ALERTER_H_
#define ALERTER_H_

//Function declaration
void alertInCelcius(float farenheit, int (*networkAlerter)(float));
int networkAlertStub(float celcius);

#endif
