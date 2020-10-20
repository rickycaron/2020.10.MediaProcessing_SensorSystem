#ifndef VENDORAFACTORY_H
#define VENDORAFACTORY_H

#include "factory.h"
#include"smokesensor.h"

class VendorAFactory : public Factory
{
    enum SensorType{ST_Undefined,ST_SmokeSensor,ST_MotionSensor,ST_GasSensor};

public:
    VendorAFactory();
    std::unique_ptr<SmokeSensor> createSmokeSensor() ;
    std::unique_ptr<MotionSensor> createMotionSensor(tm activationTime,tm deactivationTime,int restrication);
    std::unique_ptr<GasSensor> createGasSensor(string) ;
};
//hello!!!!!!!
#endif // VENDORAFACTORY_H
