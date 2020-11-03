/***************************************************************
File name: sensorprocunit.h

Author(s): Jean-Christian Delannoy (2062895 - University of Ottawa)

Description: The sensor processing unit

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

#ifndef _SENSORPROCUNIT_H__
#define _SENSORPROCUNIT_H__

#include "atomic.h"
#include "message.h"
#include "time.h"

class SensorProcUnit : public Atomic
{
public:
	SensorProcUnit(const string &name = "SensorProcUnit");
	virtual string className() const {return "SensorProcUnit";};

protected:
	Model& initFunction();
	Model& externalFunction(const ExternalMessage &);
	Model& internalFunction(const InternalMessage &);
	Model& outputFunction(const InternalMessage &);

private:
	//output ports
	Port &ChangeLights;

	//input ports
	Port &SensorN;
	Port &SensorS;
	Port &SensorE;
	Port &SensorW;

	Time tMinInterval;
	Time tMaxInterval;
	Time tLastChangeTime;
};

#endif _SENSORPROCUNIT_H__
