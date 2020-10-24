#ifndef VENDORAFACTORY_H
#define VENDORAFACTORY_H

#include "smokesensor.h"
#include "motionsensor.h"
#include "gassensor.h"

class Factory
{    
public:
    Factory();
    Factory(string_view name);
    std::shared_ptr<SmokeSensor> createSmokeSensor() ;
    std::shared_ptr<MotionSensor> createMotionSensor(tm activationTime,tm deactivationTime);
    std::shared_ptr<MotionSensor> createMotionSensor(bool);
    std::shared_ptr<MotionSensor> createMotionSensor(tm activationTime,tm deactivationTime,int restrication);
    std::shared_ptr<GasSensor> createGasSensor(string) ;
    string getFactoryName() const;
    void setFactoryName(const string &value);

private:
    string factoryName;
};
//hello!!!!!!!
#endif
