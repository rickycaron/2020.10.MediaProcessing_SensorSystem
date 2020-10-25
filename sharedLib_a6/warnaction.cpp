#include "warnaction.h"

string WarnAction::getWarner() const
{
    return warner;
}

void WarnAction::setWarner(const string &value)
{
    warner = value;
}

WarnAction::WarnAction(string warner):warner(warner){}

void WarnAction::triggered()
{
    cout<<"***!!!Warn "<<warner<<" !***"<<endl;
}
