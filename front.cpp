//front implementation file
//
//Brett Stoddard
//created: 12/4/16

#include <iostream>
using std::string;
using std::endl;
using std::cout;
#include "front.hpp"

Front:: Front(){
    name = "cabin";
}
void Front::ask_question(int a){
}
//return: 22 grab pillow, 33 grab peanuts, 44 throw 
int Front::do_action(int a){
    switch ( a ){
        case 1:
            cout<<"You reach for the pillow"<<endl;
            return 1;
            break;
        case 2:
            cout<<"You reach for the peanuts"<<endl;
            return 2;
            break;
        case 3:
            return 3;
            break;
        default:
            cout<<"This should never be seen. front.cpp - do_action()"<<endl;
    }
    return 0;           //error
}
void Front::prompt_actions(){
    cout<<"This is a normal cockpit, there are pillows, peanuts, and a bomb proof container"<<endl<<endl;
    cout<<"To throw whatevers in your hand into the bomb proof container input 1"<<endl;
    cout<<"To grab pillow input 2"<<endl;
    cout<<"To grab bag of peanuts input 3"<<endl;
    cout<<"To move down to the first row input 0"<<endl;
}
void Front::prompt_questions(){
    //null
}


