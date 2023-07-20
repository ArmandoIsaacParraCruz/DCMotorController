#include "DCMotorController.h"
DCMotorController::DCMotorController(int8_t pinMotorA, int8_t pinMotorB)
{
    _pinMotorA = pinMotorA;
    pinMode(_pinMotorA, OUTPUT);
    if(pinMotorB != NotConfigured) {
        _pinMotorB = pinMotorB;
        pinMode(_pinMotorB, OUTPUT);
    }
    _encoderPhaseA = NotConfigured;
    _encoderPhaseB = NotConfigured;
    _motorDirection = MotorDirection::Forward;
    _controlMode = ControlMode::OpenLoop;
    _pulsesPerRevolution = NotConfigured;
}

void DCMotorController::configureEncoderPins(int8_t encoderPhaseA, int8_t encoderPhaseB)
{

}

void DCMotorController::configurePulserPerRevolution(float pulsesPerRevolution)
{
    _pulsesPerRevolution = pulsesPerRevolution;
}

void DCMotorController::changeControlMode(ControlMode controlMode)
{
    _controlMode = controlMode;
}

void DCMotorController::changeMotorDirection(MotorDirection motorDirection)
{
    _motorDirection = motorDirection;
}

void DCMotorController::startMotor()
{
    if(_controlMode == ControlMode::ClosedLoop) {

    } else{
        startMotorOpenLoop();
    }
}

void DCMotorController::startMotorOpenLoop()
{
    if(_motorDirection == MotorDirection::Forward) {
        digitalWrite(_pinMotorA, HIGH);
        digitalWrite(_pinMotorB, LOW);
    } else {
        digitalWrite(_pinMotorA, LOW);
        digitalWrite(_pinMotorB, HIGH);
    }
}

void DCMotorController::stopMotor()
{
    digitalWrite(_pinMotorA, LOW);
    digitalWrite(_pinMotorB, LOW);
}

double DCMotorController::getSpeed()
{
    return _speed;
}
