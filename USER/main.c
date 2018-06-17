#include<bsp.h>

int main()
{
	u8 i = 0;
	bsp_Init();
	Clockwise_Rotate(3200);
	while(1)
	{		
		Angle = Get_Adc1_Average(ADC_Channel_5,5);
		printf("Angle=%u\r\n",Angle);
		
		i ++;
		
		if(i > 200)
		{
			led0 = ~led0;
			led1 = ~led1;
			i = 0;
		}
	}
}
