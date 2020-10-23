#include "group.h"
#include "sensor.h"
#include "sensorCompById.h"

#include <iostream>

Group::Group(string_view name):
    Unit(name)
{
}

void Group::triggered()
{
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

Group & Group::operator ++()
{
    activate();
    return (*this);
}

Group & Group::operator --()
{
    deactivate();
    return (*this);
}

void Group::activate()
{
    for(std::set<std::shared_ptr<Unit>>::iterator i=children.begin();i!=children.end();i++){
        (*i)->activate();
    }
}

void Group::deactivate()
{
    for(std::set<std::shared_ptr<Unit>>::iterator i=children.begin();i!=children.end();i++){
        (*i)->deactivate();
    }
}

std::shared_ptr<Sensor> Group::getSensor()
{
    return NULL;
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


