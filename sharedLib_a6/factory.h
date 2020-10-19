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
    virtual std::unique_ptr<SmokeSensor> createSmokeSensor(SensorType,string);
    virtual std::unique_ptr<MotionSensor> createMotionSensor(SensorType,string,int activationTime,int deactivationTime,int restrication);
    virtual std::unique_ptr<GasSensor> createGasSensor(SensorType,string);
};

#endif // FACTORY_H
