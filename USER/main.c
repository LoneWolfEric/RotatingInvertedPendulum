#include<bsp.h>

int main()
{
	u8 i = 0;
	bsp_Init();
	
	Clockwise_Rotate(3200);
	delay_ms(2000);
	//Clockwise_Rotate(3200);
	while(1)
	{		
		//Clockwise_Rotate(3200);
		Angle = Get_Adc1_Average(ADC_Channel_5,5);
		//printf("Angle=%u\r\n",Angle);
		printf("Deviation_Angle=%d\r\n",Deviation_Angle);
		
		i ++;
		
		if(i > 40)
		{
			led0 = ~led0;
			led1 = ~led1;
			i = 0;
		}
	}
}
