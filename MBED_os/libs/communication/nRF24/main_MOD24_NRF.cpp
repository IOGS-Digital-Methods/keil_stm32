/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "MOD24_NRF.h"

#define WAIT_TIME_MS 500 

UnbufferedSerial    my_pc(USBTX, USBRX);
char        charStr[128];

// RF Transmission of data
#define TRANSFER_SIZE   8
SPI     my_spi(D11, D12, D13);
nRF24L01P       nRF24_mod(&my_spi, D8, D7, D6);
// MOSI, MISO, SCK, CSN, CE, IRQ
char        dataToSend[TRANSFER_SIZE] = {1, 50, 60, 128, 36, 66, 255, 255};
char        dataReceived[TRANSFER_SIZE] = {0};


// Initialization function for the BT nRF24L01 module
//  frequency in MHz
void        initNRF24(int frequency);
// Receiving function for the BT nRF24L01 module
//  data : array of data received by the module
//  return the number of bytes received
uint8_t     receiveNRF24(char *data);
// Transmitting function for the BT nRF24L01 module
//  data : array of data to transmit
void        transmitNRF24(char *data);


// MAIN FUNCTION
int main()
{
    my_pc.baud(115200);
    sprintf(charStr, "Mbed OS %d.%d.%d.\r\n", MBED_MAJOR_VERSION, MBED_MINOR_VERSION, MBED_PATCH_VERSION);
    my_pc.write(charStr, strlen(charStr));

    initNRF24(2450);

    while (true)
    {
        dataToSend[0]++;
        transmitNRF24(dataToSend);
        uint8_t  nb_data = receiveNRF24(dataReceived);
        if(nb_data != 0){
            for(int i = 0; i < nb_data; i++){
                sprintf(charStr, "%d ", dataReceived[i]);
                my_pc.write(charStr, strlen(charStr));               
            }
            sprintf(charStr, "\r\n");
            my_pc.write(charStr, strlen(charStr)); 
        }
        thread_sleep_for(WAIT_TIME_MS);
    }
}

// Initialization function for the BT nRF24L01 module
void initNRF24(int frequency){
    nRF24_mod.powerUp();
    wait_us(100000);
    nRF24_mod.setAirDataRate(NRF24L01P_DATARATE_250_KBPS);
    nRF24_mod.setRfFrequency(frequency);
    wait_us(1000000);

    sprintf(charStr, "nRF24L01+ Frequency    : %d MHz\r\n",  nRF24_mod.getRfFrequency());
    my_pc.write(charStr, strlen(charStr)); 
    sprintf(charStr, "nRF24L01+ Data Rate    : %d kbps\r\n", nRF24_mod.getAirDataRate());
    my_pc.write(charStr, strlen(charStr)); 

    nRF24_mod.setTransferSize( TRANSFER_SIZE );
    nRF24_mod.setReceiveMode();
    nRF24_mod.enable();
}

// Receiving function for the BT nRF24L01 module
uint8_t receiveNRF24(char *data){
    uint8_t        rxDataCnt = 0;
    if ( nRF24_mod.readable() ) {
        // Read the data into the receive buffer
        rxDataCnt = nRF24_mod.read( NRF24L01P_PIPE_P0, data, TRANSFER_SIZE);
    }
    return rxDataCnt;
}

// Transmitting function for the BT nRF24L01 module
//  data : array of data to transmit
void        transmitNRF24(char *data){    
    nRF24_mod.write( NRF24L01P_PIPE_P0, data, TRANSFER_SIZE );
}
