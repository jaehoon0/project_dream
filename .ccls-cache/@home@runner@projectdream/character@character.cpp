#include "character.h"

//예비
Character::Character() {}

//예비
Character::Character(string name): Creature(name) {}

//모든 Character는 이름과 스탯을 가짐
Character::Character(string name, int hp_, int atk_, int def_, int sp_): Creature(name, hp_, atk_, def_, sp_), money(0) {
    if(name=="RICH") {
        money=10000;      
    }
    if(name=="KNIGHT OF THE HAMMER") {
        cout<<"---!!숨겨진 조건 달성!!___"<<endl;
    }
    if(name=="SSOL") {
        cout<<"너구울...?!?"<<endl;
    }
    if(name=="NoNaMe") {
        Stat adminStat(10000, 1000, 1000, 0);
        stat+=adminStat;
    }

    Weapon weapon("dagger", 0, 0, 2, 0);
    Weapon armor("chain-mail", 1, 0, 0, 5);
    set_weapon(weapon);
    set_weapon(armor);
}

void Character::set_weapon(Weapon weapon) {
    weapons[weapon.get_type()]=weapon;
}

void Character::choose_action(Creature& enemy) {
    cout<<"================================================="<<endl;
    cout<<"================================================="<<endl;
    cout<<"원하는 선택지 번호를 입력하십시오"<<endl;
    cout<<"1. "<<"기본 공격"<<endl;
    cout<<"2. "<<"스킬 사용"<<endl;
    cout<<"3. "<<"도망"<<endl;
    cout<<"================================================="<<endl;
    cout<<"================================================="<<endl;

    bool befSelected=true;
    while(befSelected) {
        int selection;
        cin>>selection;
        switch(selection) {
            case 1: 
                enemy.attacked(*this);
                befSelected=false;
                break;
            case 2:
            case 3:
            default:
                cout<<"선택지 번호중에 골라주십시오"<<endl;
                break;
        }
    }
    

}

void Character::acquire_stat(const Stat other) {
    stat+=other;
}

Weapon& Character::get_weapon(int index) {
    return weapons[index-1];
}

int& Character::get_money() {
    return money;
}

Stat Character::get_stat() const {
    Stat statSum=stat+weapons[0].get_stat()+weapons[1].get_stat();
    return statSum;
}
    
void Character::attacked(const Creature& enemy) {
    stat.damaged(enemy.get_stat());
}
void Character::show_status() const {
    cout<<name<<"(Player):"<<endl;    
    //cout<<"TOTAL: "<<endl;
    //cout<<get_stat();    
    cout<<stat;

    weapons[0].show_status();
    weapons[1].show_status();
}

bool Character::is_dead() const{
    return stat.is_dead();
}