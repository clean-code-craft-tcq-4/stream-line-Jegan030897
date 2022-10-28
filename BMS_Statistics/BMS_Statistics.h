#include "stdio.h"
#include "stdlib.h"
#include <string.h>

#define   MAX_RECEIVE_DATA   50


void BMSData_Statistics(char receive_BMSdata[], int datasize);
int movingAverage_of_Tempdata(int Tempdata[]);
int movingAverage_of_SOCdata(int SOCdata[]);
void sortBmsData(int Tempdata[], int SOCdata[]);
void sortGivenIndexPosition(int *Tempdata, int *SOCdata, int noOfElements, int received_position);
void convertString_To_Int(char receive_BMSdata[], int len, int Battery_Tempdata[], int Battery_SOCdata[]);
void convertBatteryTempData_To_Int(int receive_BMSdata, int Tempdata[], char BMSdata[], int BMSData_length);
void convertBatterySocData_To_Int(int receive_BMSdata, int SOCdata[], char BMSdata[], int BMSData_length);
void print_movingAvgData(int Avg_Of_Temp, int Avg_Of_Soc);
void print_Temp_MinMaxData(int minTempData, int maxTempData);
void print_Soc_MinMaxData(int minSocData, int maxSocData);
