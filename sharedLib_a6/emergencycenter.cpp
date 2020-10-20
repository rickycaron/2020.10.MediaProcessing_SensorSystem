#include "emergencycenter.h"
#include "unit.h"
#include "group.h"
#include "single.h"
#include <iostream>

EmergencyCenter::EmergencyCenter():
    centerName{"defaultCenter"}
{
    controlUnit = std::make_unique<Group>(centerName);
}

EmergencyCenter::EmergencyCenter(std::string_view name):
    centerName{name}
{
    controlUnit = std::make_unique<Group>(centerName);
}

void EmergencyCenter::setRelation(const std::shared_ptr<Group> & parent,const std::shared_ptr<Unit> & child)
{
    parent->addUnit(child);
    addToSensorSet(child);
}

void EmergencyCenter::resetRelation(const std::shared_ptr<Group> &parent, const std::shared_ptr<Unit> &child)
{
    parent->removeUnit(child);
    deleteFromSensorSet(child);
}

void EmergencyCenter::addChild(const std::shared_ptr<Unit> & newUnit)
{
    controlUnit->addUnit(newUnit);
    addToSensorSet(newUnit);
}

void EmergencyCenter::removeChild(const std::shared_ptr<Unit> & oldUnit)
{
    controlUnit->removeUnit(oldUnit);
    deleteFromSensorSet(oldUnit);
}

const std::shared_ptr<Unit> EmergencyCenter::findUnit(const std::vector<std::string> &address)
{
    if(address.back()!=centerName) return NULL;
    auto unit = controlUnit->findUnit(address[address.size()-2]);
    if(unit!=NULL){
        for(int index=address.size()-3;index>=0;index--){
            if(unit!=NULL&&unit->isGroup()){
                unit = unit->findUnit(address[index]);
            }else{
                return NULL;
            }
        }
        return unit;
    }else{
        return NULL;
    }
}

void EmergencyCenter::triggered()
{
    controlUnit->triggered();
}

void EmergencyCenter::addToSensorSet(const std::shared_ptr<Unit> & newUnit)
{
    if(!newUnit->isGroup()){
        sensorById.insert(newUnit->getSensor());
        sensorByVendor.insert(newUnit->getSensor());
    }
}

void EmergencyCenter::deleteFromSensorSet(const std::shared_ptr<Unit> &oldUnit)
{
    if(!oldUnit->isGroup()){
        sensorById.erase(oldUnit->getSensor());
        sensorByVendor.erase(oldUnit->getSensor());
    }
}

void EmergencyCenter::overviewById() const
{
    std::cout<<"An overview of all sensors ordered by sensorId:"<<std::endl;
    for(std::set<std::shared_ptr<Sensor>>::iterator i=sensorById.begin();i!=sensorById.end();i++){
        std::cout<<(*i)->getVendor()<<(*i)->getId()<<std::endl;
    }
}

void EmergencyCenter::overviewByVendor() const
{
    std::cout<<"An overview of all sensors ordered by Vendor:"<<std::endl;
    for(std::set<std::shared_ptr<Sensor>>::iterator i=sensorByVendor.begin();i!=sensorByVendor.end();i++){
        std::cout<<(*i)->getVendor()<<(*i)->getId()<<std::endl;
    }
}

EmergencyCenter &EmergencyCenter::operator ++()
{
    ++(*controlUnit);
    return *this;
}

EmergencyCenter &EmergencyCenter::operator --()
{
    --(*controlUnit);
    return *this;
}

