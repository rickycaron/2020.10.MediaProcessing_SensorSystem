#include "single.h"
#include "sensor.h"

Single::Single(std::shared_ptr<Unit> parent, std::string_view name, std::unique_ptr<Sensor> sensor):
    Unit{parent, name}, sensorPointer{std::move(sensor)}
{

}

void Single::setSensor(std::unique_ptr<Sensor> value)
{
    sensorPointer = std::move(value);
}

bool Single::isGroup() const
{
    return false;
}

void Single::triggered() const
{
    sensorPointer->triggered();
}

/*void Single::print() const
{

}*/
