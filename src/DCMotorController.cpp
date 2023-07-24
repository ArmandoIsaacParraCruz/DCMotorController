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
    _myEncoder = nullptr;
}


MyEncoder* DCMotorController::instanceEncoder(int8_t& encoderPhaseA, int8_t& encoderPhaseB, int8_t& interruptMode)
{
    MyEncoder* encoderInstance = new MyEncoder{encoderPhaseA, encoderPhaseB};
    return encoderInstance;
}

bool DCMotorController::setEncoderPins(int8_t encoderPhaseA, int8_t encoderPhaseB, int8_t interruptMode)
{
    if(_myEncoder == nullptr) {
        _myEncoder = instanceEncoder(encoderPhaseA, encoderPhaseB, interruptMode);
        Serial.println("An encoder was configurated");
        return true;
    } else {
        Serial.println("An error ocurried: DCMotorController::setEncoderPins");
        return false;
    }
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



void DCMotorController::stopMotor()
{
    digitalWrite(_pinMotorA, LOW);
    digitalWrite(_pinMotorB, LOW);
}

double DCMotorController::getSpeed()
{
    return _speed;
}
