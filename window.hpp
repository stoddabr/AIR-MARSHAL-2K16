//window header file
//
//Brett Stoddard
//created 12/4/16



#ifndef WINDOW_CLASS
#define WINDOW_CLASS

#include "room.hpp"
#include <iostream>
using std::string;

class Window: public Room {
    private:
        int start_time;
        int current_time;
    public:
        Window();
        Window(int start);
        void ask_question(int a);
        int do_action(int a);
        void prompt_actions();
        int get_start_time();
};

#endif
