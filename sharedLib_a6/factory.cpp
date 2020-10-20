#include "factory.h"
#include<iostream>

Factory::Factory()
{
    std::cout << "this is Factory constructor" << std::endl;

}

std::unique_ptr<SmokeSensor>  Factory::createSmokeSensor(SensorType sensortype,string vender)
{
     std::cout << "this is factory createSmokeSensor" << std::endl;
     return nullptr;
}

std::unique_ptr<MotionSensor> Factory::createMotionSensor(SensorType sensortype,string vender,tm activationTime, tm deactivationTime, int restrication)
{
    std::cout << "this is factory createMotionSensor" << std::endl;
    return nullptr;
}


std::unique_ptr<GasSensor> Factory::createGasSensor(SensorType sensortype,string vender,string gastype)
{
    std::cout << "this is factory createGasSensor" << std::endl;
    return nullptr;
}
