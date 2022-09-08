#include "stdio.h"
#include "stdlib.h"
#include "Generate_BMS_sensorData.h"

void Generate_TempSensorData(int Datasize)
{
  for(int index = 0; index < Datasize; index++)
  {
		int randData = rand()%TEMP_RANGE;
		if(randData > MIN_TEMP && randData < MAX_TEMP)
		{
			BatteryTemp[index] = randData;
		}
  }
}

void Generate_SOCData(int Datasize)
{
  for(int index = 0; index < Datasize; index++)
  {
		int randData = rand()%SOC_RANGE;
		if(randData > MIN_SOC && randData < MAX_SOC)
		{
			Soc[index] = randData;
		}
  } 
}

int main()
{
	Generate_TempSensorData(MAX_DATA);
	Generate_SOCData(MAX_DATA);
}
