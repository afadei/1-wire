
#ifndef TEMP_ACCESS_H
#define TEMP_ACCESS_H

#include "DeviceControlClass.h"

/*
** Class associated to a room (includes 2 motors and one temperature sensor
*/
class tempSensorClass
{
   private:
   std::string atsDeviceName;
   std::string atsBridgeId;
   std::string atsTempDeviceId;
   float aLastTempRead; 
   float aTempReadAvg; 
   int aNumberOfReads;
   OneWireClass28   owTemp;


   public:
   tempSensorClass(std::string pBaseAccessPoint, std::string pDeviceName, std::string pBridgeId, std::string pTempDevId);
   void configureTempSensor(std::string pBaseAccessPoint, std::string pDeviceName, std::string pBridgeId, std::string pTempDevId)
   {
      atsDeviceName = pDeviceName;
      atsBridgeId = pBridgeId;
      atsTempDeviceId = pTempDevId;
      owTemp.configureDevice(pDeviceName, pBaseAccessPoint, pBridgeId, pTempDevId);

   };

   ~tempSensorClass(void){};
   tempSensorClass(void){};
   

float  mGetTemperature(void)
{
  aLastTempRead = owTemp.readDevice();
  aTempReadAvg = (aTempReadAvg+aLastTempRead)/2;
  aNumberOfReads++;
  return aLastTempRead;
}

int  mGetAvgTemperature(void)
{
  return aTempReadAvg;
}
void  mResetAvgTemperature(void)
{
  aTempReadAvg = 0;
}

std::string mGetDeviceName(void){ return atsDeviceName; };


};  /* class */

#endif

