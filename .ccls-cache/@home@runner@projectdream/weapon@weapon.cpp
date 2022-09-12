#include "weapon.h"

const string weaponType[2]={"Weapon", "Armor"};

Weapon::Weapon():name("UnKnOwN") {}

Weapon::Weapon(string name_):name(name_) {}
    
Weapon::Weapon(string name_, int type_, int hp_, int atk_, int def_):name(name_), type(type_), typeName(weaponType[type]), stat(hp_, atk_, def_) {}
    
Stat Weapon::get_stat() const {
    return stat;
}

int Weapon::get_type() const {
    return type;
}

void Weapon::acquire_stat(const Stat other) {
    stat+=other;
}

void Weapon::show_status() const {
    cout<<name<<"("<<weaponType[type]<<"): "<<endl;
    cout<<stat;
}