// Created by: Scott Timpe
// Created on: 11/5/2017
// Last edited By: Scott Timpe
// Last edited bn: 11/5/2017
//

#include "H2RoverXbee.h"

H2RoverXbee::H2RoverXbee(int xbee_device_type) {
	
	this->xbee = Xbee();
		
	if(xbee_device_type == COORDINATOR) {
		this->macAddress = 0x0013a2004154ec07;
	}
	else if(xbee_device_type == ENDDEVICE) {
		this->macAddress = 0x0013a2004154ec02;
	}
	this->addr64 = XBeeAddress64(this->macAddress);

    // create reusable response objects for responses we expect to handle 	
	this->response = XBeeResponse();
	this->rx = ZBRxResponse();
	this->msr = ModemStatusResponse();
	
}

H2RoverXbee::~H2RoverXbee() {}

H2RoverXbee::initialize(HardwareSerial* serialPointer) {
	this->xbeeSerial = serialPointer;
	this->xbee.setSerial(this->xbeeSerial);
}

int H2RoverXbee::send_data(uint8_t* send_data_array) {
	  this->tx = ZBTxRequest(this->macAddress, send_data_array, sizeof(send_data_array)); // 64-bit addressing, packet, and packet length
      this->xbee.send(this->tx); // send packet to remote radio
	  
	  return TX_SUCCESS;
}

int H2RoverXbee::receive_data(uint8_t* receive_data_array) {
	int packetStatus = INDETERMINATE;
	/*** begin xbee code ***/
    this->xbee.readPacket();
    
    if (this->xbee.getResponse().isAvailable()) {
		// got something
		packetStatus = RECEIVED_SOMETHING;
           
		if (this->xbee.getResponse().getApiId() == ZB_RX_RESPONSE) {
			// got a zb rx packet
			packetStatus = RECEIVED_RX_PACKET;
        
			// now fill our zb rx class
			this->xbee.getResponse().getZBRxResponse(this->rx);
			this->xbeeSerial.println("got an rx packet");
            
			if (this->rx.getOption() == ZB_PACKET_ACKNOWLEDGED) {
				// the sender got an ACK
				packetStatus = RECIEVED_RX_PACKET_AND_SENDER_ACK;
				this->xbeeSerial.println("packet acknowledged");
			} else {
				this->xbeeSerial.println("packet not acknowledged");
			}
        
			this->xbeeSerial.print("checksum is ");
			this->xbeeSerial.println(this->rx.getChecksum(), HEX);

			this->xbeeSerial.print("packet length is ");
			this->xbeeSerial.println(this->rx.getPacketLength(), DEC);
        
			for (int i = 0; i < this->rx.getDataLength(); i++) {
				receive_data_array[i] = this->rx.getData()[i];
				this->xbeeSerial.print("payload [");
				this->xbeeSerial.print(i, DEC);
				this->xbeeSerial.print("] is ");
				this->xbeeSerial.println(receive_data_array[i]);
			}
        
			for (int i = 0; i < this->xbee.getResponse().getFrameDataLength(); i++) {
				this->xbeeSerial.print("frame data [");
				this->xbeeSerial.print(i, DEC);
				this->xbeeSerial.print("] is ");
				this->xbeeSerial.println(this->xbee.getResponse().getFrameData()[i], HEX);
			}
		}
    } else if (this->xbee.getResponse().isError()) {
		packetStatus = NO_RESPONSE;
		this->xbeeSerial.print("error code:");
		this->xbeeSerial.println(this->xbee.getResponse().getErrorCode());
	}
	
	return packetStatus;
}