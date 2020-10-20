#include <iostream>
#include "unit.h"
#include "group.h"
#include "single.h"
#include "emergencycenter.h"
#include "sensor.h"
#include "sensorCompById.h"
#include "sensorCompByVendor.h"

int main()
{
    auto center = std::make_shared<EmergencyCenter>();
    auto group1 = std::make_shared<Group>("group1");
    auto single1 = std::make_shared<Single>("single1");
//    auto group2 = std::make_shared<Group>("group2");
//    auto group3 = std::make_shared<Group>("group3");
//    auto single2 = std::make_shared<Single>("single2");


    center->setRelation(group1,single1);
//    center->setRelation(group1,group2);
    center->addChild(group1);

    ++(*center);
//    center->addChild(group3);
//    center->setRelation(group2,single2);

//    std::cout<<"First: "<<std::endl;
//    for(unsigned int i=0;i<single2->getAddress().size();i++){
//        std::cout<<single2->getAddress()[i]<<std::endl;
//    }

//    if(center->findUnit(group2->getAddress())!=NULL){
//        std::cout<<"Find out."<<std::endl;
//    }else{
//        std::cout<<"Cannot find out."<<std::endl;
//    }

//    center->resetRelation(group1,group2);
//    std::cout<<"Second: "<<std::endl;
//    for(unsigned int i=0;i<single2->getAddress().size();i++){
//        std::cout<<single2->getAddress()[i]<<std::endl;
//    }

//    center->setRelation(group1,group2);
//    std::cout<<"Third: "<<std::endl;
//    for(unsigned int i=0;i<single2->getAddress().size();i++){
//        std::cout<<single2->getAddress()[i]<<std::endl;
//    }

//    auto sensor1 = std::make_shared<Sensor>(1,"a");
//    auto sensor2 = std::make_shared<Sensor>(2,"c");
//    auto sensor3 = std::make_shared<Sensor>(3,"b");
//    auto sensor4 = std::make_shared<Sensor>(4,"b");
//    auto single1 = std::make_shared<Single>("single1");
//    auto single2 = std::make_shared<Single>("single2");
//    auto single3 = std::make_shared<Single>("single3");
//    auto single4 = std::make_shared<Single>("single4");
//    single1->setSensor(sensor1);
//    single2->setSensor(sensor2);
//    single3->setSensor(sensor3);
//    single4->setSensor(sensor4);
//    std::set<std::shared_ptr<Sensor>,sensorCompById> sensors;
//    sensors.insert(sensor3);
//    sensors.insert(sensor2);
//    sensors.insert(sensor4);
//    sensors.insert(sensor1);
//    auto center = std::make_shared<EmergencyCenter>();
//    auto group1 = std::make_shared<Group>("group1");
//    auto group2 = std::make_shared<Group>("group2");
//    center->setRelation(group1,single1);
//    center->setRelation(group2,single2);
//    center->setRelation(group1,single3);
//    center->setRelation(group1,single4);
//    center->addChild(group1);
//    center->setRelation(group1,group2);
//    center->overviewById();
//    center->overviewByVendor();

}
