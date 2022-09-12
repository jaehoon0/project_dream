#ifndef __WEAPON_H__
#define __WEAPON_H__

#include "../stat/stat.h"

class Weapon {
private:
    string name;
    Stat stat;
    int type;
    string typeName;
public:
    Weapon();
    Weapon(string name_);
    Weapon(string name_, int type_, int hp_, int atk_, int def_);
    Stat get_stat() const;
    int get_type() const;
    void acquire_stat(const Stat other);
    void show_status() const;
};

#endif