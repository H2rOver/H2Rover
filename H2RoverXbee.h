// Created by: Scott Timpe
// Created on: 11/5/2017
// Last edited By: Scott Timpe
// Last edited bn: 11/5/2017
//

#ifndef H2ROVER_XBEE_H
#define H2ROVER_XBEE_H

#include "PinDeclarations.h"
#include <XBee.h>

class H2RoverXbee {
public:
    H2RoverXbee(int xbee_device_type);
    ~H2RoverXbee();
	int sendPacket(uint8_t* send_data_array);
	int getPacket(uint8_t* receive_data_array);
	void initialize();

private:

	//xbee type correspond to Mac Address
	const int COORDINATOR = 0;
	const int ENDDEVICE = 1;

	//constants for transmission
	const int TX_SUCCESS = 1;

	//constants for receiving packets
	const int NO_RESPONSE = -1;
	const int INDETERMINATE = 0;
	const int RECEIVED_RX_PACKET = 2;
	const int RECIEVED_PACKET_ACK = 3;

    uint8_t* packet;
	uint64_t macAddress;
	HardwareSerial* xbeeSerial;
	Xbee xbee;
	XBeeAddress64 addr64;
	ZBTxRequest tx;
	XBeeResponse response;
	ZBRxResponse rx;
	ModemStatusResponse msr;
};
#endif //H2ROVER_XBEE_H