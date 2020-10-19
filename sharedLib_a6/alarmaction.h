#ifndef ALARMACTION_H
#define ALARMACTION_H

#include "emergencyaction.h"

class AlarmAction : public EmergencyAction
{
private:
    string alarm;
public:
    AlarmAction(string);
    void triggered();
    string getAlarm();
    void setAlarm(const string &value);
};

#endif // ALARMACTION_H
