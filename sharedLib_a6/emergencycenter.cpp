#include "emergencycenter.h"

EmergencyCenter::EmergencyCenter(std::string_view name):
    centerName{name}
{

}

void EmergencyCenter::addUnit(std::shared_ptr<Unit> newUnit)
{
    units.insert(newUnit);
}

void EmergencyCenter::removeUnit(std::shared_ptr<Unit> oldUnit)
{
    units.erase(oldUnit);
}

void EmergencyCenter::triggered() const
{

}

void EmergencyCenter::overview() const
{

}
