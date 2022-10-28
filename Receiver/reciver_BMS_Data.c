#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "reciver_BMS_Data.h"
#include "../BMS_Statistics/BMS_Statistics.h"
#include "../Generate_BMS_sensorData.h"

char receive_BMSdata[MAX_NOOF_RECEIVED_BMSDATA];
char mock_BMSdata[MAX_NOOF_RECEIVED_BMSDATA] = {"33,36\n27,15\n43,35\n36,42\n49,21\n12,27\n40,9\n13,26\n40,26\n22,36\n11,18\n17,29\n32,30\n12,23\n17,35\n29,2\n22,8\n19,17\n43,6\n11,42\n29,23\n21,19\n34,37\n48,24\n15,20\n13,26\n41,30\n6,23\n12,20\n46,31\n5,25\n34,27\n36,5\n46,29\n13,7\n24,45\n32,45\n14,17\n34,14\n43,0\n37,8\n26,28\n38,34\n3,1\n4,49\n32,10\n26,18\n39,12\n26,36\n44,39\n"};

void Receiver(int file_directory[])
{
	memset(receive_BMSdata, '\0', MAX_NOOF_RECEIVED_BMSDATA);
		
	close(file_directory[1]);
		
	read(file_directory[0], receive_BMSdata, MAX_NOOF_RECEIVED_BMSDATA);
		
	close(file_directory[0]);
	//printf("Receiver: %s",receive_BMSdata);
}


int ReadData_From_Console(receiveData rx_type, char ReadBMS_data[])
{
	int Tx_Status = Get_TransmitStatus();
	
	if((rx_type == READ_FROM_PIPE) && (Tx_Status == ACK_RX_DATA))
	{
		Read_from_PIPE(ReadBMS_data);
		//BMSData_Statistics(ReadBMS_data, MAX_NOOF_RECEIVED_BMSDATA);
		return ACK_RX_DATA;
	}
	else if(rx_type == READ_FROM_PIPE)
	{
		return NACK_RX_DATA;
	}
	
	if(rx_type == READ_FROM_MOCK_DATA)
	{
		Read_mock_data(ReadBMS_data);
		//printf("Rx_data: %s",ReadBMS_data);
		//BMSData_Statistics(ReadBMS_data, MAX_NOOF_RECEIVED_BMSDATA);
		return ACK_RX_DATA;
	}
}

void Read_from_PIPE(char ReadBMS_data[])
{
	memcpy(ReadBMS_data, receive_BMSdata, strlen(receive_BMSdata)+1);
}

void Read_mock_data(char ReadBMS_data[])
{
	memcpy(ReadBMS_data, mock_BMSdata, strlen(mock_BMSdata)+1);
}

