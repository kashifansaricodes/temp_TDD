#ifndef _TDD_ASSG_HPP_
#define _TDD_ASSG_HPP_

class PIDImpl
{
public:
    // Constructor stub
    PIDImpl(double dt, double max, double min, double Kp, double Kd, double Ki);
    ~PIDImpl();

    // Stub for the calculate method
    double calculate(double setpoint, double pv);

    // Declaration of computeTotal method
    double computeTotal(double Pout, double Iout, double Dout, double error);


private:



    double _dt;
    double _max;
    double _min;
    double _Kp;
    double _Kd;
    double _Ki;
    double _pre_error; // Previous error for derivative calculation
    double _integral;  // Integral of the error
};

class PID_Control {
public:
    PID_Control(double Kp, double Kd, double Ki, double dt, double integral, double pre_error);
    ~PID_Control();
    double output_value(double setpoint, double actual_value);
    PIDImpl* pimpl;  // Use PIDImpl* for your implementation
    
    
};

#endif
