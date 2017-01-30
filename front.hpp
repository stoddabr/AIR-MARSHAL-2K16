//header file front
//
//Brett Stoddard
//created: 12/4/16


#ifndef FRONT_CLASS
#define FRONT_CLASS

#include <iostream>
using std::string;
#include "room.hpp"

class Front: public Room{
    private:
        bool asked_inventory;
    public:
        Front(); void ask_question(int a); int do_action(int a); void prompt_actions(); void prompt_questions();

};

#endif
