#include<bsp.h>


void TIM3_PWM_Init(u16 arr,u16 psc)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef TIM_OCInitStructure;

	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC,ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;           
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;        
	GPIO_Init(GPIOC,&GPIO_InitStructure);             			 	    	 //��ʼ��PC7
	
	GPIO_PinAFConfig(GPIOC,GPIO_PinSource7,GPIO_AF_TIM3);		    	 //�˿ڸ���ӳ��C7Ϊ��ʱ��3
	
	TIM_TimeBaseStructure.TIM_Prescaler=psc;  
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; 
	TIM_TimeBaseStructure.TIM_Period=arr;   
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1; 
	
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseStructure);									//��ʼ����ʱ��3
	
	TIM_OCInitStructure.TIM_OCMode=TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OCPolarity=TIM_OCPolarity_Low;
	TIM_OCInitStructure.TIM_OutputState=TIM_OutputState_Enable;

	TIM_OC2Init(TIM3,&TIM_OCInitStructure);												//����OC2ͨ���ͼ�ʱ��3����pwm�Ƚ�ģʽ
	
	TIM_OC2PreloadConfig(TIM3,TIM_OCPreload_Enable);								//OC2ͨ����Ԥװ�ؼĴ�������--���˲������п��ޣ�
	
	TIM_ARRPreloadConfig(TIM3,ENABLE);															//��ʱ��3��Ԥװ��ʹ��λ(ARPE)����--���˲������п��ޣ�
	
	TIM_Cmd(TIM3, ENABLE);  																				//ʹ��TIM3
}

void Stepping_motor_init(void)
{
	
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC,ENABLE);

	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType=GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd=GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOC,&GPIO_InitStructure);
	
	GPIO_SetBits(GPIOC,GPIO_Pin_6);
	//C6

	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_8;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType=GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd=GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOC,&GPIO_InitStructure);
	
	GPIO_SetBits(GPIOC,GPIO_Pin_8);
	//C8
	
	TIM3_PWM_Init(20, 84 - 1);
	ENA = 0;
	DIR = 1;
}


void Clockwise_Rotate(u8 step_num)
{
	u32 delay_time = 0;
	ENA = 0;
	DIR = 1;
	delay_us(10);
	TIM_SetCompare2(TIM3,10);
	delay_time = step_num * 8; 
	delay_us(delay_time);
	ENA = 1;
}

void Counterclockwise_Rotate(u8 step_num)
{
	u32 delay_time = 0;
	ENA = 0;
	DIR = 0;
	delay_us(10);
	TIM_SetCompare2(TIM3,10);
	delay_time = step_num *  8;
	delay_us(delay_time);
	ENA = 1;
}


