#ifndef SENDACTION_H
#define SENDACTION_H
#include "emergencyaction.h"

class SendAction : public EmergencyAction
{
private:
    string receiver;
    string message;
public:
    SendAction(string,string);
    void triggered();
    string getReceiver() const;
    void setReceiver(const string &value);
    string getMessage() const;
    void setMessage(const string &value);
};

#endif // SENDACTION_H
