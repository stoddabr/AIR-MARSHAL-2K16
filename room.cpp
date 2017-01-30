//room implementation
//
//Brett Stoddard
//Created: 12/4/16

#include "room.hpp"
#include <iostream>
using std::cin;
using std::cout;
using std::string;
using std::endl;

Room:: Room(){
    name = "";
}
Room:: Room( string name_ ){
    name = name_;
}
void Room::set_links(Room* before_, Room* after_, Room* front_, Room* window_){
    before = before_;
    after = after_;
    front = front_;
    window = window_;
}
void Room::print_moves(){
    cout << "To go to the row with the " << before->get_name()<<" input 1"<<endl;
    cout <<"To go to the row with the "<< after->get_name()<< " input 2"<<endl;
    cout <<"To go to the Flight Attendant Cabin input 3"<<endl;
    cout <<"To look out the window input 4"<<endl;
}
string Room::get_name(){
    return name;
}










