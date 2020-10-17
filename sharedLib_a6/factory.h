#ifndef FACTORY_H
#define FACTORY_H
#include "smokesensor.h"
#include <memory>

class Factory
{
public:
    Factory();
    virtual std::unique_ptr<SmokeSensor> createSmokeSensor();
    virtual std::unique_ptr<MotionSensor> createMotionSensor(int activationTime,int deactivationTime,int restrication);
    virtual std::unique_ptr<GasSensor> createGasSensor();
};

#endif // FACTORY_H
