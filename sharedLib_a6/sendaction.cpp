#include "sendaction.h"

SendAction::SendAction(string message, string receiver) :receiver(receiver),message(message){}

void SendAction::triggered()
{
    cout<<"Send "<<message<<" to "<<receiver<<"!"<<endl;
}



void SendAction::setReceiver(const string &value)
{
    receiver = value;
}

string SendAction::getMessage() const
{
    return message;
}

void SendAction::setMessage(const string &value)
{
    message = value;
}

string SendAction::getReceiver() const
{
    return receiver;
}
