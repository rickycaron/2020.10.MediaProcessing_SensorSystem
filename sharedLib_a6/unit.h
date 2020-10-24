#ifndef UNIT_H
#define UNIT_H
#include <string>
#include <vector>
#include <memory>

class Sensor;
class Unit
{
public:
    Unit(std::string_view name);
    const std::string & getUnitName() const {return unitName;};
    std::vector<std::string> & getAddress();
    Unit & operator ++();
    Unit & operator --();
    virtual bool isGroup(){return false;};
    virtual void addUnit(const std::shared_ptr<Unit> &);
    virtual void removeUnit(const std::shared_ptr<Unit> &);
    virtual const std::shared_ptr<Unit> findUnit(std::string_view name) const;
    virtual void updateAddress(const std::string & newAddress);
    virtual void deleteAddress();
    virtual void triggered();
    virtual std::shared_ptr<Sensor> getSensor();
    void printAddress();
    virtual void activate();
    virtual void deactivate();
private:
    std::string unitName;
    std::vector<std::string> address;
};

#endif // UNIT_H
