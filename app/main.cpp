/**
 * @file PID_Control.hpp
 * @brief Header file for the PID control implementation.
 *
 * Driver: Kashif Ansari
 * Navigator: Piyush Goenka
 */

#include <stdio.h>

#include "../tdd_assg/PID_Control.cpp"

int main() {
  // Instantiate the PID controller with dummy values
  PID_Control pid(0.1, 0.5, 0.01, 0.1, 0,
                  0);  // Example values for Kp, Kd, Ki, dt, integral, pre_error

  double setpoint = 11.0;     // Example setpoint value
  double actual_value = 7.0;  // Example actual value

  // Calculate the control output once
  double control_output = pid.output_value(setpoint, actual_value);

  // Print the result
  printf("Setpoint: %7.3f Actual Value: %7.3f Control Output: %7.3f\n",
         setpoint, actual_value, control_output);

  return 0;
}
