#include<adc.h>
#include<delay.h>	
#include<bsp.h>

u16 Angle;

void Adc_Init(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	ADC_CommonInitTypeDef ADC_CommonInitStructure;
	ADC_InitTypeDef ADC_InitStructure;
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);									//ʹ��GPIOAʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE); 									//ʹ��ADC1ʱ��
	//RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC2, ENABLE); 									//ʹ��ADC2ʱ��

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;
//	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
//	
//	
//	GPIO_Init(GPIOA,&GPIO_InitStructure);													//����gpioA4,5Ϊģ���ź�����˿�
	
	ADC_DeInit();																			//adc��λ��Ϊ�µ�������׼��
	
	ADC_CommonInitStructure.ADC_DMAAccessMode=ADC_DMAAccessMode_Disabled;
	ADC_CommonInitStructure.ADC_Mode=ADC_Mode_Independent;
	ADC_CommonInitStructure.ADC_Prescaler=ADC_Prescaler_Div4;
	ADC_CommonInitStructure.ADC_TwoSamplingDelay=ADC_TwoSamplingDelay_5Cycles;
	
	ADC_CommonInit(&ADC_CommonInitStructure);												//��ʼ��adcͨ������
	
	ADC_InitStructure.ADC_ContinuousConvMode=DISABLE;
	ADC_InitStructure.ADC_DataAlign=ADC_DataAlign_Right;
	ADC_InitStructure.ADC_ExternalTrigConvEdge=ADC_ExternalTrigConvEdge_None;	//��ֹ�ⲿ������ֻ���������
	ADC_InitStructure.ADC_NbrOfConversion=1;
	ADC_InitStructure.ADC_Resolution=ADC_Resolution_12b;
	ADC_InitStructure.ADC_ScanConvMode=DISABLE;
	
	ADC_Init(ADC1,&ADC_InitStructure);														//��ʼ��adc1
	//ADC_Init(ADC2,&ADC_InitStructure);
	
	ADC_Cmd(ADC1, ENABLE);																	//����adc1
	//ADC_Cmd(ADC2, ENABLE);		
}



u16  Get_Adc1(u8 ch)
{
	ADC_RegularChannelConfig(ADC1,ch,1,ADC_SampleTime_480Cycles);					//����adc1ͨ��ch
	ADC_SoftwareStartConv(ADC1);													//�������adc1��ʼ����
	
	while(!ADC_GetFlagStatus(ADC1,ADC_FLAG_EOC))									//�������
		;
	
	return ADC_GetConversionValue(ADC1);											//���صõ���ֵ
}

u16  Get_Adc2(u8 ch)
{
	ADC_RegularChannelConfig(ADC2,ch,1,ADC_SampleTime_480Cycles);					//����adc2ͨ��ch
	ADC_SoftwareStartConv(ADC2);													//�������adc2��ʼ����
	
	while(!ADC_GetFlagStatus(ADC2,ADC_FLAG_EOC))									//�������
		;
	
	return ADC_GetConversionValue(ADC2);											//���صõ���ֵ
}



u16 Get_Adc1_Average(u8 ch,u8 times)
{
	u32 temp_val=0;
	u8 t;
	for(t=0;t<times;t++)
	{
		temp_val+=Get_Adc1(ch);
		delay_us(100);
	}
	return temp_val/times;
}

u16 Get_Adc2_Average(u8 ch,u8 times)
{
	u32 temp_val=0;
	u8 t;
	for(t=0;t<times;t++)
	{
		temp_val+=Get_Adc2(ch);
		delay_ms(5);
	}
	return temp_val/times;
}


