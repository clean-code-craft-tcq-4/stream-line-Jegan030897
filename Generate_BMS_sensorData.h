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

#define TRUE            1
#define FALSE           0

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

Parameter BatteryParameter; 

int BatteryTemp[MAX_DATA];
int BatterySoc[MAX_DATA];

int Temp_fileDirectory[2]; 
int SOC_fileDirectory[2]; 
int id;

void Generate_TempSensorData(int *batTemp, int Datasize);
void Generate_SOCData(int *socData, int Datasize);
int settingPipeforDataTransition();
void serialCom_TxData();


