#include "single.h"
#include "sensor.h"

#include <iostream>

Single::Single(string_view name):
    Unit(name)
{

}

void Single::triggered()
{
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

