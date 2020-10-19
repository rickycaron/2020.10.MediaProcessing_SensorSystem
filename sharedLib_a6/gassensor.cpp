#include "gassensor.h"


GasSensor::GasSensor(SensorType stringtype, string vender, string gastype):Sensor(stringtype,vender),gasType(gastype)
{}

void GasSensor::printAllInformation()
{
    cout<<"Gas sensor to detect "<<gasType<<" ,of id "<<id<<" ,produce by "<<vender<<" is ";
    if(activationState)
        cout<<"active now! ";
    else
        cout<<"not active now! ";
    cout<<endl;
}

string GasSensor::getAllInformation()
{
    std::stringstream sensorInformation;
    sensorInformation <<"Gas sensor to detect "<<gasType<<" ,of id "<<id<<" ,produce by "<<vender<<" is ";
    if(activationState)
       sensorInformation<<"active now! ";
    else
        sensorInformation<<"not active now! ";
    return sensorInformation.str();

}

bool GasSensor::activate()
{
    activationState=true;
    return activationState;
}
