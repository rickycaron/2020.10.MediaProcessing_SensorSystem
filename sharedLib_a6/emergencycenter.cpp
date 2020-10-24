#include "emergencycenter.h"
#include "unit.h"
#include "group.h"
#include <iostream>

EmergencyCenter::EmergencyCenter():
    centerName{"defaultCenter"}
{
    controlUnit = std::make_unique<Group>("defaultCenter");
}

EmergencyCenter::EmergencyCenter(std::string_view name):
    centerName{name}
{
    controlUnit = std::make_unique<Group>(centerName);
}

void EmergencyCenter::setRelation(const std::shared_ptr<Group> & parent,const std::shared_ptr<Unit> & child)
{
    if(findUnit(parent->getAddress())!=NULL){
        parent->addUnit(child);
        addToSensorSet(child);
    }else{
        std::cout<<parent->getUnitName()<<" doesn't belong to this center."<<std::endl;
    }
}

void EmergencyCenter::resetRelation(const std::shared_ptr<Group> &parent, const std::shared_ptr<Unit> &child)
{
    if(findUnit(parent->getAddress())==NULL){
        std::cout<<parent->getUnitName()<<" doesn't belong to this center."<<std::endl;
    }else if(parent->findUnit(child->getUnitName())==NULL){
        std::cout<<child->getUnitName()<<" doesn't belong to "<<parent->getUnitName()<<"."<<std::endl;
    }else{
        parent->removeUnit(child);
        deleteFromSensorSet(child);
    }
}

void EmergencyCenter::setRelation(const std::shared_ptr<Unit> & newUnit)
{
    controlUnit->addUnit(newUnit);
    addToSensorSet(newUnit);
}

void EmergencyCenter::resetRelation(const std::shared_ptr<Unit> & oldUnit)
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
        sensorById.insert(newUnit);
        sensorByVendor.insert(newUnit);
    }
}

void EmergencyCenter::deleteFromSensorSet(const std::shared_ptr<Unit> &oldUnit)
{
    if(!oldUnit->isGroup()){
        sensorById.insert(oldUnit);
        sensorByVendor.insert(oldUnit);
    }
}

void EmergencyCenter::overviewById() const
{
    std::cout<<"An overview of all sensors ordered by sensorId"<<std::endl;
    for(auto i=sensorById.begin();i!=sensorById.end();i++){
        (*i)->printAddress();
        std::cout<<(*i)->getSensor()->getAllInformation()<<std::endl;
    }
}

void EmergencyCenter::overviewByVendor() const
{
    std::cout<<"An overview of all sensors ordered by Vendor:"<<std::endl;
    for(auto i=sensorByVendor.begin();i!=sensorByVendor.end();i++){
        (*i)->printAddress();
        std::cout<<(*i)->getSensor()->getAllInformation()<<std::endl;
    }
}

EmergencyCenter &EmergencyCenter::operator ++()
{
    controlUnit->activate();
    return *this;
}

EmergencyCenter &EmergencyCenter::operator --()
{
    controlUnit->deactivate();
    return *this;
}
