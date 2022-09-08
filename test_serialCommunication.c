#include <stdio.h>
#include <assert.h>
#include "Generate_BMS_sensorData.h"


void TestCase_GenerateSensorData()
{
  int tempData[5] = {0xFF,0xFF,0xFF,0xFF,0xFF}, socData[5] = {0xFF,0xFF,0xFF,0xFF,0xFF};
  
  Generate_TempSensorData(tempData, 5);
  Generate_SOCData(socData, 5);
  
  for(int index = 0; index < 5; index++)
  {
    assert(tempData[index] != 0);
    assert(socData[index] != 0);
  }
}

void TestCase_Setting_PipeFor_TxData()
{
  int Temp_fileDirectory[2], SOC_fileDirectory[2]; 
  
  assert(settingPipeforDataTransition(Temp_fileDirectory, SOC_fileDirectory) == Tx_ESTABLISHED);
}

int main()
{
  TestCase_GenerateSensorData();
  TestCase_Setting_PipeFor_TxData();
}
