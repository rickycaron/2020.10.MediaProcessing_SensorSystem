#ifndef VENDORAFACTORY_H
#define VENDORAFACTORY_H

#include "factory.h"
#include"smokesensor.h"

class VendorAFactory : public Factory
{
public:
    VendorAFactory();
    std::unique_ptr<SmokeSensor> createSmokeSensor(SensorType,string);
    std::unique_ptr<MotionSensor> createMotionSensor(SensorType,string,tm activationTime,tm deactivationTime,int restrication);
    std::unique_ptr<GasSensor> createGasSensor(SensorType,string,string);
};
//hello!!!!!!!
#endif // VENDORAFACTORY_H
