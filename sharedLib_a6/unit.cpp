#include "unit.h"
#include <iostream>

Unit::Unit(std::string_view name):
    unitName{name}
{
    address.emplace_back(std::string{name});
}

const std::shared_ptr<Unit> Unit::findUnit(std::string_view name) const
{

}

void Unit::triggered()
{

}

std::shared_ptr<Sensor> Unit::getSensor()
{

}

void Unit::printAddress()
{
    std::cout<<"In";
    for(int index = address.size()-1; index>=2; index--){
        std::cout<<" "<<address[index]<<",";
    }
    std::cout<<" "<<address[1]<<": ";
}

std::vector<std::string> &Unit::getAddress()
{
    return address;
}

Unit &Unit::operator ++()
{
    activate();
    return *this;
}

Unit &Unit::operator --()
{
    deactivate();
    return *this;
}

void Unit::activate()
{

}

void Unit::deactivate()
{

}

void Unit::addUnit(const std::shared_ptr<Unit> &)
{

}

void Unit::removeUnit(const std::shared_ptr<Unit> &)
{

}

void Unit::updateAddress(const std::string &newAddress)
{
    address.push_back(newAddress);
}

void Unit::deleteAddress()
{
    address.pop_back();
}

