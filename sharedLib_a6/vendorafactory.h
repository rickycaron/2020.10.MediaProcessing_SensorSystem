#ifndef VENDORAFACTORY_H
#define VENDORAFACTORY_H

#include "factory.h"
#include"smokesensor.h"

class VendorAFactory : public Factory
{
public:
    VendorAFactory();
    std::unique_ptr<SmokeSensor> createSmokeSensor() override;
    std::unique_ptr<MotionSensor> createMotionSensor(int activationTime,int deactivationTime,int restrication) override;
    std::unique_ptr<GasSensor> createGasSensor() override;
};

#endif // VENDORAFACTORY_H
