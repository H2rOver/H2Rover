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
    //Int for maximum packet size
    static uint8_t MAXIMUM_PACKET_SIZE = 10;

    //TX packet constants
    static const int NO_RESPONSE = -2;
    static const int INDETERMINATE = -1;
    static const int RECEIVED_RX_PACKET = 1;
    static const int RECIEVED_PACKET_ACK = 0;

    //Preps all private variables for communications
    //0 => coordinator
    //1 => end device
    //This constructor sets up only teo devices with particular MAC addresses. This is not generic
    H2RoverXbee(int xbee_device_type);

    ~H2RoverXbee();

    //Sets the Serial line for communication
    void initialize();

    /*  Sends the passed in array to another specified Xbee
        Ensure that the first element in the array that is passed in contains the length of the payload
        Only sends characters
        Returns 4 possible values:
        -2 => No packet sent
        -1 => Error in XBee
        1 => Packet received but not acknowledged
        0 => Success
        Packets should only be acted upon a reception of 0
    */
    int sendPacket(uint8_t send_data_array[]);

    //Recieves a packet that has been sent
    //returns 0 upon success
    int getPacket(uint8_t receive_data_array[]);

    //Returns the set packet size for the local XBee
    int getMaximumPacketSize();

    //Sets the packet size for the local XBee
    void setMaximumPacketSize(uint8_t maximumPacketSize);


private:

    //xbee type correspond to Mac Address
    const int COORDINATOR = 0;
    const int ENDDEVICE = 1;

    uint64_t macAddress;
    XBee xbee;
    XBeeAddress64 addr64;
    ZBTxRequest tx;
    XBeeResponse response;
    ZBRxResponse rx;
    ModemStatusResponse msr;
};

#endif //H2ROVER_XBEE_H