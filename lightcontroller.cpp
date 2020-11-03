/***************************************************************
File name: lightcontroller.h

Author(s): Jean-Christian Delannoy (2062895 - University of Ottawa)

Description: Models a 4-way light controller.

Documentation: 

Version: 0.001	

***************************************************************
***************************************************************
TODO:


	
***************************************************************
CHANGES:

JCD 19/10/2003  Created

   

***************************************************************
***************************************************************
Notes:


****************************************************************
****************************************************************
****************************************************************
****************************************************************/

#include "lightcontroller.h"
#include "message.h"
#include "mainsimu.h"

LightController::LightController(const string &name) 
	: Atomic(name), 
	ToLightN(addOutputPort("ToLightN")), 
	ToLightS(addOutputPort("ToLightS")), 
	ToLightE(addOutputPort("ToLightE")), 
	ToLightW(addOutputPort("ToLightW")),
	ChangeWay(addInputPort("ChangeWay"))
{

}

Model& LightController::initFunction()
{
	Toggle=true;
	sendOutput(0,ToLightN,1);
	sendOutput(0,ToLightS,1);
	sendOutput(0,ToLightE,2);
	sendOutput(0,ToLightW,2);
	
	return *this;
}

Model& LightController::externalFunction(const ExternalMessage& msg)
{
	if(Toggle)
	{
		sendOutput(msg.time(),ToLightN,2);
		sendOutput(msg.time(),ToLightS,2);
		sendOutput(msg.time(),ToLightE,1);
		sendOutput(msg.time(),ToLightW,1);
	}
	else
	{
		sendOutput(msg.time(),ToLightN,1);
		sendOutput(msg.time(),ToLightS,1);
		sendOutput(msg.time(),ToLightE,2);
		sendOutput(msg.time(),ToLightW,2);
	}

	Toggle=!Toggle;
	return *this;
}

Model& LightController::internalFunction(const InternalMessage& msg)
{
	return *this;
}

Model& LightController::outputFunction(const InternalMessage& msg)
{
	return *this;
}


	