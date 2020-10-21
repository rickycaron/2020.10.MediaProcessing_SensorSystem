#ifndef VENDORAFACTORY_H
#define VENDORAFACTORY_H

#include "smokesensor.h"
#include "motionsensor.h"
#include "gassensor.h"

class Factory
{    
public:
    Factory();
    Factory(string);
    string getFactoryName() const;
    void setFactoryName(const string &value);
    std::unique_ptr<SmokeSensor> createSmokeSensor() ;
    std::unique_ptr<MotionSensor> createMotionSensor(tm activationTime,tm deactivationTime,int restrication);
    std::unique_ptr<MotionSensor> createMotionSensor(bool);
    std::unique_ptr<GasSensor> createGasSensor(string) ;
private:
    string factoryName;
};
//hello!!!!!!!
#endif
