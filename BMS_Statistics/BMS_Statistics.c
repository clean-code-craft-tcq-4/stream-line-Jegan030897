#include "BMS_Statistics.h"

static int BMSdataIndex = 0;

void sortGivenIndexPosition(int *Tempdata, int *SOCdata, int noOfElements, int received_position) {
	int temp;
	
	for(int index = received_position+1 ; index < noOfElements; index++) {
	if(Tempdata[received_position] > Tempdata[index]) {
	temp = Tempdata[received_position];
     	Tempdata[received_position] = Tempdata[index];
     	Tempdata[index] = temp;
   	}
   	
   	if(SOCdata[received_position] > SOCdata[index]) {
	temp = SOCdata[received_position];
     	SOCdata[received_position] = SOCdata[index];
     	SOCdata[index] = temp;
   	}
 	}
}

void sortBmsData(int Tempdata[], int SOCdata[]) {
  	for(int index = 0; index < MAX_RECEIVE_DATA; index++) {
    	sortGivenIndexPosition(Tempdata, SOCdata,  MAX_RECEIVE_DATA, index); 
  	}
}

int movingAverage_of_Tempdata(int Tempdata[])
{
    int Avg_of_Temp = 0;
    
    for(int index = MAX_RECEIVE_DATA - 5; index < MAX_RECEIVE_DATA; index++)
    {
       Avg_of_Temp +=  Tempdata[index];
       
    }
    Avg_of_Temp /= 5;
    //printf("avg_1: %d ",Avg_of_Temp);
    return Avg_of_Temp;

}

int movingAverage_of_SOCdata(int SOCdata[])
{
    int Avg_of_Soc = 0;
    
    for(int index = MAX_RECEIVE_DATA - 5; index < MAX_RECEIVE_DATA; index++)
    {
       Avg_of_Soc +=  SOCdata[index];
    }
    Avg_of_Soc /= 5;
    //printf("avg_2: %d \n",Avg_of_Soc);
    return Avg_of_Soc;
    
}

void convertString_To_Int(char receive_BMSdata[], int len, int Battery_Tempdata[], int Battery_SOCdata[])
{
    int index;
    char BMSdata[4];
    
    memset(BMSdata, '\0', sizeof(BMSdata));
    
    for(index = 0; index <  len; index++)
    {
        if(receive_BMSdata[index] != '\0')
        {
           // printf("in: %d\n",index);
            if((receive_BMSdata[index] != ',') && (receive_BMSdata[index] != '\n'))
            {
                BMSdata[BMSdataIndex] = receive_BMSdata[index];
                //printf("%c",BMSdata[BMSdataIndex]);
                BMSdataIndex++;
            }
            convertBatteryTempData_To_Int(receive_BMSdata[index], Battery_Tempdata, BMSdata, sizeof(BMSdata));
		
	    convertBatterySocData_To_Int(receive_BMSdata[index], Battery_SOCdata, BMSdata, sizeof(BMSdata));
        }
        else
        {
            break;
        }
    }
}

void convertBatteryTempData_To_Int(int receive_BMSdata, int Tempdata[], char BMSdata[], int BMSData_length)
{
    static int BMSTempIndex = 0;
    
    if((receive_BMSdata == ',') && (receive_BMSdata != '\n'))
    {
       Tempdata[BMSTempIndex] = atoi(BMSdata);
       //printf("Temp: %d \n",Tempdata[BMSTempIndex]);
       ++BMSTempIndex;
       BMSdataIndex = 0;
       memset(BMSdata, '\0', BMSData_length);
    }
}

void convertBatterySocData_To_Int(int receive_BMSdata, int SOCdata[], char BMSdata[], int BMSData_length)
{
    static int BMSSocIndex = 0;
    
    if((receive_BMSdata == '\n') && (receive_BMSdata != ','))
    {
       SOCdata[BMSSocIndex] = atoi(BMSdata);
       //printf("SOC: %d \n",SOCdata[BMSSocIndex]);
       ++BMSSocIndex;
       BMSdataIndex = 0;
       memset(BMSdata, '\0', BMSData_length);
    }
}

void print_movingAvgData(int Avg_Of_Temp, int Avg_Of_Soc)
{
	printf("Avg of Temp: %d Soc: %d\n",Avg_Of_Temp,Avg_Of_Soc);
}

void print_Temp_MinMaxData(int minTempData, int maxTempData)
{
	printf("Temp min value: %d max value: %d\n", minTempData, maxTempData);
}

void print_Soc_MinMaxData(int minSocData, int maxSocData)
{
	printf("Soc min value: %d max value: %d\n", minSocData, maxSocData);
}

void BMSData_Statistics(char receive_BMSdata[], int datasize)
{
    int BatteryTempdata[50];
    int BatterySOCdata[50];
    int AvgofTemp = 0, AvgofSOC = 0;
	
    convertString_To_Int(receive_BMSdata,datasize,BatteryTempdata,BatterySOCdata);
	
    AvgofTemp = movingAverage_of_Tempdata(BatteryTempdata);
    AvgofSOC = movingAverage_of_SOCdata(BatterySOCdata);
	
    print_movingAvgData(AvgofTemp, AvgofSOC);
	
    sortBmsData(BatteryTempdata, BatterySOCdata);
	
    print_Temp_MinMaxData(BatteryTempdata[0],BatteryTempdata[MAX_RECEIVE_DATA-1]);
    print_Soc_MinMaxData(BatterySOCdata[0],BatterySOCdata[MAX_RECEIVE_DATA-1]);
	
}
