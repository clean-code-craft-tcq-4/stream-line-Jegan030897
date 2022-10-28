#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define TRUE 	    1
#define FALSE       0

#define MAX_VALUE   50
#define TEMP_RANGE  50
#define SOC_RANGE   50
#define CHAR_MAX    256
#define DATA_OK     0 
#define DATA_NOT_OK 1

#define MAXSENSORCNT   2
#define LENGTH_OF_BMSDATA         8
#define MAX_NOOF_BMSDATA  (MAXSENSORCNT * MAX_VALUE * LENGTH_OF_BMSDATA)

typedef struct {
	int Temperature[MAX_VALUE];
	int Soc[MAX_VALUE];
} sensorValue;

extern int BMS_fileDirectory[2];
extern int id; 

int GenerateSensorData(sensorValue *sensorData);
void DisplayToConsole(char* buffer);
int config_PIPE(int *tempFD);
int writeToFileDirectory(sensorValue *sensorData);
void convertInt_To_String(char dataArray[], sensorValue *sensorData);
void sender(int file_directory[], char senderdata[], int length);
int Generate_Transmit_BMS_data(sensorValue *sensorData);
int Get_TransmitStatus();

