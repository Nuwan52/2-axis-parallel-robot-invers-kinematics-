#pragma once
#include <Arduino.h>

void InversKinamatics(float x, float y, int L1 , int L2 , int L3 , int L4 , int D, int* teata_01_p , int* teata_02_p)
{
  float a1 = 2 * x * L4;
  float b1 = -2 * y * L4;

  float a2 = 2 * (D - x) * L1;
  float b2 = -2 * y * L1;

  float c1 = pow(L3, 2) - pow(L4, 2) - (pow(x, 2) + pow(y, 2));
  float c2 = pow(L2, 2) - pow(L1, 2) - pow(y, 2) - pow((D - x), 2);

  float alfa_1 = asin(a1 / sqrt(pow(a1, 2) + pow(b1, 2)));
  float alfa_2 = asin(a2 / sqrt(pow(a2, 2) + pow(b2, 2)));

  float rhs1 = c1 / sqrt(pow(a1, 2) + pow(b1, 2));
  float sin_inverse1 = asin(rhs1);

  float theta_1 = sin_inverse1 - alfa_1;
  float theta_1_degrees = degrees(theta_1);

  float rhs2 = c2 / sqrt(pow(a2, 2) + pow(b2, 2));
  float sin_inverse2 = asin(rhs2);

  float theta_2 = sin_inverse2 - alfa_2;
  float theta_2_degrees = degrees(theta_2);

  *teata_01_p = theta_1_degrees * -1;
  *teata_02_p = theta_2_degrees;
}