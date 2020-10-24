#include "car.h"
#include "map.h"
#include <stdlib.h>
#include <string>
#include <iostream>

// publics
Car::Car(Map& mapp){
    m_CURRENT_WAYS = 0;
    set_car_loc(mapp);
    for(int i;i<4;i++){
        m_open_ways[i] = 0;
    }
};
void Car::push(Map& m){
    reset_checks();
    check_ways(m);
    countOpenWay();
    lock_back();
    while(true){
        way res = (way)(rand() % 4);
        if(this->m_open_ways[(int)res] == true){
            std::cout << "\nRunning to " << (int)res << "\n";
            if(go(res)){
                std::cout << "Successfully going ahead ! \n";
                m_CURRENT_WAYS = 0;
                save_move(res);
                break;
            }
        }
    }
}
bool Car::isFinish(int ending[]){
    if(m_locale[0] == ending[0] && m_locale[1] == ending[1]){
        return 1;
    }else{return 0;};
};
int* Car::getLocale(){
    return m_locale;
};
Map& Car::getMap(Map& m){
    return m;
}
void cls(void){
    system("cls||clear");
    return;
}


int Car::getCurr_ways(){
    return m_CURRENT_WAYS;
}
// privates ..
bool Car::go(way w){
    int where = (int)w;
    if(where == 0){
        m_locale[1] = m_locale[1] - 1;
        printf("Gone to left\n");
		return true;
    }else if(where == 1){
        m_locale[1] = m_locale[1] + 1;
        printf("Gone to right\n");
		return true;
    }else if(where == 2){
        m_locale[0] = m_locale[0] - 1;
        printf("Gone to top\n");
		return true;
    }else if(where == 3){
        m_locale[0] = m_locale[0] + 1;
        printf("Gone to bottom\n");
		return true;
    }else{
        return false;
    }
}
void Car::lock_back(){
    int l_m = (int)m_last_move;
    if(this->m_CURRENT_WAYS > 1){
        if(l_m == 0){
            this->m_open_ways[1] = 0;
        }else if(l_m == 1){
            this->m_open_ways[0] = 0;
        }else if(l_m == 2){
            this->m_open_ways[3] = 0;
        }else if(l_m == 3){
            this->m_open_ways[2] = 0;
        }
    }
}
void Car::countOpenWay(){
    for(int i=0;i<4;i++){
        if(m_open_ways[i] == 1){
            m_CURRENT_WAYS ++;
        }
    }
}
void Car::reset_checks(){
    for(int i=0;i<4;i++){
        m_open_ways[i] = 0;
    }
}
void Car::check_ways(Map& m){
    if(m.getBlocks(m_locale[0],m_locale[1]-1) == ' '){
        m_open_ways[0] = 1;
    }
    if(m.getBlocks(m_locale[0],m_locale[1]+1) == ' '){
        m_open_ways[1] = 1;
    }
    if(m.getBlocks(m_locale[0]-1,m_locale[1]) == ' '){
        m_open_ways[2] = 1;
    }
    if(m.getBlocks(m_locale[0]+1,m_locale[1]) == ' '){
        m_open_ways[3] = 1;
    }
    if(m_locale[0] == m.get_start_loc()[0] && m_locale[1] == m.get_start_loc()[1]){
        m_open_ways[3] = 0;
    }
}
void Car::save_move(way w){
    this->m_last_move = w;
}
void Car::set_car_loc(Map& m){
    int* starting = m.get_start_loc();
    m_locale[0] = starting[0];
    m_locale[1] = starting[1];
}


