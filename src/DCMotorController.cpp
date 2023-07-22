#include "DCMotorController.h"
DCMotorController::DCMotorController(int8_t pinMotorA, int8_t pinMotorB)
{
    _pinMotorA = pinMotorA;
    pinMode(_pinMotorA, OUTPUT);
    if(pinMotorB != _UNDEFINED) {
        _pinMotorB = pinMotorB;
        pinMode(_pinMotorB, OUTPUT);
    }
    _encoderPhaseA = _UNDEFINED;
    _encoderPhaseB = _UNDEFINED;
    _motorDirection = MotorDirection::Forward;
    _controlMode = ControlMode::OpenLoop;
    _pulsesPerRevolution = _UNDEFINED;
    _statusOutputLimits = _OFF;
    _statusPWMControl = _OFF;
    _statusPIDAutoupdate = _OFF;
}

void DCMotorController::setEncoderPins(int8_t encoderPhaseA, int8_t encoderPhaseB)
{
    pinMode(encoderPhaseA, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(encoderPhaseA), addPulse, RISING);
}

void DCMotorController::setPulserPerRevolution(float pulsesPerRevolution)
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

void DCMotorController::enablePWMControl()
{
}

void DCMotorController::setOutputLimits(double minOutput, double maxOutput)
{
}

void DCMotorController::setSampleTime(double sampleTime)
{
}

void DCMotorController::enablePIDAutoUpdate()
{
}

void DCMotorController::disablePIDAutoUpdate()
{
}

void DCMotorController::computePID()
{
}

void DCMotorController::setPIDConstants(double Kp, double Ki, double Kd)
{
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

void IRAM_ATTR DCMotorController::addPulse()
{
    
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
