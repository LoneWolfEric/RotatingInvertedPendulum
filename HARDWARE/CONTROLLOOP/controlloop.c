#include "bsp.h"

void ControlLoop(void)
{
	Angle = Get_Adc1_Average(ADC_Channel_5,1);
//	Angle = Get_Adc1_Average(ADC_Channel_5,5);
//	TIM_SetCompare2(TIM3,0);
}
