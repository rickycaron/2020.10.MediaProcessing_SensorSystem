#ifndef FACTORY_H
#define FACTORY_H
#include "sensor.h"
#include "smokesensor.h"
#include "motionsensor.h"
#include "gassensor.h"
#include <memory>

class Factory
{
public:
    Factory();
   virtual std::shared_ptr<SmokeSensor> createSmokeSensor() =0;
   virtual std::shared_ptr<MotionSensor> createMotionSensor(tm activationTime,tm deactivationTime,int restrication)=0;
   virtual std::shared_ptr<GasSensor> createGasSensor(string)=0;

private:
    string name;
};

#endif // FACTORY_H
