#include "single.h"
#include "sensor.h"

#include <iostream>

Single::Single(string_view name, const std::shared_ptr<Sensor> &newSensor):
    Unit(name),sensor{newSensor}
{

}

void Single::triggered()
{
    if(sensor->getActivationState()){
        std::cout<<getUnitName()<<" is triggered."<<std::endl;
    }
    sensor->triggered();
}

std::shared_ptr<Sensor> Single::getSensor()
{
    return sensor;
}

void Single::setSensor(const std::shared_ptr<Sensor> &value)
{
    sensor = value;
}

Single &Single::operator ++()
{
    activate();
    return *this;
}

Single &Single::operator --()
{
    deactivate();
    return *this;
}

void Single::activate()
{
    ++(*sensor);
}

void Single::deactivate()
{
    --(*sensor);
}

