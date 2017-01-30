//row header file
//
//Brett stoddard
//created: 12/4/16


#ifndef ROW_CLASS
#define ROW_CLASS

#include "room.hpp"
#include <iostream>
using std::string;

class Row : public Room {
    private:
        string q1ans, q2ans, q3ans, act1resp, act2resp;
        string act1, act2;
        bool is_baby;
    public:
        Row();
        Row(string name, string q1answer, string q2answer, 
            string q3answer, string act1response, 
            string act2response, string act1_, string act2_);
        void ask_question(int a);
        int do_action(int a);
        void prompt_actions();
};

#endif
