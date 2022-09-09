#ifndef __CREATURE_H__
#define __CREATURE_H__

#include "../stat/stat.h"

class Creature {
protected:
    string name;
    Stat stat;  
public:
    Creature();
    Creature(string name_);
    Creature(string name_, int hp_, int atk_, int def_);
    Creature(string name_, int hp_, int atk_, int def_, int sp);
    Stat get_stat() const;
    virtual void attacked(const Creature& enemy)=0;
    virtual void showStatus() const=0;
};

#endif