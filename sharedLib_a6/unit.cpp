#include "unit.h"
#include <iostream>

Unit::Unit(std::shared_ptr<Unit> parent, std::string_view name):
    unitParent{parent}, unitName{name}
{

}

Unit::Unit(std::string_view name):
    unitName{name}
{

}

void Unit::setParent(std::shared_ptr<Unit> value)
{
    unitParent = value;
}

const std::shared_ptr<Unit> & Unit::getParent() const
{
    return unitParent;
}

void Unit::triggered() const
{
    std::cout<<"Unit "<<unitName<<"was triggered."<<std::endl;
}

bool Unit::isGroup() const
{
    return false;
}

/*void Unit::print() const
{

}*/
