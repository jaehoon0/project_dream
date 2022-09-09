#include "character.h"

//예비
Character::Character() {}

//예비
Character::Character(string name): Creature(name) {}

//모든 Character는 이름과 스탯을 가짐
Character::Character(string name, int hp_, int atk_, int def_, int sp_): Creature(name, hp_, atk_, def_, sp_) {}
    
void Character::attacked(const Creature& enemy) {
    //수정 필요
    stat.damaged(enemy.get_stat());
}
void Character::showStatus() const {
    cout<<"Name  "<<name<<"(Player)"<<endl<<endl;
    cout<<stat;
}