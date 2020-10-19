#ifndef EMERGENCYCENTER_H
#define EMERGENCYCENTER_H

#include <memory>
#include <string>
#include <set>

class Unit;
class EmergencyCenter
{
public:
    EmergencyCenter(std::string_view name);
    void addUnit(std::shared_ptr<Unit> newUnit);
    void removeUnit(std::shared_ptr<Unit> oldUnit);
    void triggered() const;
    void overview() const;
private:
    std::string centerName;
    std::set<std::shared_ptr<Unit>> units;
};

#endif // EMERGENCYCENTER_H
