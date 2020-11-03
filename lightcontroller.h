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

#ifndef _LIGHTCONTROLLER_H__
#define _LIGHTCONTROLLER_H__

#include "atomic.h"
#include "message.h"

class LightController : public Atomic
{
public:
	LightController(const string &name = "LightController");
	virtual string className() const {return "LightController";};

protected:
	Model& initFunction();
	Model& externalFunction(const ExternalMessage &);
	Model& internalFunction(const InternalMessage &);
	Model& outputFunction(const InternalMessage &);

private:
	//output ports
	Port &ToLightN;
	Port &ToLightS;
	Port &ToLightE;
	Port &ToLightW;

	//input ports
	Port &ChangeWay;

	bool Toggle;
};

#endif _LIGHTCONTROLLER_H__
