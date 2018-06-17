#include<bsp.h>

int main()
{
	bsp_Init();
	while(1)
	{		
		printf("Angle=%u\r\n",Angle);
		led0 = ~led0;
		led1 = ~led1;
		delay_ms(1000);
	}
}
