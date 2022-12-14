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
    virtual Stat get_stat() const;
    virtual int get_power_point() const=0;
    virtual void attacked(const Creature& enemy)=0;
    virtual void show_status() const=0;
    virtual bool is_dead() const=0;
};

#endif