#include "monster.h"

Monster::Monster() {}

Monster::Monster(string name):Creature(name) {}

Monster::Monster(string name, int hp_, int atk_, int def_): Creature(name, hp_, atk_, def_){}

Monster::Monster(string name, int hp_, int atk_, int def_,  int sp_): Creature(name, hp_, atk_, def_, sp_) {}

void Monster::attacked(const Creature& enemy) {
    stat.damaged(enemy.get_stat());
}

void Monster::showStatus() const {
    cout<<"Name  "<<name<<"(Monster)"<<endl<<endl;
    cout<<stat;
}