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
    //Constant for maximum packet size
    static const int MAXIMUM_PACKET_SIZE = 10;

    H2RoverXbee(int xbee_device_type);
    ~H2RoverXbee();
	int sendPacket(uint8_t send_data_array[MAXIMUM_PACKET_SIZE]);
	int getPacket(uint8_t receive_data_array[MAXIMUM_PACKET_SIZE]);
	void initialize();



private:

	//xbee type correspond to Mac Address
	const int COORDINATOR = 0;
	const int ENDDEVICE = 1;

	//constants for transmission
	const int TX_SUCCESS = 1;

	//constants for receiving packets
	const int NO_RESPONSE = -2;
	const int INDETERMINATE = -1;
	const int RECEIVED_RX_PACKET = 1;
	const int RECIEVED_PACKET_ACK = 0;



	uint64_t macAddress;
	XBee xbee;
	XBeeAddress64 addr64;
	ZBTxRequest tx;
	XBeeResponse response;
	ZBRxResponse rx;
	ModemStatusResponse msr;
};
#endif //H2ROVER_XBEE_H