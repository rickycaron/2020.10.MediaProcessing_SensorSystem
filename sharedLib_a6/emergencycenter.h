#ifndef EMERGENCYCENTER_H
#define EMERGENCYCENTER_H
#include <string>
#include <memory>
#include <vector>
#include <set>
#include "sensorCompById.h"
#include "sensorCompByVendor.h"
#include "unit.h"
#include "group.h"

class Sensor;
class EmergencyCenter
{
public:
    EmergencyCenter();
    EmergencyCenter(std::string_view name);
    void setRelation(const std::shared_ptr<Unit> & newUnit);
    void resetRelation(const std::shared_ptr<Unit> & oldUnit);
    void setRelation(const std::shared_ptr<Group> & parent,const std::shared_ptr<Unit> & child);
    void resetRelation(const std::shared_ptr<Group> & parent,const std::shared_ptr<Unit> & child);
    const std::shared_ptr<Unit> findUnit(const std::vector<std::string> & address);
    void triggered();
    void addToSensorSet(const std::shared_ptr<Unit> & newUnit);
    void deleteFromSensorSet(const std::shared_ptr<Unit> & oldUnit);
    void overviewById() const;
    void overviewByVendor() const;
    EmergencyCenter & operator ++();
    EmergencyCenter & operator --();
private:
    std::string centerName;
    std::unique_ptr<Group> controlUnit;
    std::set<std::shared_ptr<Unit>,sensorCompById> sensorById;
    std::set<std::shared_ptr<Unit>,sensorCompByVendor> sensorByVendor;
};

#endif // EMERGENCYCENTER_H
