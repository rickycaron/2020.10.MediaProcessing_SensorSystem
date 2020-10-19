#ifndef EMERGENCYACTION_H
#define EMERGENCYACTION_H
#include <iostream>
#include <string>

using namespace std;

class EmergencyAction
{
public:
    EmergencyAction();
    virtual void triggered()=0;
};

#endif // EMERGENCYACTION_H
