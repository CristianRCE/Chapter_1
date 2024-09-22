#include "mbed.h"
#include "arm_book_lib.h"

int main()
{
    // DIGITAL INPUTS
    DigitalIn gasDetector(D2);
    DigitalIn overTempDetector(D3);
    DigitalIn alarmOffButton(BUTTON1);
    //DIGITAL OUTPUTS
    DigitalOut alarmLed(LED2);
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

        alarmLed = alarmState;

        if(alarmOffButton)
        {
            alarmState = OFF;
        }

        alarmLed = alarmState;
    }
}
