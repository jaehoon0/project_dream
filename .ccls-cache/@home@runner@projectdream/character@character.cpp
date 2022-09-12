#include "character.h"

namespace character {
    void get_enter() {
        char next='n';
        while(next!='\n')
            cin.get(next);
    }
}

//예비
Character::Character() {}

//예비
Character::Character(string name): Creature(name) {}

//모든 Character는 이름과 스탯을 가짐
Character::Character(string name, int hp_, int atk_, int def_, int sp_): Creature(name, hp_, atk_, def_, sp_), money(100) {
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

int Character::choose_action(Creature& enemy) {
    cout<<"================================================="<<endl;
    cout<<"================================================="<<endl;
    cout<<"원하는 선택지 번호를 입력하십시오"<<endl;
    cout<<"0. "<<"내 정보 상세보기"<<endl;
    cout<<"1. "<<"기본 공격"<<endl;
    cout<<"2. "<<"스킬 사용"<<endl;
    cout<<"3. "<<"도망"<<endl;
    cout<<"================================================="<<endl;
    cout<<"================================================="<<endl;

    bool befSelected=true;
    int selection;
    while(befSelected) {
        cin>>selection;
        switch(selection) {
            case 0:
                show_detail_status();
                cout<<"(---스토리를 진행하시려면 Enter를 눌러주세요---)"<<endl;
                cin.ignore();
                character::get_enter();
                befSelected=false;
                break;
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
    return selection;
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

void Character::show_detail_status() const {
    cout<<name<<"(Player):"<<endl;
    cout<<"보유 코인: "<<money<<endl;
    cout<<stat;

    weapons[0].show_status();
    weapons[1].show_status();
}

Stat Character::get_stat() const {
    Stat statSum=stat+weapons[0].get_stat()+weapons[1].get_stat();
    return statSum;
}

int Character::get_power_point() const {
    return stat.cal_power();
}
    
void Character::attacked(const Creature& enemy) {
    int damage;
    damage=stat.damaged(enemy.get_stat());
    cout<<name<<"은 "<<damage<<"의 피해를 입었다..!!"<<endl;
    character::get_enter();
}
void Character::show_status() const {
    cout<<name<<"(Player):"<<endl;    
    Stat tempStat(0, 0, 0);
    tempStat=stat;
    tempStat+=weapons[0].get_stat();
    tempStat+=weapons[1].get_stat();

    cout<<tempStat;
}

bool Character::is_dead() const{
    return stat.is_dead();
}