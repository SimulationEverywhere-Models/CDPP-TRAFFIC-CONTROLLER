To RUN:

./demo.bat

This test will show how the controller will react when receiving signals at different times. Note that the MinIntervalTime and MaxIntervalTime are set at 10 and 20 respectively. Observe the model through LightsChange port.

In this test, the controller coupled model (lightController and sensorProcessingUnit) is connected to 4 trafficLight atomic models and signals are sent to simulate cars arriving at the various sensors. For a detailed explanation of the execution see sensorProcUnit's readme file.

Note that the simulation will execute indefinitely. I still don't know how to execute for a fixed period.