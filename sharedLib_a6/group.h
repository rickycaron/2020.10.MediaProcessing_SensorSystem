#ifndef GROUP_H
#define GROUP_H

#include "unit.h"
#include "unitComp.h"
#include <set>
#include <memory>

class Group : public Unit
{
    using Unit::Unit;
public:
    void triggered() override;
    void addUnit(const std::shared_ptr<Unit> & newUnit);
    void removeUnit(const std::shared_ptr<Unit> & oldUnit);
    const std::shared_ptr<Unit> findUnit(const std::string_view name) const override;
    bool isGroup() override{return true;};
    const std::set<std::shared_ptr<Unit>, UnitComp> & getChildren() const {return children;};
    void updateAddress(const std::string & newAddress) override;
    void deleteAddress() override;
    void operator ++() override;
    void operator --() override;
private:
    std::set<std::shared_ptr<Unit>,UnitComp> children;
};

#endif // GROUP_H

