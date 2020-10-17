#include "factory.h"
#include<iostream>

Factory::Factory()
{
    std::cout << "this is Factory constructor" << std::endl;

}

std::unique_ptr<SmokeSensor>  Factory::createSmokeSensor()
{
     std::cout << "this is factory createSmokeSensor" << std::endl;
     return nullptr;
}

std::unique_ptr<MotionSensor> Factory::createMotionSensor(int activationTime, int deactivationTime, int restrication)
{
    std::cout << "this is factory createMotionSensor" << std::endl;
    return nullptr;
}


std::unique_ptr<GasSensor> Factory::createGasSensor()
{
    std::cout << "this is factory createGasSensor" << std::endl;
    return nullptr;
}
