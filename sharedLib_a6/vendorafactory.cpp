#include "vendorafactory.h"
#include <iostream>

VendorAFactory::VendorAFactory()
{
    std::cout << "this is VendorAFactory constructor" << std::endl;

}

std::unique_ptr<SmokeSensor> VendorAFactory::createSmokeSensor(SensorType sensortype, string vendor)
{
    std::cout << "this is VendorAFactory createSmokeSensor function" << std::endl;
    return std::make_unique<SmokeSensor>(sensortype,vendor);
}

std::unique_ptr<MotionSensor> VendorAFactory::createMotionSensor(SensorType sensortype, string vendor, tm activationTime, tm deactivationTime, int restrication)
{
    std::cout << "this is VendorAFactory createMotionSensor function" << std::endl;
    return std::make_unique<MotionSensor>(sensortype,vendor,activationTime,deactivationTime,restrication);
}

std::unique_ptr<GasSensor> VendorAFactory::createGasSensor(SensorType sensortype, string vendor, string gastype)
{
    std::cout << "this is VendorAFactory createGasSensor function" << std::endl;
    return std::make_unique<GasSensor>(sensortype,vendor,gastype);
}
