#include <stdio.h>
#include <assert.h>
#include "Generate_BMS_sensorData.h"

int tempData[5] = {0xFF,0xFF,0xFF,0xFF,0xFF}, socData[5] = {0xFF,0xFF,0xFF,0xFF,0xFF};

void TestCase_GenerateSensorData()
{
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

void TestCase_SerialCom_TxData()
{
  assert((serialCom_TxData(tempData, socData, 5, 5) == ACK);
}

int main()
{
  TestCase_GenerateSensorData();
  TestCase_Setting_PipeFor_TxData();
  TestCase_SerialCom_TxData();
}
