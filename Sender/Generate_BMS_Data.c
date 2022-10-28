#include "Generate_BMS_Data.h"

/******* This Function will Generate battery parameter & process for display **************************/
int GenerateSensorData(sensorValue *sensorData)
{
    char buffer[MAX_NOOF_BMSDATA];
    if(sensorData!=NULL)
    {
        for(int i=0;i<MAX_VALUE;i++)
        {
        	sensorData->Temperature[i] = rand()%TEMP_RANGE;
        	sensorData->Soc[i] = rand()%SOC_RANGE;
        	sprintf(buffer,"%d,%d\n",sensorData->Temperature[i],sensorData->Soc[i]);
        }
        return DATA_OK;
    }
    return DATA_NOT_OK;
}
