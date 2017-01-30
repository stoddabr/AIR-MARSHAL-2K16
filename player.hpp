//player class header
//
//Brett Stoddard
//created: 12/4/16

#ifndef PLAYER_CLASS
#define PLAYER_CLASS

#include <iostream>
using std::string;
using std::cout;
using std::endl;
using std::string;
#include "room.hpp"


class Player {
    private:
        int held_item;   //1-N7, 2-pillow, 3-peanuts
        string item_name; 
    public:
        Player();
        Player(Room* first);
        void grab_object(int item);
        int get_held_int();
        string get_held_string();
        void set_room(Room* new_r);
        void drop_item();
        Room* current_room;
};

#endif
