[top]
components : sensorProcUnit@SensorProcUnit
in : MyInN MyInS MyInW MyInE
out : MyChangeLights
Link : ChangeLights@sensorProcUnit MyChangeLights
Link : MyInN SensorN@sensorProcUnit
Link : MyInS SensorS@sensorProcUnit
Link : MyInE SensorE@sensorProcUnit
Link : MyInW SensorW@sensorProcUnit

[sensorProcUnit]
MinIntervalTime : 00:00:10:000
MaxIntervalTime : 00:00:20:000

