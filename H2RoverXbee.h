// Created by: Scott Timpe
// Created on: 11/5/2017
// Last edited By: Scott Timpe
// Last edited bn: 11/5/2017
//

#ifndef H2ROVER_XBEE_H
#define H2ROVER_XBEE_H

#include "PinDeclarations.h"
#include <XBee.h>

class H2Xbee {
public:
    H2Xbee(int xbee_device_type);
    ~H2Xbee();
	int send_data(uint8_t* send_data_array);
	int receive_data(uint8_t* receive_data_array);
	void initialize(HardwareSerial* serial);

private:
	//xbee type correspond to Mac Address
	const int COORDINATOR = 0;
	const int ENDDEVICE = 1;
	//constants for tx
	const int TX_SUCCESS = 1;
	//constants for rx
	const int NO_RESPONSE = -1;
	const int INDETERMINATE = 0;
	const int RECEIVED_SOMETHING = 1;
	const int RECEIVED_RX_PACKET = 2;
	const int RECIEVED_RX_PACKET_AND_SENDER_ACK = 3;
	
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