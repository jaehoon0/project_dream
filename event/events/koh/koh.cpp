#include "koh.h"

namespace event {
    void get_enter() {
        char next='n';
        while(next!='\n')
            cin.get(next);
    }
}

Koh::Koh(): Event("Knight of Hammer") {
    ment="당신은 별의 더욱 깊숙한 곳으로 걸음을 옮겼다\n당신은 그곳에서 대장장이와 마주쳤다!!\n대장장이: 깡깡!! 돈만 주시면 어떤 무기든 강화해 드립니다~!~!\n";
}

void Koh::event_start(Character& character) {
    cout << "\x1B[2J\x1B[H";
    cout<<"당신은 별의 더욱 깊숙한 곳으로 걸음을 옮겼다"<<endl;
    event::get_enter();
    cout<<"당신은 그곳에서 대장장이와 마주쳤다!!"<<endl;
    event::get_enter();
    cout<<"대장장이: 깡깡!! 돈만 주시면 어떤 무기든 강화해 드립니다~!~!"<<endl;
    event::get_enter();
    
    character.show_status();
    cout<<"---강화할 무기를 선택하세요---"<<endl;
    cout<<"================================"<<endl;
    cout<<"1. 무기"<<endl;
    cout<<"2. 방어구"<<endl;
    cout<<"================================"<<endl;
    cout<<"숫자를 입력하시오 >> ";
    int index;
    cin>>index;
    if(index>2 || index<1) {
        cout<<"감히 대장장이 앞에서 장난을 치다니!!!"<<endl;
        cout<<"망치로 맞기 전에 썩 꺼지거라 이노옴!!"<<endl;
        cout<<"(당신은 서둘러 도망쳐 나왔다)"<<endl;
        event::get_enter();        
    }
    else {
        Weapon& weapon=character.get_weapon(index);
        int& money=character.get_money();

        if(money==0) {
            cout<<"하지만 당신에겐 동전 한푼 없었다..."<<endl;
            event::get_enter();       
            cout<<"당신은 아쉬운 발걸음을 돌렸다"<<endl;
            event::get_enter();
            return;
        }
        
        int pay=0;

        while(true) {
            cout<<"--- 지불할 금액을 입력하세요. (보유금액: "<<money<<") ---"<<endl;
            cin>>pay;
            if(pay<=money) break;
            cout<<"돈이 부족하잖아!! 깡깡!!"<<endl;
            event::get_enter();
        }
        money-=pay;
        
        if(index==1) {
            Stat upgrade(0, pay/10, pay/100);
            weapon.acquire_stat(upgrade);
            if(pay/10==0) {
                cout<<"헤헿 실패했네. 다음엔 돈을 더 많이 들고 와. 미안~~~"<<endl;
                event::get_enter();
                cout<<"대장장이는 눈 깜짝할 사이에 사라져 버렸다"<<endl;
                event::get_enter();
                cout<<"저런 돌팔이쉨..."<<endl;
                event::get_enter();
            }
            else {
                cout<<"후...강화에 성공했어"<<endl;
                event::get_enter();
                cout<<"한번 살펴볼래??"<<endl;
                event::get_enter();
                weapon.show_status();
                cout<<"ATK는 "<<pay/10<<", DEF는 "<<pay/100<<" 증가했어"<<endl;
                event::get_enter();
            }
        }
        else {
            Stat upgrade(0, pay/100, pay/10);
            weapon.acquire_stat(upgrade);
            if(pay/10==0) {
                cout<<"헤헿 실패했네. 다음엔 돈을 더 많이 들고 와. 미안~~~"<<endl;
                event::get_enter();
                cout<<"대장장이는 눈 깜짝할 사이에 사라져 버렸다"<<endl;
                event::get_enter();
                cout<<"저런 돌팔이쉨..."<<endl;
                event::get_enter();
            }
            else {
                cout<<"후...강화에 성공했어"<<endl;
                event::get_enter();
                cout<<"한번 살펴볼래??"<<endl;
                event::get_enter();
                weapon.show_status();
                cout<<"ATK는 "<<pay/100<<", DEF는 "<<pay/10<<" 증가했어"<<endl;
                event::get_enter();
            }
        }
        
    }    
}