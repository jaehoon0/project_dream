#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include "../creature/creature.h"
#include "../weapon/weapon.h"

class Character:public Creature {
private:
    Weapon weapons[2];
    int money;

public:
    Character();
    Character(string name);
    Character(string name, int hp_, int atk_, int def_,  int sp_);
    void set_weapon(Weapon weapon);
    int choose_action(Creature& enemy);
    void acquire_stat(const Stat other);
    Weapon& get_weapon(int index);
    int& get_money();
    void show_detail_status() const;
    virtual Stat get_stat() const;
    virtual void attacked(const Creature& enemy);
    virtual void show_status() const;
    virtual bool is_dead() const;
};

#endif