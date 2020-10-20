#include "unit.h"
#include <iostream>

Unit::Unit(std::string_view name):
    unitName{name}
{
    address.emplace_back(std::string{name});
}

void Unit::triggered()
{
    std::cout<<"Unit "<<unitName<<"was triggered."<<std::endl;
}

std::shared_ptr<Sensor> Unit::getSensor() const
{

}

std::vector<std::string> &Unit::getAddress()
{
    return address;
}

const std::shared_ptr<Unit> Unit::findUnit(std::string_view name) const
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


//Unit::Unit(std::string_view name, std::shared_ptr<Unit> parent):
//    unitName{name},unitParent{parent}
//{

//}
//void Unit::setParent(const std::shared_ptr<Unit> & parent)
//{
//    unitParent=parent;
//}

