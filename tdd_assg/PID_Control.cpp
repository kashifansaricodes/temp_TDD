/**
 * @file PID_Control.cpp
 * @brief Implementation file for the PID control class.
 *
 * Part 1:
 * Driver: Kashif Ansari
 * Navigator: Piyush Goenka
 *
 * Part 2:
 * Driver: Kshitij Aggarwal
 * Navigator: Bhavana Rao
 */

#ifndef _PID_SOURCE_
#define _PID_SOURCE_

#include "../include/PID_Control.hpp"

#include <iostream>

// using namespace std;

// Constructor for PID_Control, initializing the implementation
PID_Control::PID_Control(double Kp, double Kd, double Ki, double dt,
                         double integral, double pre_error) {
  pimpl = new PIDImpl(dt, 100, -100, Kp, Kd, Ki);  // Dummy max/min values
}

// Stub for the calculate method, returns a hardcoded value
double PID_Control::output_value(double setpoint, double actual_value) {
  // Return a hardcoded value (stub)
  return pimpl->calculate(setpoint,
                          actual_value);  // Will return hardcoded value
}

// Destructor to clean up the implementation
PID_Control::~PID_Control() {
  delete pimpl;  // Free the memory for pimpl
}

// Implementation constructor (stub)
PIDImpl::PIDImpl(double dt, double max, double min, double Kp, double Kd,
                 double Ki)
    : _dt(dt),
      _max(max),
      _min(min),
      _Kp(Kp),
      _Kd(Kd),
      _Ki(Ki),
      _pre_error(0),
      _integral(0) {
  // No initialization logic, just a stub
}

// Method to calculate the total final values
double PIDImpl::computeTotal(double Pout, double Iout, double Dout,
                             double error) {
  // Calculates the final total output fromPout and Iout
  double output = Pout + Iout + Dout;

  // Trims the output if overflows beyond the maximum/minimum values
  if (output > _max)
    output = _max;
  else if (output < _min)
    output = _min;

  // Update the previous error value
  _pre_error = error;

  return output;
}

double PIDImpl::calculate(double setpoint, double pv) {
  // Calculate the error value
  double error = setpoint - pv;

  // Proportional gain
  double Pout = _Kp * error;

  // Integral gain
  _integral += error * _dt;
  double Iout = _Ki * _integral;

  // Derivative gain
  double derivative = (error - _pre_error) / _dt;
  double Dout = _Kd * derivative;

  // Calculate and return total output and handle restrictions
  return computeTotal(Pout, Iout, Dout, error);
}

// Destructor for PIDImpl (stub)
PIDImpl::~PIDImpl() {
  // No cleanup needed for stubs
}

#endif