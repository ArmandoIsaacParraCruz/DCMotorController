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
        uint32_t _pulsesCounter;
        double _speed;
        double _Kp;
        double _Ki;
        double _Kd;
        double _input;
        double _output;
        double _minOutput;
        double _maxOutput;

        static const bool _OFF = false; 
        static const bool _ON = true;
        static const int8_t _UNDEFINED = -1;

        bool _statusOutputLimits;
        bool _statusPWMControl;
        bool _statusPIDAutoupdate;

        void startMotorOpenLoop();

        static IRAM_ATTR void addPulse();

    public:
        DCMotorController(int8_t pinMotorA, int8_t pinMotorB = _UNDEFINED);
        void setEncoderPins(int8_t encoderPhaseA, int8_t encoderPhaseB = _UNDEFINED);
        void setPulserPerRevolution(float pulsesPerRevolution);
        void changeControlMode(ControlMode controlMode);
        void changeMotorDirection(MotorDirection motorDirection);
        void setPIDConstants(double Kp, double Ki, double Kd);
        void enablePWMControl();
        void setOutputLimits(double minOutput, double maxOutput);
        void setSampleTime(double sampleTime);
        void enablePIDAutoUpdate();
        void disablePIDAutoUpdate();
        void computePID();
        void startMotor();
        void stopMotor();
        double getSpeed();
};

#endif