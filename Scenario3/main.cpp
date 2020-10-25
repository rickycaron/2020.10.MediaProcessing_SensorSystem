#include <iostream>
#include <memory>
#include "emergencycenter.h"
#include "group.h"
#include "single.h"
#include "factory.h"
using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    //create all sensors
    shared_ptr<Factory> myfactory = make_shared<Factory>("KuLeuven");
    auto motionsensortwix= make_shared<Single>("motion sensor twix galaxy",myfactory->createMotionSensor(true));
    auto gassensorXAE = make_shared<Single>("gas sensor XAE atomosphere", myfactory->createGasSensor("sulphur"));
    auto smokesensorRedstone=make_shared<Single>("smoke sensor Redstone", myfactory->createSmokeSensor());
    auto smokesensorOrangestone=make_shared<Single>("smoke sensor Orangestone", myfactory->createSmokeSensor());
    auto motionsensorLV= make_shared<Single>("motion sensor LV_426 atomosphere",myfactory->createMotionSensor(true));
    auto gassensorLV= make_shared<Single>("gas sensor LV_426 atomosphere",myfactory->createGasSensor("Oxygen"));
    auto smokesensorMoon=make_shared<Single>("smoke sensor Moon", myfactory->createSmokeSensor());
    tm tm1,tm2={0};
    tm1.tm_hour=20;
    tm2.tm_hour=8;
    auto motionsensorMoon=make_shared<Single>("smoke sensor Moon Unit ",myfactory->createMotionSensor(tm1,tm2,10));
    auto smokesensorDweezil=make_shared<Single>("smoke sensor Dweezil", myfactory->createSmokeSensor());
    auto motionensorDweezil=make_shared<Single>("Smoke sensor Dweezil ",myfactory->createMotionSensor(tm1,tm2,10));

    //create all tree, branch,
    //layer1
    auto Disney = make_shared<EmergencyCenter>("Disney");
    auto TwixGalaxy = make_shared<Group>("TwixGalaxy");
    Disney->setRelation(TwixGalaxy);
    //layer2
    auto PlanetXAEA_12 = make_shared<Group>("PlanetXAEA-12");
    auto PlanetLV_426= make_shared<Group>("PlanetLV-426");
    Disney->setRelation(TwixGalaxy,motionsensortwix);
    Disney->setRelation(TwixGalaxy,PlanetXAEA_12);
    Disney->setRelation(TwixGalaxy,PlanetLV_426);
    //layer3
    Disney->setRelation(PlanetXAEA_12,gassensorXAE);
    auto XAEA_12surface = make_shared<Group>("XAEA_12surface");
    Disney->setRelation(PlanetXAEA_12,XAEA_12surface);
    Disney->setRelation(XAEA_12surface,smokesensorRedstone);
    Disney->setRelation(XAEA_12surface,smokesensorOrangestone);
    //layer3, PlanetLV_426
    auto LV_426atmosphere = make_shared<Group>("LV_426 atmosphere");
    Disney->setRelation(PlanetLV_426,LV_426atmosphere);
    Disney->setRelation(LV_426atmosphere,motionsensorLV);
    Disney->setRelation(LV_426atmosphere,gassensorLV);
    auto LV_426surface = make_shared<Group>("LV_426surface");
    Disney->setRelation(PlanetLV_426,LV_426surface);
    auto MoonUnit=make_shared<Group>("Moon Unit");
    Disney->setRelation(LV_426surface,MoonUnit);
    Disney->setRelation(MoonUnit,smokesensorMoon);
    Disney->setRelation(MoonUnit,motionsensorMoon);
    auto Dweezil=make_shared<Group>("Dweezil");
    Disney->setRelation(LV_426surface,Dweezil);
    Disney->setRelation(Dweezil,smokesensorDweezil);
    Disney->setRelation(Dweezil,motionensorDweezil);
    cout<<"Now "<<Sensor::getSensorCount()<<" sensors have been created!"<<endl;









    return 0;
}
