//player class implementation
//
//Brett Stoddard
//created: 12/4/16

#include <iostream>
using std::endl;
using std::string;
using std::cout;
#include "player.hpp"

Player::Player(){
    //not used
}
Player::Player(Room* first){
    held_item = 0;
    item_name = "";
    current_room = first; 
}
void Player:: grab_object(int item){
    if ( held_item == 0 || item ==0 ){  //hand empty
        held_item = item; 
        switch( item ){
            case 0:             //used for dropping/giving something
                item_name = "";
                break;
            case 1:
                item_name = "Samsung Note 7";
                break;
            case 2:
                item_name = "pillow";
                break;
            case 3:
                item_name = "peanuts";
                break;
            default:
                cout<<"this shouldn't be seen. player.cpp-grab_object()"<<endl;
        }
        if ( held_item != 0){   //dont print when item is dripped/given
            cout<< "You grab the " <<item_name<<endl;
        }
    } else {    //item already in hand
        cout << "You already are holding a "<< item_name << ". Remember your training says to always keep one hand unoccupied in case the situation goes South."<<endl;
        cout << "If you want to drop the item in your hand, run back up to the cabin and drop it into the bomb box. It's big enough. You shouldn't be littering all over the plane and no one's going to want something you've already touched anyways"<<endl; 
    }     
}
void Player::set_room(Room* new_r){
    current_room = new_r;
}
void Player::drop_item(){
    held_item = 0;
    item_name = "";
}
int Player::get_held_int(){
    return held_item;
}
string Player::get_held_string(){
    return item_name;
}


