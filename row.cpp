//row implementation
//
//Brett Stoddard
//created: 12/4/16
//
#include "row.hpp"
#include <iostream>
using std::string;
using std::cout;
using std::endl;

Row::Row() {
    //null
}
//assign question answers and responses
Row::Row(string name_, string q1answer, string q2answer, 
        string q3answer, string act1response, string act2response, 
        string act1_, string act2_ ){
    name = name_;
    q1ans = q1answer;
    q2ans = q2answer;
    q3ans = q3answer;
    act1resp = act1response;
    act2resp = act2response;
    act1 = act1_;
    act2 = act2_;
}
void Row:: ask_question(int a){
    switch(a){
        case 0:
            cout<< q1ans <<endl;
            break;
        case 1:
            cout<< q2ans <<endl;
            break;
        case 2:
            cout<< q3ans <<endl;
            break;
        default:
            //error message
            cout<< "This shouldn't be seen. row.cpp-ask_question"<<endl;
    }
}
int Row:: do_action(int a){
    switch( a ){
        case 1:
            cout<< act1resp <<endl;
            break;
        case 2:
            cout<< act2resp <<endl;
            break;
        default:
            cout<< "This shouldn't be seen. row.cpp - do_action()"<<endl<<endl;
    }
}
void Row:: prompt_actions(){
    cout << "To "<< act1 <<" input 1"<<endl;
    cout << "To "<< act2 <<" input 2"<<endl;
    cout << "To stare at them and do nothing input 0"<<endl;
}
