#ifndef CAR_H
#define CAR_H

#include <iostream>

class Map;

typedef enum class ways {
    left = 0,
    right = 1,
    up = 2,
    down = 3,
}way;

class Car {

    public :
        Car(Map*,std::string);
        void _push(Map*);
        bool isFinish(int[]); // is needed for main loop
        int* getLocale();
        int getCurr_ways();
        void show_move();
        int get_move();
        std::string getName();
        
        
    private :
        int m_locale[2];        // location
        bool m_open_ways[4];    // available moves
        way m_last_move;        //
        int m_CURRENT_WAYS;     // available move number
        std::string name;

    private:
        void set_car_loc(Map*); // needed for constructor (first location)
        void check_ways(Map*);  // configures the next move where it should be
        void lock_back();       // helps car to go ahead
        void reset_checks();    // locks all ways at first 
        void countOpenWay();    // this will be important if I work with decision points
        bool go(way);           // sets car's new location after move
        void save_move(way);    // 

    // redesigned
        void _check_ways(Map*);

};


#endif