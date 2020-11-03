/***************************************************************
File name: trafficlight.h

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

#ifndef _TRAFFICLIGHT_H__
#define _TRAFFICLIGHT_H__

#include "atomic.h"

enum LightColor
{
	green, yellow, red
};

class TrafficLight : public Atomic
{
public:
	TrafficLight(const string &name = "TrafficLight");
	virtual string className() const {return "TrafficLight";};

protected:
	Model& initFunction();
	Model& externalFunction(const ExternalMessage &);
	Model& internalFunction(const InternalMessage &);
	Model& outputFunction(const InternalMessage &);

private:
	//if(green) change to yellow (stay yellow for YellowTime) and change to red
	//if(red) change to green with a dealay of YellowTime 
	Port& GoChangeColor; 
		
	LightColor Color;
	Time YellowTime;
};

#endif _TRAFFICLIGHT_H__
