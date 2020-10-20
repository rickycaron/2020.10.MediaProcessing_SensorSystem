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
    std::unique_ptr<SmokeSensor> createSmokeSensor(SensorType,string);
    std::unique_ptr<MotionSensor> createMotionSensor(SensorType,string,tm activationTime,tm deactivationTime,int restrication);
    std::unique_ptr<GasSensor> createGasSensor(SensorType,string,string);
};

#endif // FACTORY_H
