#include "Generate_BMS_Data.h"
#include "../Receiver/Rx_BMS_Data.h"

int BMS_fileDirectory[2];
int id; 
int isDataSend_toPIPE = FALSE;

int config_PIPE(int *tempFD)
{
	
	if(pipe(tempFD) == -1) {
		printf("an error occured with opening the pipe \n");
		
		return FALSE;
	}
	return TRUE;
}

int writeToFileDirectory(sensorValue *sensorData)
{
  	char BMS_Data[MAX_NOOF_BMSDATA];
	
	id = fork();
	
	convertInt_To_String(BMS_Data, sensorData);
        
	if(id > FALSE)
	{
		sender(BMS_fileDirectory, BMS_Data, strlen(BMS_Data));
		return TRUE;
	}
	else
	{
		Receiver(BMS_fileDirectory);
	  	isDataSend_toPIPE = TRUE;
		return TRUE;
	}
	return FALSE;
}

void convertInt_To_String(char dataArray[], sensorValue *sensorData)
{
    memset(dataArray, '\0', MAX_NOOF_BMSDATA);
  	for (int dataIndex = 0; dataIndex < MAX_VALUE; dataIndex++) {
            char tempArray[LENGTH_OF_BMSDATA];
            memset(tempArray, '\0', sizeof(tempArray));
            sprintf(tempArray, "%d,%d\n", sensorData->Temperature[dataIndex], sensorData->Soc[dataIndex]);
            strcat(dataArray, tempArray);
  	}  
}

void sender(int file_directory[], char BMSdatas[], int length)
{
  	close(file_directory[0]);
		
	write(file_directory[1], BMSdatas, length);
		
	close(file_directory[1]);
	//printf("sender: %s",BMSdatas);
}

int Get_TransmitStatus()
{
	return isDataSend_toPIPE;
}

int Generate_Transmit_BMS_data(sensorValue *sensorData)
{
  int PipeStatus, Tx_Ack;
	
  GenerateSensorData(sensorData);
  
  PipeStatus = config_PIPE(BMS_fileDirectory);
  
  if(PipeStatus == TRUE)
  {
    Tx_Ack = writeToFileDirectory(sensorData);
  }
  return Tx_Ack;
}
