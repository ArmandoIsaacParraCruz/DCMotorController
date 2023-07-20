#ifndef DCMotorController_h
#define DCMotorController_h
#include <Arduino.h>


enum class MotorDirection{Forward, Reverse};
enum class ControlMode{OpenLoop, ClosedLoop};

class DCMotorController
{
    private:
        int8_t _pinMotorA;
        int8_t _pinMotorB;
        int8_t _encoderPhaseA;
        int8_t _encoderPhaseB;
        MotorDirection _motorDirection;
        ControlMode _controlMode;
        float _pulsesPerRevolution;
        uint32_t _revolutionCounter;
        double _speed;

        enum Status{NotConfigured = -1, Configured = 1};
        void startMotorOpenLoop();

    public:
        DCMotorController(int8_t pinMotorA, int8_t pinMotorB = NotConfigured);
        void configureEncoderPins(int8_t encoderPhaseA, int8_t encoderPhaseB = NotConfigured);
        void configurePulserPerRevolution(float pulsesPerRevolution);
        void changeControlMode(ControlMode controlMode);
        void changeMotorDirection(MotorDirection motorDirection);
        void startMotor();
        void stopMotor();
        double getSpeed();
};

#endif