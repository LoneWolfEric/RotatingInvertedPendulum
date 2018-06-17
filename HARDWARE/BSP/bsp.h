#ifndef	__BSP_H__
#define	__BSP_H__

#include "stm32f4xx.h"
#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "math.h"
#include "stdio.h"
#include "led.h"
#include "beep.h"
#include "key.h"
#include "timer.h"
#include "adc.h"
#include "usart2.h"
#include "controlloop.h"
#include "iwdg.h"
#include "stepping_motor.h"
	
#define BEEP 						PCout(2) 


typedef struct
{
	float Kp;				//比例
	float Ki;				//积分
	float Kd;				//微分
	float error_now;		//本次误差
	float error_last;		//上次误差
	float error_last_last;	//上上次误差
	int16_t pid_out;		//PID输出
}Inc_PID;					//增量式PID



extern u16 Angle;
extern int Deviation_Angle;

extern Inc_PID ChassisPID_1;
extern Inc_PID ChassisPID_2;
extern Inc_PID ChassisPID_3;
extern Inc_PID ChassisPID_4;


void bsp_Init(void);

#endif
