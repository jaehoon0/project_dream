#ifndef __MONSTER_H__
#define __MONSTER_H__

#include "../creature/creature.h"

class Monster:public Creature {
public:
    Monster();
    Monster(string name);
    Monster(string name, int hp_, int atk_, int def_);
    Monster(string name, int hp_, int atk_, int def_,  int sp_);
    virtual Stat get_stat() const;
    virtual void attacked(const Creature& enemy);
    virtual void show_status() const;
    virtual bool is_dead() const;
};

#endif