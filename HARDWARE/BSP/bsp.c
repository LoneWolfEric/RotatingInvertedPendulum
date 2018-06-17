#include "bsp.h"

void bsp_Init(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置系统中断优先级分组2
	delay_init(168);
	uart_init(115200);
	uart2_init(115200);
	Adc_Init();
	LED_Init();
	Stepping_motor_init();
	TIM14_Init();
	//IWDG_Init(3,300);
	//KEY_Init();
}
