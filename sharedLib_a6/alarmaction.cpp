#include "alarmaction.h"
//#include <iostream>


AlarmAction::AlarmAction(string alarm):alarm(alarm)
{

}

void AlarmAction::setAlarm(const string &value)
{
    alarm = value;
}

string AlarmAction::getAlarm()
{
    return alarm;
}

void AlarmAction::triggered(){
 cout<<"***!!!Activating the "<< alarm <<" !***"<<endl;
}
