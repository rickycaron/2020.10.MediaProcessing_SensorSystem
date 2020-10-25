#ifndef SENSOR_H
#define SENSOR_H
#include "emergencyaction.h"
#include <iostream>
#include <vector>
#include <iterator>
#include <utility>
#include <sstream>
#include <memory>
using namespace std::rel_ops;

enum SensorType{ST_Undefined,ST_SmokeSensor,ST_MotionSensor,ST_GasSensor};

class Sensor
{
protected:
    static int sensorCount;
    static int sensorUniqCount;
    int id = 0;//automatically generated
    SensorType sensorType=ST_Undefined;// initialized when created
    string vendor;
    bool activationState=false;
    //EmergencyAction * emergencyActions = nullptr;
    vector < shared_ptr<EmergencyAction> > emergencyActions;

public:

    Sensor(SensorType,string);
    ~Sensor();
//    static Sensor* CreateSensor(SensorType,string); // It seems not necessary
    virtual bool activate()=0;
    void deactivate();
    void triggered();
    Sensor& operator ++();//prefix increment
    //Sensor operator++(int);  //post increment operator
    Sensor& operator--();
    //Sensor operator--(int);

    bool addEmergrncyAction(shared_ptr<EmergencyAction>);
    bool removeAllEmergencyAction();
    virtual void printAllInformation()=0;
    virtual string getAllInformation()=0;

    static int getSensorCount();
    static void setSensorCount(int value);
    static int getSensorUniqCount();
    static void setSensorUniqCount(int value);
    int getId() const;
    string getVendor() const;
    bool getActivationState() const;
};

ostream&  operator<<(ostream &os, Sensor &sensor);

#endif // SENSOR_H
