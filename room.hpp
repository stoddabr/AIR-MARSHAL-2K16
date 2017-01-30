//header file for room abstract class
//
//Brett Stoddard
//
//
//Created 12/4/16

#ifndef ROOM_CLASS
#define ROOM_CLASS

#include <iostream>
using std::string;

class Room {
    protected:
        string name;
    public:
        Room();
        Room(string name_);
        void set_links (Room* before_, Room* after_, Room* front_, Room* window_);

        virtual void ask_question(int q) = 0;
        virtual int do_action(int a) = 0;
        virtual void prompt_actions() = 0;
        
        void print_moves();     //not used?
        string get_name();      //returns short description ex "cabin"
        
        Room* before;           //pointers to adjacent rooms
        Room* after;
        Room* front;
        Room* window; 
};

#endif
