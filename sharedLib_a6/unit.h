#ifndef UNIT_H
#define UNIT_H

#include <memory>
#include <string>

class Unit
{
public:
    Unit(std::shared_ptr<Unit> parent, std::string_view name);
    Unit(std::string_view name);
    void setParent(std::shared_ptr<Unit> value);
    const std::shared_ptr<Unit> & getParent() const;
    virtual void triggered() const;
    //virtual void print() const;
    std::string getUnitName() const {return unitName;};
    bool operator<(const Unit & right)const
        {
            if(this->unitName < right.unitName)
                return true;
            else
                return false;
        }
    virtual bool isGroup() const;

private:
    std::shared_ptr<Unit> unitParent;
    std::string unitName;
};

#endif // UNIT_H
