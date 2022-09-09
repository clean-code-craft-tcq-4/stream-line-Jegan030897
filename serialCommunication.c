#include "Generate_BMS_sensorData.h"

//int BatteryTemp[MAX_DATA];
//int BatterySoc[MAX_DATA];

int Temp_fileDirectory[2]; 
int SOC_fileDirectory[2]; 
int id;

Parameter BatteryParameter; 

int settingPipeforDataTransition(int *tempFD, int *socFD)
{
	id = fork();
	
	if((pipe(tempFD) == -1) && (pipe(socFD) == -1)) {
		printf("an error occured with opening the pipe \n");
		
		return Tx_NOT_ESTABLISHED;
	}
	return Tx_ESTABLISHED;
}

int serialCommunication(int *receiveBatTemp, int *receiveSocData)
{
    id = fork();
	int temp1[MAXNOOFBMSDATA], temp2[MAXNOOFBMSDATA];
	char dataArray[MAXNOOFBMSDATA];
	
	memset(dataArray, '\0', MAXNOOFBMSDATA);
    	for (int dataIndex = 0; dataIndex < MAX_DATA; dataIndex++) {
            char tempArray[MAX_DATA];
            temp1[dataIndex] = *(receiveBatTemp + dataIndex);
            temp2[dataIndex] = *(receiveSocData + dataIndex);
            memset(tempArray, '\0', sizeof(tempArray));
            sprintf(tempArray, "%d %d\n", temp1[dataIndex], temp2[dataIndex]);
            strcat(dataArray, tempArray);
        }
        
	if(id > FALSE)
	{
		  close(Temp_fileDirectory[0]);
		
		  write(Temp_fileDirectory[1], dataArray, strlen(dataArray));
		
		  close(Temp_fileDirectory[1]);
		  printf("sender: %s", dataArray);

	}
	else
	{
	    char receiveData[MAXNOOFBMSDATA], arr2[5];
	    memset(receiveData, '\0', sizeof(arrw));
	    close(Temp_fileDirectory[1]);
		
	    read(Temp_fileDirectory[0], receiveData, MAXNOOFBMSDATA);
		
	    close(Temp_fileDirectory[0]);
		
            printf("Receive Data: %s\n",receiveData);
	}
	return ACK;
}

int GenerateSensorData_Tx(int *BatteryTemp, int *BatterySoc, int tempDataLen, int socDataLen)
{
  int ComStatus, Tx_Ack;

  Generate_TempSensorData(BatteryTemp, tempDataLen);
  Generate_SOCData(BatterySoc, socDataLen);
  
  ComStatus = settingPipeforDataTransition(Temp_fileDirectory, SOC_fileDirectory);
  
  if(ComStatus == TRUE)
  {
    Tx_Ack = serialCom_TxData(BatteryTemp, BatterySoc);
  }
  return Tx_Ack;
}
