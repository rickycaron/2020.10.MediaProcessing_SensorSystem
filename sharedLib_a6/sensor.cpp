#include "sensor.h"

int Sensor::sensorCount = 0;
int Sensor::sensorUniqCount = 0;

void Sensor::setSensorCount(int value)
{
    sensorCount = value;
}

int Sensor::getSensorUniqCount()
{
    return sensorUniqCount;
}

void Sensor::setSensorUniqCount(int value)
{
    sensorUniqCount = value;
}

int Sensor::getSensorCount()
{
    return sensorCount;
}


int Sensor::getId() const
{
    return id;
}

string Sensor::getVendor() const
{
    return vendor;
}

bool Sensor::getActivationState() const
{
    return activationState;
}

Sensor::Sensor(SensorType sensortype, string vender): sensorType(sensortype),vendor(vender)
{
    Sensor::sensorCount++;
    Sensor::sensorUniqCount++;
    id=Sensor::sensorUniqCount;
    //emergencyActions = new (EmergencyAction *)[3]; here is some problem
}

Sensor::~Sensor()
{
    Sensor::sensorCount--;
}

void Sensor::deactivate()
{
    activationState=false;
}

void Sensor::triggered()
{
    if(!activationState)
        return;
    for(int i = 0 ; i < int(emergencyActions.size());i++)
    {
      emergencyActions[i]->triggered();
    }
}

Sensor &Sensor::operator ++()
{
    this->activate();
    return *this;
}

Sensor &Sensor::operator--()
{
    this->deactivate();
    return *this;
}

bool Sensor::addEmergrncyAction(shared_ptr<EmergencyAction> emergencyaction)
{
    shared_ptr<EmergencyAction> newEmergencyAction(emergencyaction);
    vector<shared_ptr<EmergencyAction>>::iterator eaptr;
    for(eaptr= emergencyActions.begin(); eaptr != emergencyActions.end(); eaptr++)
    {
        //make sure there is no emergencyAction duplicate
        if( (*eaptr).get() == newEmergencyAction.get()){
            std::cout<<"This method has been added to the sensor of id"<<id<<endl;
            return false;
        }
    }
    emergencyActions.push_back(newEmergencyAction);
    return true;
}

bool Sensor::removeAllEmergencyAction()
{
    emergencyActions.clear();
    return true;
}

ostream&  operator<<(ostream &os, Sensor &sensor)
{
    os << sensor.getAllInformation() << std::endl;
    return os;
}

