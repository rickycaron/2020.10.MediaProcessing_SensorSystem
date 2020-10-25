#include <iostream>
#include <memory>
#include "emergencycenter.h"
#include "group.h"
#include "single.h"
#include "factory.h"
#include "alarmaction.h"
#include "warnaction.h"
#include "sendaction.h"

using namespace std;

int main()
{
    //create houses and rooms
    auto center = make_shared<EmergencyCenter>("neighborhood");
    auto V_J_house = make_shared<Group>("Vicky and John’s house");
    auto D_house = make_shared<Group>("Dave's house");
    auto K_house = make_shared<Group>("Kaitlin's house");
    center->setRelation(V_J_house);
    center->setRelation(D_house);
    center->setRelation(K_house);
    auto J_shed = make_shared<Group>("John's shed");
    auto V_kitchen = make_shared<Group>("Vicky's kitchen");
    center->setRelation(V_J_house,J_shed);
    center->setRelation(V_J_house,V_kitchen);
    auto D_livingroom = make_shared<Group>("Dave's living room");
    center->setRelation(D_house,D_livingroom);
    auto K_lab = make_shared<Group>("Kaitlin's lab");
    center->setRelation(K_house,K_lab);

    //create factories
    auto Smokey = make_shared<Factory>("Smokey");
    auto IcanCU = make_shared<Factory>("IcanCU");
    auto BreatheLabs = make_shared<Factory>("BreatheLabs");
    auto BurningInc = make_shared<Factory>("BurningInc");
    auto TN2S = make_shared<Factory>("TN2S");

    //create emergencyActions
    auto alarm_V_J_house = make_shared<AlarmAction>("Vicky and John’s house alarm");
    auto sendToFD = make_shared<SendAction>("a message", "Fire department of the neighborhood");
    auto activateLight = make_shared<AlarmAction>("the light");
    auto turnOnAC = make_shared<SendAction>("an turn on", "the air conditioner");
    auto emailToV = make_shared<SendAction>("an email", "vicky at vicky.cooke@gmail.com");
    auto alarm_D_house = make_shared<AlarmAction>("Dave's house alarm");
    auto alarmSS = make_shared<AlarmAction>("the sprinkler system");
    auto selfAlarm = make_shared<AlarmAction>("alarm");
    auto sendEmail = make_shared<SendAction>("an email", "Kaitlin");

    //create sensors in John's shed
    auto smokeSensor_J_shed = make_shared<Single>("smokeSensor_J_shed", Smokey->createSmokeSensor());
    smokeSensor_J_shed->getSensor()->addEmergrncyAction(alarm_V_J_house);
    smokeSensor_J_shed->getSensor()->addEmergrncyAction(sendToFD);
    center->setRelation(J_shed, smokeSensor_J_shed);

    auto motionSensor_J_shed = make_shared<Single>("motionSensor_J_shed",IcanCU->createMotionSensor(true));
    motionSensor_J_shed->getSensor()->addEmergrncyAction(activateLight);
    motionSensor_J_shed->getSensor()->addEmergrncyAction(turnOnAC);
    center->setRelation(J_shed, motionSensor_J_shed);

    //create sensors in Vicky's kitchen
    auto smokeSensor_V_kitchen = make_shared<Single>("smokeSensor_V_kitchen", Smokey->createSmokeSensor());
    smokeSensor_V_kitchen->getSensor()->addEmergrncyAction(alarm_V_J_house);
    smokeSensor_V_kitchen->getSensor()->addEmergrncyAction(sendToFD);
    center->setRelation(V_kitchen, smokeSensor_V_kitchen);

    tm startTime1 = {0};
    startTime1.tm_hour = 22;
    startTime1.tm_min = 0;
    tm stopTime1 = {0};
    stopTime1.tm_hour = 7;
    stopTime1.tm_min = 0;
    auto motionSensor_V_kitchen = make_shared<Single>("motionSensor_V_kitchen",IcanCU->createMotionSensor(startTime1, stopTime1));
    motionSensor_V_kitchen->getSensor()->addEmergrncyAction(emailToV);
    center->setRelation(V_kitchen, motionSensor_V_kitchen);

    //create sensors in Dave's living room
    auto gasSensor_D_livingroom = make_shared<Single>("gasSensor_D_livingroom", BreatheLabs->createGasSensor("CO"));
    gasSensor_D_livingroom->getSensor()->addEmergrncyAction(alarm_D_house);
    center->setRelation(D_livingroom, gasSensor_D_livingroom);

    auto smokeSensor_D_livingroom = make_shared<Single>("smokeSensor_D_livingroom", BurningInc->createSmokeSensor());
    smokeSensor_D_livingroom->getSensor()->addEmergrncyAction(alarmSS);
    smokeSensor_D_livingroom->getSensor()->addEmergrncyAction(sendToFD);
    center->setRelation(D_livingroom, smokeSensor_D_livingroom);

    //create sensors in Kaitlin's house
    auto gasSensor_K_house = make_shared<Single>("gasSensor_K_house", TN2S->createGasSensor("poison gas"));//the description of scenario 2 didn't mention the gas type
    gasSensor_K_house->getSensor()->addEmergrncyAction(selfAlarm);
    center->setRelation(K_house, gasSensor_K_house);


    //create sensors in Kaitlin's lab
    tm startTime2 = {0};
    startTime2.tm_hour = 4;
    startTime2.tm_min = 40;
    tm stopTime2 = {0};
    stopTime2.tm_hour = 15;
    stopTime2.tm_min = 15;
    auto motionSensor_K_lab = make_shared<Single>("motionSensor_K_lab",IcanCU->createMotionSensor(startTime2,stopTime2));
    motionSensor_K_lab->getSensor()->addEmergrncyAction(sendEmail);
    center->setRelation(K_lab, motionSensor_K_lab);


    //Activate and test the smoke sensor in shed
//    ++(*smokeSensor_J_shed);
//    smokeSensor_J_shed->triggered();

    //An alternative
    //vector<string> address = {"smokeSensor_J_shed","John's shed","Vicky and John’s house","neighborhood"};
    //center->findUnit(address)->getSensor()->activate();
    //center->findUnit(address)->getSensor()->triggered();

    //Activate and test all sensors in Vicky and John’s house
//    ++(*V_J_house);
//    V_J_house->triggered();
//    cout<<"**************************************"<<endl;

    //Test all sensors in the neighborhood
//    center->triggered();
//    cout<<"**************************************"<<endl;

    //Activate all sensors using the ++ operator
    //++(*center);

    //Test the whole neighborhood
//    center->triggered();
//    cout<<"**************************************"<<endl;

    //Test the mad scientist’s house
    //K_house->triggered();
    motionSensor_K_lab->activate();
    motionSensor_K_lab->triggered();
    cout<<*(motionSensor_K_lab->getSensor())<<endl;
    cout<<"**************************************"<<endl;

    //Give an overview of all sensors ordered by id
//    center->overviewById();
    return 0;
}
