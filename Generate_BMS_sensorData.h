#include "stdio.h"

#define MAX_DATA        50
#define TEMP_RANGE      45
#define SOC_RANGE       80
#define MIN_TEMP	      0
#define MAX_TEMP	      45
#define MIN_SOC		      20
#define MAX_SOC		      80

int BatteryTemp[MAX_DATA];
int Soc[MAX_DATA];

void Generate_TempSensorData(int Datasize);
void Generate_SOCData(int Datasize);  
