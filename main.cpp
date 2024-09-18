#include "mbed.h"
#include "arm_book_lib.h"

int main()
{
    // DIGITAL INPUTS
    DigitalIn gasDetector(D2);
    DigitalIn overTempDetector(D3);
    DigitalIn alarmOffButton(D4);
    //DIGITAL OUTPUTS
    DigitalOut alarmLed(LED1);
    //INPUT STATES
    gasDetector.mode(PullDown);
    overTempDetector.mode(PullDown);
    alarmOffButton.mode(PullDown);
    // INITIAL STATES
    alarmLed = OFF;
    //BOOLEAN STATES
    bool alarmState = OFF;

    while (true)
    {
        if(gasDetector || overTempDetector)
        {
            alarmState = ON;
        }
        if(alarmOffButton == ON)
        {
            alarmState = OFF;
        }
        alarmLed = alarmState;
    }
}
