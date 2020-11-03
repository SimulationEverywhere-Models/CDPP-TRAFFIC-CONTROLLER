/***************************************************************
File name: trafficlight.cpp

Author(s): Jean-Christian Delannoy (2062895 - University of Ottawa)

Description: Models a red-yellow-green traffic light.

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

#include "trafficlight.h"
#include "message.h"
#include "mainsimu.h"

TrafficLight::TrafficLight(const string &name) 
	: Atomic(name), 
	GoChangeColor(addInputPort("GoChangeColor")), 
	YellowTime(0,0,2,0)
{
	string time(MainSimulator::Instance().getParameter(description(),"YellowTime"));
	if(time!="") YellowTime=time ;
	
	Color=red;
}

Model& TrafficLight::initFunction()
{
	return *this;
}

Model& TrafficLight::externalFunction(const ExternalMessage& msg)
{
	if(msg.port()==GoChangeColor)
	{
		int messValue = static_cast<int>(msg.value());
		if(messValue==1)
		{
			//color SHOULD be GREEN
			//turn to red in (YellowTime) seconds
			Color=yellow;
			holdIn(active,YellowTime);
		}
		else
		{
			//color SHOULD be RED
			//turn to green in (YellowTime) seconds
			holdIn(active,YellowTime);
		}
	}
	
	return *this;
}

Model& TrafficLight::internalFunction(const InternalMessage& msg)
{
	if(Color==yellow)
	{
		Color=red;
	}
	else if(Color==red)
	{
		Color=green;
	}
	passivate();
	return *this;
}

Model& TrafficLight::outputFunction(const InternalMessage& msg)
{
	return *this;
}


	