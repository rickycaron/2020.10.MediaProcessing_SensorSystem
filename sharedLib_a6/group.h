#ifndef GROUP_H
#define GROUP_H

#include <set>
#include "unit.h"

class Group : public Unit
{
    using Unit::Unit;
public:
    void addUnit(std::shared_ptr<Unit> newUnit);
    void removeUnit(std::shared_ptr<Unit> oldUnit);
    void triggered() const override;
    //void print() const override;
    //void printChildren() const;
    std::shared_ptr<Unit> findUnit(std::string_view name);
    bool isGroup() const override;
private:
    std::set<std::shared_ptr<Unit>> children;
};

#endif // GROUP_H
