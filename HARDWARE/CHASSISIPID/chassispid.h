#ifndef __CHASSISPID_H__
#define __CHASSISPID_H__

#include "sys.h"

int16_t ChassisCurrentLimit(int16_t current);

int16_t ChassisIncPID_1(int16_t current_velocity,int16_t target_velocity);
int16_t ChassisIncPID_2(int16_t current_velocity,int16_t target_velocity);
int16_t ChassisIncPID_3(int16_t current_velocity,int16_t target_velocity);
int16_t ChassisIncPID_4(int16_t current_velocity,int16_t target_velocity);

#endif

