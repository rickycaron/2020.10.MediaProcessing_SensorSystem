#include <iostream>
#include <memory>
#include "emergencycenter.h"
#include "group.h"
#include "single.h"
#include "factory.h"

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

    //create sensors
    auto smokeSensor1 = make_shared<Single>("smokeSensor1", Smokey->createSmokeSensor());
    auto motionSensor1 = make_shared<Single>("motionSensor1",IcanCU->createMotionSensor(true));
    center->setRelation(J_shed, smokeSensor1);
    center->setRelation(J_shed, motionSensor1);

    tm tm1 = {0};
    tm1.tm_hour = 22;
    tm tm2 = {0};
    tm2.tm_hour = 7;
    auto smokeSensor2 = make_shared<Single>("smokeSensor2", Smokey->createSmokeSensor());
    auto motionSensor2 = make_shared<Single>("motionSensor2",IcanCU->createMotionSensor(tm1, tm2));
    center->setRelation(V_kitchen, smokeSensor2);
    //center->setRelation(V_kitchen, motionSensor2);

    auto gasSensor1 = make_shared<Single>("gasSensor1", BreatheLabs->createGasSensor("CO"));
    auto smokeSensor3 = make_shared<Single>("smokeSensor3", BurningInc->createSmokeSensor());
    center->setRelation(D_livingroom, gasSensor1);
    center->setRelation(D_livingroom, smokeSensor3);

    auto gasSensor2 = make_shared<Single>("gasSensor2", TN2S->createGasSensor("poison gas"));//the description of scenario 2 didn't mention the gas type
    //auto motionSensor3 = make_shared<Single>("motionSensor3",IcanCU->createMotionSensor())
    center->setRelation(K_lab, gasSensor2);
    //center->setRelation(K_lab, motionSensor3);

    //std::vector<std::string> address = {"","",};
    std::cout<<*(gasSensor1->getSensor())<<std::endl;
    return 0;
}
