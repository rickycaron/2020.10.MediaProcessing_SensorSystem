#include "motionsensor.h"

MotionSensor::MotionSensor(SensorType stringtype, string vendor):Sensor(stringtype,vendor){
    permenateActive=true;
}

MotionSensor::MotionSensor(SensorType stringtype, string vendor,tm activetime,tm deactivetime):Sensor(stringtype,vendor),activationTime(activetime),deactivationTime(deactivetime){}

MotionSensor::MotionSensor(SensorType stringtype, string vendor,bool permenentactive):Sensor(stringtype,vendor),permenateActive(permenentactive){}

MotionSensor::MotionSensor(SensorType stringtype, string vendor,tm activetime,tm deactivetime,int restrication):Sensor(stringtype,vendor),activationTime(activetime),deactivationTime(deactivetime),restrication(restrication){}

void MotionSensor::printAllInformation()
{
    cout<<"Motion sensor to detect of id "<<id<<" ,produce by "<<vendor<<" is ";
    if(permenateActive) cout<<"permenate acitve ,";
    else if (activationTime.tm_hour!= deactivationTime.tm_hour && activationTime.tm_hour!=0)
    {
        cout<<"active from "<< activationTime.tm_hour<<":"<<activationTime.tm_min;
        cout<<" to "<<deactivationTime.tm_hour<<" : "<<deactivationTime.tm_min<<" ,";
    }
    if(!restrication) cout<<"has a restricaiton of "<<restrication<<" meters";
    if(activationState)
        cout<<"is active now! ";
    else
        cout<<"is not active now! ";
    cout<<endl;
}

string MotionSensor::getAllInformation()
{
    std::stringstream sensorInformation;
    sensorInformation <<"Motion sensor to detect of id "<<id<<" ,produce by "<<vendor<<" is ";
    if(permenateActive) sensorInformation<<"permenate acitve ,";
        else if (activationTime.tm_hour!= deactivationTime.tm_hour && activationTime.tm_hour!=0)
        {
            sensorInformation<<"active from "<< activationTime.tm_hour<<":"<<activationTime.tm_min<<" to "<<deactivationTime.tm_hour<<" : "<<deactivationTime.tm_min<<" ,";
        }
        if(!restrication) sensorInformation<<"has a restricaiton of "<<restrication<<" meters";
        if(activationState)
            sensorInformation<<"is active now! ";
        else
            sensorInformation<<"is not active now! ";
    return sensorInformation.str();

}

bool MotionSensor::activate()
{
    activationState=checktime();
    return activationState;
}

void MotionSensor::deactive()
{
    activationState=false;
}

bool MotionSensor::checktime()
{
    if(permenateActive){return true;}
    else if(activationTime.tm_hour == deactivationTime.tm_hour && activationTime.tm_min==deactivationTime.tm_min)
        {
        cout<<"Wong activation and deactivation time for motion sensor of id "<<id<<"endl";
        return false;;
        }
    else
    {
        time_t now=time(0);
        tm *tmnow=localtime(&now);
        int hournow=tmnow->tm_hour;
        int minnow=tmnow->tm_min;
        if(activationTime.tm_hour > deactivationTime.tm_hour)
        {
            if(hournow > activationTime.tm_hour ||( (hournow == activationTime.tm_hour) && (minnow > activationTime.tm_min)))
                return true;
            else if(hournow<deactivationTime.tm_hour||(hournow==deactivationTime.tm_hour &&minnow <= activationTime.tm_min))
                return true;
        }
        else if (activationTime.tm_hour < deactivationTime.tm_hour)
        {
            if(hournow > activationTime.tm_hour && hournow<activationTime.tm_hour)
                return true;
            else if (hournow==activationTime.tm_hour && tmnow->tm_min >= activationTime.tm_min)
                return true;
            else if(hournow==deactivationTime.tm_hour && tmnow->tm_min <=deactivationTime.tm_min)
                return true;
        }
        else if(activationTime.tm_hour == deactivationTime.tm_hour)
        {
            if (hournow==activationTime.tm_hour && tmnow->tm_min >= activationTime.tm_min && tmnow->tm_min <= deactivationTime.tm_min)
                return true;
        }
        else
            return false;
    }
}
