#include "group.h"
#include "sensor.h"
#include "sensorCompById.h"

#include <iostream>

void Group::triggered()
{
    std::cout<<"Group "<<getUnitName()<<" was triggered"<<std::endl;
    for(std::set<std::shared_ptr<Unit>>::iterator i=children.begin();i!=children.end();i++){
        (*i)->triggered();
    }
}

void Group::addUnit(const std::shared_ptr<Unit> & newUnit)
{
    children.insert(newUnit);
    for(unsigned int index=0;index<getAddress().size();index++){
        newUnit->updateAddress(getAddress()[index]);
    }
}

void Group::removeUnit(const std::shared_ptr<Unit> & oldUnit)
{
    children.erase(oldUnit);
    for(unsigned int index=0;index<getAddress().size();index++){
        oldUnit->deleteAddress();
    }
}

void Group::updateAddress(const std::string &newAddress)
{
    getAddress().push_back(newAddress);
    for(std::set<std::shared_ptr<Unit>>::iterator i=children.begin();i!=children.end();i++){
        (*i)->updateAddress(newAddress);
    }
}

void Group::deleteAddress()
{
    getAddress().pop_back();
    for(std::set<std::shared_ptr<Unit>>::iterator i=children.begin();i!=children.end();i++){
        (*i)->deleteAddress();
    }
}

std::shared_ptr<Group> & Group::operator ++()
{

}

std::shared_ptr<Group> & Group::operator --()
{

}


const std::shared_ptr<Unit> Group::findUnit(const std::string_view name) const
{
    auto iter = children.find(std::make_shared<Unit>(name));
    if(iter!=children.end()){
        return *iter;
    }
    else{
        return NULL;
    }
}

