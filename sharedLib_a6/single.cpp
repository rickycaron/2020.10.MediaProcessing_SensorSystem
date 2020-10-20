#include "single.h"
#include "sensor.h"

#include <iostream>

void Single::triggered()
{
    std::cout<<"Single "<<getUnitName()<<" was triggered."<<std::endl;
}

std::shared_ptr<Sensor> Single::getSensor() const
{
    return sensor;
}

void Single::setSensor(const std::shared_ptr<Sensor> &value)
{
    sensor = value;
}

Single &Single::operator ++()
{
    ++(*sensor);
    return *this;
}

Single &Single::operator --()
{
    --(*sensor);
    return *this;
}

