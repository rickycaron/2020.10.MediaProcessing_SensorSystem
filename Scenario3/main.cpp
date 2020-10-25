/*
*******************Media Processing Lab 3*******************************
*******************Group 53E, Team a6*******************************
*******************RUI ZHU*******************************
*******************Scenario 3*******************************
*******************gitlab address*******************************
https://gitlab.groept.be/mediaproc/mp20-team-a6.git
**************************************************
*/
#include <iostream>
#include <memory>
#include "emergencycenter.h"
#include "group.h"
#include "single.h"
#include "factory.h"
#include "alarmaction.h"
#include "sendaction.h"
#include "warnaction.h"
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
    auto motionsensorDweezil=make_shared<Single>("Smoke sensor Dweezil ",myfactory->createMotionSensor(tm1,tm2,10));

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
    auto XAEA_12atomosphere= make_shared<Group>("XAEA_12atomosphere");
    Disney->setRelation(PlanetXAEA_12,XAEA_12atomosphere);
    Disney->setRelation(XAEA_12atomosphere,gassensorXAE);
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
    Disney->setRelation(Dweezil,motionsensorDweezil);
    cout<<"Now "<<Sensor::getSensorCount()<<" sensors have been created!"<<endl;

    //create all emergency action
    auto warnpolice=make_shared<WarnAction>("our peacekeeping force, which you call police");
    auto alarmsulphur=make_shared<AlarmAction>("sulphur alarm");
    auto sendsulphur=make_shared<SendAction>("an elestronic message ","our scientists on the surface ");
    auto alarmmagma=make_shared<AlarmAction>("an array of magmacooling sprinklers");
    auto warnforce=make_shared<WarnAction>("our peacekeeping force and our scientists");
    auto alarmoxygen=make_shared<AlarmAction>("oxygen alarm");
    auto warnfirefighter=make_shared<WarnAction>("our fire fighters");
    auto warnegg=make_shared<WarnAction>("us, the eggs are hatching");

    //add all actions to their sensors
    bool addresult;
    addresult=motionsensortwix->getSensor()->addEmergrncyAction(warnpolice);
    addresult=gassensorXAE->getSensor()->addEmergrncyAction(alarmsulphur);
    addresult=gassensorXAE->getSensor()->addEmergrncyAction(sendsulphur);
    addresult=smokesensorRedstone->getSensor()->addEmergrncyAction(alarmmagma);
    addresult=smokesensorOrangestone->getSensor()->addEmergrncyAction(alarmmagma);
    addresult=motionsensorLV->getSensor()->addEmergrncyAction(warnforce);
    addresult=gassensorLV->getSensor()->addEmergrncyAction(alarmoxygen);
    addresult=smokesensorMoon->getSensor()->addEmergrncyAction(warnfirefighter);
    addresult=motionsensorMoon->getSensor()->addEmergrncyAction(warnegg);
    addresult=smokesensorDweezil->getSensor()->addEmergrncyAction(warnfirefighter);
    addresult=motionsensorDweezil->getSensor()->addEmergrncyAction(warnegg);

    std::cout<<addresult<<std::endl;

    std::cout<<"Question1: "<<std::endl;
    //Activate and test all atomospheric, but leave all other sensors inactive.
    ++(*XAEA_12atomosphere);
    ++(*LV_426atmosphere);
    XAEA_12atomosphere->triggered();
    LV_426atmosphere->triggered();

    std::cout<<"Question2: "<<std::endl;
    //Activate all sensors on X AE A-12, and test all of them
    ++(*PlanetXAEA_12);
    PlanetXAEA_12->triggered();

    std::cout<<"Question3: "<<std::endl;
    //Deactivate all sensors on LV-426 and test. This should not do anything
    --(*PlanetLV_426);
    PlanetLV_426->triggered();

    std::cout<<"Question4.1: "<<std::endl;
    //Reactivate all sensors on LV-426 and test the whole Planet.
    ++(*PlanetLV_426);
    PlanetLV_426->triggered();

    std::cout<<"Question4.2: "<<std::endl;
    //test the Moon Unit
    MoonUnit->triggered();

    std::cout<<"Question4.3: "<<std::endl;
    //test the Dweezil
    Dweezil->triggered();

    std::cout<<"Question5: "<<std::endl;
    //print an overview of all sensors, alphabetically ordered by location
    Disney->overviewByVendor();

    cout<<"You did it! Good job!!!"<<endl;
    cout<<"Thank you~~~"<< endl;
















    return 0;
}
