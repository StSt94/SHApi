#ifndef SHAPI_DEVICE_H
#define SHAPI_DEVICE_H
///Device interface describes fuctions every device must know.
/*! 
The Device interface will be inherited by different Devices like sensors or actuators. 
This interface is to make sure, every device can comunicate with the controll center and
the controll center can communicate with the devices.
*/


class device {
private:
	//variables
	///Variable where the status of the device is stored.
	int status;
	
	//functions
	///Interrupt on the bus to get attention.
	/*!
	if device wants to tell the controll center that somthing happened, 
	it sends an interrupt and then the controll center pulls the informations from this device.
	The return value should return the number of errors occured.
	*/
	virtual int sendInterrupt() = 0;
	
	///sendData() implements the function to send the data.
	/*!
	sendData() should implement the function to send the data via the specific bus system. 
	If possible it should return 0 if no errors occured. Otherwise if needed it can also return the value
	nedded for the conversation (eg. some sort of conversation id).
	*/
	virtual int sendData() = 0;

	

public:
	///Returns the status of the device.
	/*!
	getStatus() returns the status of the device. If status is "okay" it should always return 0. 
	Otherwise it should return (if possible) the error code of the error.
	*/
	virtual int getStatus() = 0;

	///setData() sets the desired value of the actor.
	/*!
	setData() sets the desired value of the actor. The return value should contain the number of errors occured.
	If no errors occured, the return value should be 0.
	*/
	virtual int setData() = 0;

};


#endif // !SHAPI_DEVICE_H

