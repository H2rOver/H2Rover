// Created by: Scott Timpe
// Created on: 11/5/2017
// Last edited By: Daniel Benusovich
// Last edited bn: 11 November 2017
//

#include "H2RoverXbee.h"


H2RoverXbee::H2RoverXbee(int xbee_device_type) {

    this->xbee = XBee();


    if (xbee_device_type == COORDINATOR) {
        this->macAddress = 0x0013a2004154ec07;
    } else if (xbee_device_type == ENDDEVICE) {
        this->macAddress = 0x0013a2004154ec02;
    }
    this->addr64 = XBeeAddress64(this->macAddress);

    // create reusable response objects for responses we expect to handle 	
    this->response = XBeeResponse();
    this->rx = ZBRxResponse();
    this->msr = ModemStatusResponse();

}

H2RoverXbee::~H2RoverXbee() {}

//Xbee will receive data and push data on Serial
void H2RoverXbee::initialize() {
    this->xbee.setSerial(Serial);
}

//Sends data to the ENDDEVICE
//Pass array pointer to data to send
int H2RoverXbee::sendPacket(uint8_t send_data_array[]) {

    uint8_t payload[send_data_array[0]];

    //Assign send_data_array[1] to payload[0] etc
    for (int i = 0; i < send_data_array[0]; i++) {
        payload[i] = send_data_array[i + 1];
    }

    this->tx = ZBTxRequest(this->macAddress, payload, sizeof(payload)); // 64-bit addressing, packet, and packet length
    this->xbee.send(this->tx); // send packet to remote radio

    return 0;
}

//Receive data from ENDDEVICE
//Populates array whose pointer is passed
int H2RoverXbee::getPacket(uint8_t receive_data_array[]) {

    int packetStatus = INDETERMINATE;

    /*** begin xbee code ***/
    this->xbee.readPacket();

    //Check if a packet has been received
    if (this->xbee.getResponse().isAvailable()) {

        //Packet Received
        //Constant from XBee.h include
    if (this->xbee.getResponse().getApiId() == ZB_RX_RESPONSE) {
            packetStatus = RECEIVED_RX_PACKET;
            //Populate rx
            this->xbee.getResponse().getZBRxResponse(this->rx);

            //Verify Reception
            if (this->rx.getOption() == ZB_PACKET_ACKNOWLEDGED) {
                packetStatus = RECIEVED_PACKET_ACK;
            }

            //Give packet length as first parameter in returned array
            receive_data_array[0] = this->rx.getDataLength();

            //Process packet and assign it to passed in array
            for (int i = 0; i < receive_data_array[0]; i++) {
                receive_data_array[i + 1] = this->rx.getData()[i];
            }
        }

        //Error in receiving packet
    } else if (this->xbee.getResponse().isError()) {
        packetStatus = NO_RESPONSE;
    }

    return packetStatus;
}


uint8_t H2RoverXbee::getMaximumPacketSize() {
    return MAXIMUM_PACKET_SIZE;
}

void H2RoverXbee::setMaximumPacketSize(uint8_t maximumPacketSize) {
    this->MAXIMUM_PACKET_SIZE = maximumPacketSize;
}