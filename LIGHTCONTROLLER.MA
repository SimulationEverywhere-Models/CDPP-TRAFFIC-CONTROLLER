[top]
components : lightcontroller@LightController
out : MyOutN MyOutS MyOutE MyOutW
in : MyIn
Link : ToLightN@lightcontroller MyOutN
Link : ToLightS@lightcontroller MyOutS
Link : ToLightE@lightcontroller MyOutE
Link : ToLightW@lightcontroller MyOutW
Link : MyIn ChangeWay@lightcontroller

