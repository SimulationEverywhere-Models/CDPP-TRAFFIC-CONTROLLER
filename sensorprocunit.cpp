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

#include "sensorprocunit.h"
#include "message.h"
#include "mainsimu.h"

SensorProcUnit::SensorProcUnit(const string &name) 
	: Atomic(name),
	ChangeLights(addOutputPort("ChangeLights")),
	SensorN(addInputPort("SensorN")),
	SensorS(addInputPort("SensorS")),
	SensorE(addInputPort("SensorE")),
	SensorW(addInputPort("SensorW")),
	tMinInterval(00,00,07,000),
	tMaxInterval(00,00,13,000)
{
	string time(MainSimulator::Instance().getParameter(description(), "MinIntervalTime"));
	if(time!="")
	{
		tMinInterval=time;
	}
	time=MainSimulator::Instance().getParameter(description(), "MaxIntervalTime");
	if(time!="")
	{
		tMaxInterval=time;
	}

	if(tMaxInterval<tMinInterval)
	{
		Time temp=tMaxInterval;
		tMaxInterval=tMinInterval;
		tMinInterval=temp;
	}
}

Model& SensorProcUnit::initFunction()
{
	tLastChangeTime=Time();
	holdIn(passive,tMaxInterval);
	return *this;
}

Model& SensorProcUnit::externalFunction(const ExternalMessage& msg)
{
	if(msg.time()-tLastChangeTime > tMinInterval)
	{
		//////////////////////////////////////////
		// send signal to change lights
		tLastChangeTime=msg.time();
		sendOutput(msg.time(),ChangeLights,1);
		if(state() == passive)
			holdIn(passive,tMaxInterval);
		else
			holdIn(active,tMaxInterval);
		// send signal to change lights
		//////////////////////////////////////////
	}
	else
	{
		//////////////////////////////////////////
		// too early to change lights but we will do it at tMinInterval
		Time tDeltaMinMax=tMaxInterval-tMinInterval;
		if(state() == passive)
			holdIn(passive,nextChange()-tDeltaMinMax);
		else
			holdIn(active,nextChange()-tDeltaMinMax);
		// too early to change lights but we will do it at tMinInterval
		//////////////////////////////////////////
	}
	
	return *this;
}

Model& SensorProcUnit::internalFunction(const InternalMessage& msg)
{
	//////////////////////////////////////////
	// send signal to change lights
	tLastChangeTime=msg.time();
	sendOutput(msg.time(),ChangeLights,1);
	if(state() == passive)
		holdIn(passive,tMaxInterval);
	else
		holdIn(active,tMaxInterval);
	// send signal to change lights
	//////////////////////////////////////////

	return *this;
}

Model& SensorProcUnit::outputFunction(const InternalMessage& msg)
{
	return *this;
}


	