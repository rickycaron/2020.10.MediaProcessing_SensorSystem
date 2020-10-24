#include "factory.h"
#include<iostream>

Factory::Factory()
{
//    std::cout << "this is Factory constructor" << std::endl;
}

Factory::Factory(string_view name):
    factoryName{name}
{
//    std::cout << "this is Factory constructor" << std::endl;
}

std::shared_ptr<SmokeSensor> Factory::createSmokeSensor()
{
    return make_shared<SmokeSensor>(ST_SmokeSensor,factoryName);
}

std::shared_ptr<MotionSensor> Factory::createMotionSensor(tm activationTime, tm deactivationTime)
{
     return make_shared<MotionSensor>(ST_MotionSensor,factoryName,activationTime,deactivationTime);
}

std::shared_ptr<MotionSensor> Factory::createMotionSensor(tm activationTime, tm deactivationTime, int restrication)
{
    return make_shared<MotionSensor>(ST_MotionSensor,factoryName,activationTime,deactivationTime,restrication);
}

std::shared_ptr<GasSensor> Factory::createGasSensor(string gastype)
{
    return make_shared<GasSensor>(ST_GasSensor,factoryName,gastype);
}

std::shared_ptr<MotionSensor> Factory::createMotionSensor(bool permenate)
{
    return make_shared<MotionSensor>(ST_MotionSensor,factoryName,permenate);
}

string Factory::getFactoryName() const
{
    return factoryName;
}

void Factory::setFactoryName(const string &value)
{
    factoryName = value;
}

