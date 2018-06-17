#include "bsp.h"


const float Kp = 1.40,Ki = 0.07,Kd = 0;
//³õÊ¼»¯
Inc_PID ChassisPID_1 = {Kp,Ki,Kd,0,0,0,0};
Inc_PID ChassisPID_2 = {Kp,Ki,Kd,0,0,0,0};
Inc_PID ChassisPID_3 = {Kp,Ki,Kd,0,0,0,0};
Inc_PID ChassisPID_4 = {Kp,Ki,Kd,0,0,0,0};


int16_t ChassisIncPID_1(int16_t current_velocity,int16_t target_velocity)
{
	ChassisPID_1.error_last_last = ChassisPID_1.error_last;
	ChassisPID_1.error_last = ChassisPID_1.error_now;
	ChassisPID_1.error_now = target_velocity - current_velocity;
	
	ChassisPID_1.pid_out =  ChassisPID_1.Kp * (ChassisPID_1.error_now - ChassisPID_1.error_last)
						  + ChassisPID_1.Ki * ChassisPID_1.error_now
						  + ChassisPID_1.Kd *( ChassisPID_1.error_now - 2 * ChassisPID_1.error_last + ChassisPID_1.error_last_last);

	ChassisPID_1.pid_out = ChassisPID_1.pid_out > MaxInc ? MaxInc : (ChassisPID_1.pid_out < -MaxInc ? -MaxInc : ChassisPID_1.pid_out);
	
	return ChassisPID_1.pid_out;
}

int16_t ChassisIncPID_2(int16_t current_velocity,int16_t target_velocity)
{
	ChassisPID_2.error_last_last = ChassisPID_2.error_last;
	ChassisPID_2.error_last = ChassisPID_2.error_now;
	ChassisPID_2.error_now = target_velocity - current_velocity;
	
	ChassisPID_2.pid_out =  ChassisPID_2.Kp * (ChassisPID_2.error_now - ChassisPID_2.error_last)
						  + ChassisPID_2.Ki * ChassisPID_2.error_now
						  + ChassisPID_2.Kd *( ChassisPID_2.error_now - 2 * ChassisPID_2.error_last + ChassisPID_2.error_last_last);

	ChassisPID_2.pid_out = ChassisPID_2.pid_out > MaxInc ? MaxInc : (ChassisPID_2.pid_out < -MaxInc ? -MaxInc : ChassisPID_2.pid_out);
	
	return ChassisPID_2.pid_out;
}

int16_t ChassisIncPID_3(int16_t current_velocity,int16_t target_velocity)
{
	ChassisPID_3.error_last_last = ChassisPID_3.error_last;
	ChassisPID_3.error_last = ChassisPID_3.error_now;
	ChassisPID_3.error_now = target_velocity - current_velocity;
	
	ChassisPID_3.pid_out =  ChassisPID_3.Kp * (ChassisPID_3.error_now - ChassisPID_3.error_last)
						  + ChassisPID_3.Ki * ChassisPID_3.error_now
						  + ChassisPID_3.Kd *( ChassisPID_3.error_now - 2 * ChassisPID_3.error_last + ChassisPID_3.error_last_last);

	ChassisPID_3.pid_out = ChassisPID_3.pid_out > MaxInc ? MaxInc : (ChassisPID_3.pid_out < -MaxInc ? -MaxInc : ChassisPID_3.pid_out);
	
	return ChassisPID_3.pid_out;
}

int16_t ChassisIncPID_4(int16_t current_velocity,int16_t target_velocity)
{
	ChassisPID_4.error_last_last = ChassisPID_4.error_last;
	ChassisPID_4.error_last = ChassisPID_4.error_now;
	ChassisPID_4.error_now = target_velocity - current_velocity;
	
	ChassisPID_4.pid_out =  ChassisPID_4.Kp * (ChassisPID_4.error_now - ChassisPID_4.error_last)
						  + ChassisPID_4.Ki * ChassisPID_4.error_now
						  + ChassisPID_4.Kd *( ChassisPID_4.error_now - 2 * ChassisPID_4.error_last + ChassisPID_4.error_last_last);

	ChassisPID_4.pid_out = ChassisPID_4.pid_out > MaxInc ? MaxInc : (ChassisPID_4.pid_out < -MaxInc ? -MaxInc : ChassisPID_4.pid_out);
	
	return ChassisPID_4.pid_out;
}

int16_t ChassisCurrentLimit(int16_t current)
{
	return current > MaxCurrent ? MaxCurrent : (current < -MaxCurrent ? -MaxCurrent : current);
}

