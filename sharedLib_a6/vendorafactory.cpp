#include "vendorafactory.h"
#include <iostream>

VendorAFactory::VendorAFactory()
{
    std::cout << "this is VendorAFactory constructor" << std::endl;

}

std::unique_ptr<SmokeSensor> VendorAFactory::createSmokeSensor()
{
   std::cout << "this is VendorAFactory createSmokeSensor function" << std::endl;
   return std::make_unique<SmokeSensor>();
}

std::unique_ptr<MotionSensor> VendorAFactory::createMotionSensor(int activationTime, int deactivationTime, int restrication)
{
    std::cout << "this is VendorAFactory createMotionSensor function" << std::endl;
    return std::make_unique<MotionSensor>(activationTime,deactivationTime,restrication);
}

std::unique_ptr<GasSensor> VendorAFactory::createGasSensor()
{
    std::cout << "this is VendorAFactory createGasSensor function" << std::endl;
    return std::make_unique<GasSensor>();
}
