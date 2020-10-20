#include <QCoreApplication>
#include "mpt67.h"
#include "emergencyaction.h"
#include "alarmaction.h"
#include "sendaction.h"
#include "warnaction.h"
#include "sensor.h"
#include "smokesensor.h"
#include "motionsensor.h"
int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);
    //MPT67 atry;
    //atry.Test();

    //Alarmactionpart
    //AlarmAction alarm1("building alarm");
    std::shared_ptr<AlarmAction> alarm1 =std::make_shared<AlarmAction>("building alarm");
    alarm1->triggered();
    std::shared_ptr<SendAction> send1 =std::make_shared<SendAction>("an email","donny.dhondt@kuleuven.be");
    //SendAction send1("an email","donny.dhondt@kuleuven.be");
    send1->triggered();
    //WarnAction warn1("the police and KULeuven security");
    std::shared_ptr<WarnAction> warn1 =std::make_shared<WarnAction>("the police and KULeuven security");
    warn1->triggered();
    //EmergencyAction * action1 =&alarm1;
    std::shared_ptr<EmergencyAction> action1;
    action1=alarm1;
    action1->triggered();
    action1=send1;
    action1->triggered();

    //Sensor part
    Sensor* senptr;
    SmokeSensor smokesensor1(ST_SmokeSensor,"Sensor Solution");
    senptr=&smokesensor1;
    senptr->addEmergrncyAction(alarm1);
    senptr->addEmergrncyAction(send1);
    senptr->printAllInformation();
    SmokeSensor smokesensor2(ST_SmokeSensor,"KitchenSafe");
    senptr=&smokesensor2;
    senptr->printAllInformation();
    tm t1={0};
    tm t2={0};
    cout<<t1.tm_hour<<endl;
    t1.tm_hour=22;
    cout<<t1.tm_hour<<endl;
    t2.tm_hour=7;
    int restrication1=10;
    MotionSensor motionsensor1(ST_MotionSensor,"GotYou",t1,t2,restrication1);
    motionsensor1.printAllInformation();

//    tm t3={0};
//    cout<<asctime(&t3)<<endl;

//    time_t now=time(0);
//    string dt=ctime(&now);
//    cout<<"now the time is "<<dt<<endl;
//    tm *tmnow=localtime(&now);
//    cout<<"hour "<<tmnow->tm_hour<<" min "<<tmnow->tm_min;
//    dt=asctime(tmnow);
//    cout<<"now the time is "<<dt<<endl;

    motionsensor1.activate();
    motionsensor1.printAllInformation();

    motionsensor1.addEmergrncyAction(alarm1);
    motionsensor1.addEmergrncyAction(send1);
    motionsensor1.addEmergrncyAction(warn1);
    motionsensor1.triggered();
    motionsensor1.removeAllEmergencyAction();
    motionsensor1.triggered();
    cout<<motionsensor1;

    --(*senptr);
    cout<<motionsensor1;










    //return a.exec();
    return 0;
}
