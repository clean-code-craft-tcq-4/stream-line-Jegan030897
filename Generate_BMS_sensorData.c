#include "stdio.h"
#include "Generate_BMS_sensorData.h"

int Generate_TempSensorData(int Datasize)
{
  for(int index = 0; index < Datasize; index++)
  {
		int randData = rand()%TEMP_RANGE;
		if(randData > MIN_TEMP && randData < MAX_TEMP)
		{
			BatteryTemp[index] = data;
		}
  }
}

int Generate_SOCData(int Datasize)
{
  for(int index = 0; index < Datasize; index++)
  {
		int randData = rand()%SOC_RANGE;
		if(randData > MIN_SOC && randData < MAX_SOC)
		{
			Soc[index] = data;
		}
  } 
}
