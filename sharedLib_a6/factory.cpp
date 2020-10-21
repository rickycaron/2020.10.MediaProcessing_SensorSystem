#include "factory.h"
#include <iostream>

Factory::Factory()
{
    std::cout << "this is VendorAFactory constructor with no name" << std::endl;
}

Factory::Factory(string factoryname):factoryName(factoryname)
{
    std::cout << "this is VendorAFactory constructor with vendor name :"<<factoryName<< std::endl;
}

std::unique_ptr<SmokeSensor> Factory::createSmokeSensor()
{
//   std::cout << "this is VendorAFactory createSmokeSensor function" << std::endl;
    return std::make_unique<SmokeSensor>(ST_SmokeSensor,factoryName);
}

//restrication = distance
std::unique_ptr<MotionSensor> Factory::createMotionSensor(tm activationTime, tm deactivationTime, int restrication)
{
//  std::cout << "this is VendorAFactory createMotionSensor function" << std::endl;
    return std::make_unique<MotionSensor>(ST_MotionSensor,factoryName,activationTime,deactivationTime,restrication);
}

std::unique_ptr<MotionSensor> Factory::createMotionSensor(bool permenativeactive)
{
     return std::make_unique<MotionSensor>(ST_MotionSensor,factoryName,permenativeactive);
}

std::unique_ptr<GasSensor> Factory::createGasSensor( string gastype)
{
//  std::cout << "this is VendorAFactory createGasSensor function" << std::endl;
    return std::make_unique<GasSensor>(ST_GasSensor,factoryName,gastype);
}

string Factory::getFactoryName() const
{
    return factoryName;
}

void Factory::setFactoryName(const string &value)
{
    factoryName = value;
}
