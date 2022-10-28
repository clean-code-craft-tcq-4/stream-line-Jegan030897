#include <stdio.h>
#include <stdlib.h>

#define MAX_VALUE   50

#define MAXSENSORCNT   2
#define LENGTH_OF_BMSDATA         8
#define MAX_NOOF_RECEIVED_BMSDATA  (MAXSENSORCNT * MAX_VALUE * LENGTH_OF_BMSDATA)

#define ACK_RX_DATA    1
#define NACK_RX_DATA   0

typedef enum
{
    READ_FROM_PIPE = 0,
    READ_FROM_MOCK_DATA
}receiveData;

void Receiver(int file_directory[]);
int ReadData_From_Console(receiveData rx_type, char ReadBMS_data[]);
void Read_from_PIPE(char ReadBMS_data[]);
void Read_mock_data(char ReadBMS_data[]);
