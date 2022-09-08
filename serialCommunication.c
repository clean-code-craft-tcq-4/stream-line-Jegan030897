#include "Generate_BMS_sensorData.h"

int BatteryTemp[MAX_DATA];
int BatterySoc[MAX_DATA];

int Temp_fileDirectory[2]; 
int SOC_fileDirectory[2]; 
int id;

Parameter BatteryParameter; 

int settingPipeforDataTransition(int *tempFD, int *socFD)
{
	id = fork();
	
	if((pipe(tempFD) == -1) && (pipe(socFD) == -1)) {
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
  int ComStatus;
    
  Generate_TempSensorData(BatteryTemp, MAX_DATA);
  Generate_SOCData(BatterySoc, MAX_DATA);
  
  ComStatus = settingPipeforDataTransition(Temp_fileDirectory, SOC_fileDirectory);
  
  if(ComStatus == TRUE)
  {
    serialCom_TxData();
  }
}
