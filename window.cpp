//window implementation file
//
//Brett Stoddard
//created: 12/4/16

#include <ctime>
#include <iostream>
using std::cout;
using std::endl;
using std::string;
#include "window.hpp"

Window::Window(int start){
    start_time = start;
    current_time = 0;
    name = "window"; 
}
void Window::ask_question(int a){
    current_time = time(NULL) - start_time;

    int total_time = 60*15;     //20 minutes to find the phone
    cout << "Looking out the window you use triangulation between landmarks to estimate how much time you have before the plane lands"<<endl;
    cout << "You have "<< ( total_time - current_time )/60 << " minutes left"<<endl;  
}
int Window::do_action(int a){
    ask_question(a);
    return 0;
}
void Window::prompt_actions(){
    //null
}
int Window::get_start_time(){
    return start_time;
}
