#include "unit.h"
#include "group.h"
#include <iterator>


void Group::addUnit(std::shared_ptr<Unit> newUnit)
{
    children.insert(newUnit);
}

void Group::removeUnit(std::shared_ptr<Unit> oldUnit)
{
    children.erase(oldUnit);
}

void Group::triggered() const
{
    for(std::set<std::shared_ptr<Unit>>::iterator i=children.begin();i!=children.end();i++){
        std::shared_ptr<Unit> unit = *i;
        unit->triggered();
    }
}

/*void Group::print() const
{

}

void Group::printChildren() const
{

}*/

std::shared_ptr<Unit> Group::findUnit(std::string_view name)
{
    auto iter = children.find(std::make_shared<Unit>(name));
    if(iter!=children.end()){
        return *iter;
    }else{

    }
}

bool Group::isGroup() const
{
    return true;
}
