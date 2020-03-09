#include "PID.h"
#include <iostream>

using namespace std;
/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}


void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */

   Kp = Kp_;
   Ki = Ki_;
   Kd = Kd_;

   p_error = 0;
   d_error = 0;
   i_error = 0;

   totalError = 0;

   stepSize = 0.3;

   It = 1;

}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */

  if (It < 2){
    p_error = cte;
    It += 1;
    return;
  }
  d_error = cte - p_error;
  i_error += cte;
  p_error = cte;
  It += 1;
}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */

  totalError += p_error;
  return totalError;  // TODO: Add your total error calc here!
}