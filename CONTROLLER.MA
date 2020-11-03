[top]
components : lightN@TrafficLight lightS@TrafficLight lightW@TrafficLight lightE@TrafficLight Controller
out : LightsChange
in : MySensorN MySensorS MySensorE MySensorW
Link : LightN@Controller GoChangeColor@lightN
Link : LightS@Controller GoChangeColor@lightS
Link : LightE@Controller GoChangeColor@lightE
Link : LightW@Controller GoChangeColor@lightW
Link : MySensorN SensorN@Controller
Link : MySensorS SensorS@Controller
Link : MySensorE SensorE@Controller
Link : MySensorW SensorW@Controller
Link : LightN@Controller LightsChange

[Controller]
components : lightController@LightController sensorProcUnit@SensorProcUnit
in : SensorN SensorS SensorE SensorW
out : LightN LightS LightE LightW
Link : ChangeLights@sensorProcUnit ChangeWay@lightController
Link : ToLightN@lightController LightN
Link : ToLightS@lightController LightS
Link : ToLightE@lightController LightE
Link : ToLightW@lightController LightW
Link : SensorN SensorN@sensorProcUnit
Link : SensorS SensorS@sensorProcUnit
Link : SensorE SensorE@sensorProcUnit
Link : SensorW SensorW@sensorProcUnit

[lightN]
YellowTime : 00:00:01:000

[lightS]
YellowTime : 00:00:01:000

[lightE]
YellowTime : 00:00:01:000

[lightW]
YellowTime : 00:00:01:000

[sensorProcUnit]
MinIntervalTime : 00:00:10:000
MaxIntervalTime : 00:00:20:000


