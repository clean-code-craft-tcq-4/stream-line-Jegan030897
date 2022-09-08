#include "stdio.h"
#include "stdlib.h"
#include "Generate_BMS_sensorData.h"

void Generate_TempSensorData(int *batTemp, int Datasize)
{
  for(int index = 0; index < Datasize; index++)
  {
	int randData = rand()%TEMP_RANGE;
	if(randData > MIN_TEMP && randData < MAX_TEMP)
	{
		*(batTemp+index) = randData;
	}
  }
}

void Generate_SOCData(int *socData, int Datasize)
{
  for(int index = 0; index < Datasize; index++)
  {
	int randData = rand()%SOC_RANGE;
	if(randData > MIN_SOC && randData < MAX_SOC)
	{
		*(socData+index) = randData;
	}
  } 
}

