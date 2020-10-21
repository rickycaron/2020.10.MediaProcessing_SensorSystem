#ifndef WARNACTION_H
#define WARNACTION_H

#include"emergencyaction.h"
class WarnAction: public EmergencyAction
{
private:
    string warner;// warn whom
public:
    WarnAction(string);
    void triggered();
    string getWarner() const;
    void setWarner(const string &value);
};

#endif // WARNACTION_H
