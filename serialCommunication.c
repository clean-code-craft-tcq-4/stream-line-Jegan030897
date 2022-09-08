#include "Generate_BMS_sensorData.h"


int settingPipeforDataTransition()
{
	id = fork();
	
	if((pipe(Temp_fileDirectory) == -1) && (pipe(SOC_fileDirectory) == -1)) {
		printf("an error occured with opening the pipe \n");
		return FALSE;
	}
	return TRUE;
}

void serialCom_TxData()
{
	int tempData[MAX_DATA], socData[MAX_DATA];
	
	for(int index = 0; index < MAX_DATA; index++)
	{
	    tempData[index] = BatteryTemp[index];
	    socData[index] = BatterySoc[index];
	}
	
	if(id == 0)
	{
		  close(Temp_fileDirectory[FILE_READ]);
		  close(SOC_fileDirectory[FILE_READ]);
		
		  write(Temp_fileDirectory[FILE_WRITE], tempData, MAX_DATA);
		  write(SOC_fileDirectory[FILE_WRITE], socData, MAX_DATA);
		
		  close(Temp_fileDirectory[FILE_WRITE]);
		  close(SOC_fileDirectory[FILE_WRITE]);
	}
}

int main()
{
  int tempComStatus, socComStatus;
    
  Generate_TempSensorData(BatteryTemp, MAX_DATA);
  Generate_SOCData(BatterySoc, MAX_DATA);
  
  tempComStatus = settingPipeforDataTransition();
  socComStatus = settingPipeforDataTransition();
  
  if((tempComStatus == TRUE) && (socComStatus == TRUE))
  {
    serialCom_TxData();
  }
}
