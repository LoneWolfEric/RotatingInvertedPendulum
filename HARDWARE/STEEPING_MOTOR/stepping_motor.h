#ifndef _PWM_H
#define _PWM_H
#include<sys.h>

#define DIR PCout(8)
#define ENA PCout(6)


void TIM3_PWM_Init(u16 arr,u16 psc);

void Stepping_motor_init(void);
void Clockwise_Rotate(int step_num);
void Counterclockwise_Rotate(int step_num);




#endif
