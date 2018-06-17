#include "bsp.h"

int Deviation_Angle;

void ControlLoop(void)
{
//	//左右摇摆模式
//	if(Sway_From_Side_To_Side == 1)
//	{
//		if(Angle < 200)
//		{
//			Clockwise_Rotate(1000);
//		}
//		
//		else if(Angle > 3000)
//		{
//			Counterclockwise_Rotate(1000);
//		}
//	}
//	
//	//圆周模式
//	if(Circling_Motion = 1)
//	{
//		Clockwise_Rotate(6000);
//	}
//	
//	//倒立保持模式
//	if(Stay_Upside_Down = 1)
//	{
//		Clockwise_Rotate(6000);
//	}



	//解算误差
	if((Angle - 394 > 0) && (Angle - 394 < 2121))
	{
		Deviation_Angle = Angle - 394;
	}
	else if(4096 + 394 - Angle > 4096)
	{
		Deviation_Angle = Angle - 394;
	}
	else
	{
		Deviation_Angle = Angle - 4096 - 394;
	}
	
	
	
	

	
	
}
