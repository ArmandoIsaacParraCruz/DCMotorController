#include "MyEncoder.h"

MyEncoder::MyEncoder(int8_t encoderPhaseA, int8_t encoderPhaseB)
{
    int8_t interruptMode = RISING;
    #ifdef INPUT_PULLUP
        pinMode(encoderPhaseA, INPUT_PULLUP);
        #else
        pinMode(encoderPhaseA, interruptMode);
        digitalWrite(encoderPhaseA, interruptMode);
    #endif
        delayMicroseconds(2000);
        
        uint8_t interruptionActivated = attach_interrupt(encoderPhaseA, interruptMode);
        if(interruptionActivated != -1) {
            Serial.println("Interruption configurated");
        } else {
            Serial.println("An error ocurried: MyEncoder::MyEncoder");
        }
    
}

EncoderInfo MyEncoder::_encoderInfo[CORE_NUM_INTERRUPT];
