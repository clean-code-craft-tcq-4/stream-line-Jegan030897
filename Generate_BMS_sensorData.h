#include "stdio.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_DATA        50
#define TEMP_RANGE      45
#define SOC_RANGE       80
#define MIN_TEMP	      0
#define MAX_TEMP	      45
#define MIN_SOC		      20
#define MAX_SOC		      80

#define MAX_SENSORCNT   2
#define BMSDATA         8
#define MAXNOOFBMSDATA  (MAX_SENSORCNT * MAX_DATA * BMSDATA)

#define TRUE            1
#define FALSE           0

#define ACK             1
#define NOT_ACK         0

#define Tx_ESTABLISHED      1
#define Tx_NOT_ESTABLISHED  0

typedef enum 
{
  FILE_READ    = 0,
  FILE_WRITE   = 1
}fileDirectory;

typedef enum 
{
  BATTERY_TEMPERATURE    = 0,
  BATTERY_SOC            = 1
}Parameter;

//extern int BatteryTemp[MAX_DATA];
//extern int BatterySoc[MAX_DATA];

extern int Temp_fileDirectory[2]; 
extern int SOC_fileDirectory[2]; 
extern int id;

void Generate_TempSensorData(int *batTemp, int Datasize);
void Generate_SOCData(int *socData, int Datasize);
int settingPipeforDataTransition(int *tempFD, int *socFD);
int serialCommunication(int *receiveBatTemp, int *receiveSocData);
int GenerateSensorData_Tx(int *BatteryTemp, int *BatterySoc, int tempDataLen, int socDataLen);
void serialCom_TxData(int dataArray[]);
void serialCom_RxData();


