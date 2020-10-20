#ifndef GROUP_H
#define GROUP_H

#include "unitComp.h"
#include <set>
#include <memory>

class Unit;
class Group : public Unit
{
public:
    Group(std::string_view name);
    const std::shared_ptr<Unit> findUnit(const std::string_view name) const override;
    bool isGroup() override{return true;};
    const std::set<std::shared_ptr<Unit>, UnitComp> & getChildren() const {return children;};
    void updateAddress(const std::string & newAddress) override;
    void deleteAddress() override;
    Group & operator ++();
    Group & operator --();
    std::shared_ptr<Sensor> getSensor() override;
    void triggered() override;
    void activate() override;
    void deactivate() override;
    void addUnit(const std::shared_ptr<Unit> & newUnit) override;
    void removeUnit(const std::shared_ptr<Unit> & oldUnit) override;
private:
    std::set<std::shared_ptr<Unit>,UnitComp> children;
};

#endif // GROUP_H

