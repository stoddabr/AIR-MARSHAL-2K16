//main game file
//
//Brett stoddard
//created 12/4/16

#include <ctime>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;

#include "room.hpp"
#include "row.hpp"
#include "window.hpp"
#include "front.hpp"
#include "player.hpp"

int intput(int max);    //input validation for ints, max != 0
void pause();           //used between inputs to create dramatic effect
void fail();            //failure message
int game();            //game function, recourses until game is done
void prompt_approved_questions(); //prompts the questions that you can ask people

int main(){
    //includes the welcomer and a tutorial-ish thing
    //the calls the main game function
    cout <<"(Pssst the baby in the third row has the phone you're looking for)" << endl;
    cout <<"(You need to give the nanny a pillow to get it)" << endl;
    pause();
    pause();
    pause();
    cout<< "\"Welcome recruit, to the prestigious sky marshal program\""<<endl;
    pause();
    cout<< "\"I know that training hasn't always been easy but you made it through the academy with honors\""<<endl;
    pause();
    cout<< "\"Now for your first assignment you will be aboard a short flight from LAX to San Diego\"" <<endl;
    pause();
    cout <<"\"Since this is your first solo flight, don't mess things up\""<<endl;
    pause();
    cout<<endl<<"To board the plane input 1"<<endl;
    cout<<"To exit the game input 0"<<endl;
    int starter = intput(1);
    switch (starter){
        case 0:
        //exit
            return 0;
            break;
        case 1:
        //skip
            break;
        default:
            cout<<"You shouldnt see this -> main.main()"<<endl;
    }
    cout<<"(Dramatic music playing)"<<endl;
    pause();
    pause();
    cout<<"\"Hello is this the sky marshal?\""<<endl;
    pause();
    cout<<"To reply yes input 1"<<endl;
    cout<<"To reply no input 0"<<endl;
    int yes = intput(1);
    if ( !yes ){
        cout<<"\"Ok nevermind then. Sorry this must be a civilian, no need for alarm\""<<endl<<endl;
        pause();
        fail();
        return 0;
    }
    cout<<"\"Ok good. This is HQ speaking. I'm afraid that we've recieved tip that one of the passangers on your flight is carrying a Samsung Note 7.\""<<endl;
    pause();
    cout<<"\"Please find the device and stick it into the bomb desposal container in the front of the plane near the the flight attendants cabin\""<<endl;
    pause();
    cout<<"\"Also, remember to only ask the passengers the 'approved' questions you learned about in flight school, if you don't they might suspect something and cause a panic\""<<endl;
    pause();
    cout<<"\"It looks like you have approx 15 minutes left to find the bomb\""<<endl;
    cout<<"\"Good luck and godspeed.\""<<endl;


    int a = game();
    cout <<endl<<endl<<endl;
    pause();
    pause();
    cout <<"The game will now start again" <<endl<<endl;
    pause();
    return main();
}
int intput(int max){
    int in;
    if (cin>>in && in<=max){
        return in;
    } else {
        cout << "Invalid input. Please try again. Input a number less than "
            <<max<<endl;
        cin.clear();
        while( cin.get() != '\n' ){
            continue;
        }
        return intput(max);     //recourse until input is accepted
    }
}
void pause(){
    int temp = time(NULL) + 2;   //pause for 2 seconds
    while( temp > time(NULL) );
}
void fail(){
    cout<<endl<<endl;
    cout<<"During the flight an explosion goes off on the plane"<<endl;
    cout<<"No one is hurt but as soon as the plane lands you are fired"<<endl;
    cout<<endl<<"Game Over."<<endl;
}
int game(){
    //before game loop:
    //1) objects are created
    //
    //main game loop:
    //
    //   player is prompted their choices and questions based on which room they are in
    //   check win conditions
    //   player's questions are carried out
    //   player's choice of action is carried out
    //   loop back to 1
    //
    //after game loop:
    //   lose
    

//Before game loop:
//1)objects are created below
//const Row(name, q1ans, q2ans, q3ans, act1resp, act2reesp, act1, act2)
//
    int start_time = time(NULL);
    Room* row1 = new Row( "Australian tourists", "\"Doing fine thanks, criky\"", "\"We got som' Nokia PureViews, mate\"", "\"No, but here are 45 photos we took on o'r trip if yah want to see them\"", "\"Bug off mate, ge' your slimy mits off me\"", "You look at the pictures, in one selfie of them boarding the plane you see the nanny handing a Samsung Note 7 to a baby!!", "try to take their phones", "look at their vacation photos");
    Room* row2 = new Row( "a group of Business women", "\"...\" There was no response", "\"...\" They don't respond but you see they are all working on blackberries", "\"There's a baby that was crying a while ago but it quieted down. You should go back and make sure it doesn't cry again\"", "\"Am I under arrest? Then no\"", "You spy over their shoulder. They're all working on presentations for a new flavor of cheese", "make them show you their phones", "spy over their shoulders to see what they're working on");
    Room* row3 = new Row("a male nanny and a baby under a blanket", "\"I'm doing fine thanks. Sorry about the noise, I'm trying to calm her down by showing her movies. She could use a pillow\"", "\"I have a razer flip phone\"", "\"Nope.\"", "\"Here's my phone\" It's a razer flip phone", "\"EXCUSE ME DONT DISTURB THE BABY\"", "demand to see their phone", "reach out to take the blanket off the baby");
    Room* row4 = new Row("Cosplayers", "\"Good! We're just really excited to go to Comic Con (TM)!\"", "\"We have Google Pixels. LOOK HERE AREN'T THEY GREEAT LOOK AT THEM HUUUUUUNNNNNNNNNGGGGGGGGGGGG\"",  "\"We haven't seen much, it's hard to see out of our masks\"", "\"These costumes don't have pockets\"", "They take off their costumes. No phone. Without their costumes they almost look normal... weird.", "Demand that they turn out their pockets", "Make them take off their costumes. There could fit buckets of Samsung Note 7s in the extra space");
 
    Room* window = new Window(start_time);
    Room* cabin = new Front();

    row1->set_links(cabin, row2, cabin, window);
    row2->set_links(row1, row3, cabin, window);
    row3->set_links(row2, row4, cabin, window);
    row4->set_links(row3, NULL, cabin, window);
    window->set_links(NULL, NULL, NULL, NULL);
    cabin->set_links(NULL, row1, cabin, window);
    
    Player you(cabin);
    int game_time = 60*15;      //10 mins in seconds

//***************************
//Game loop
//***************************
    Room* current = you.current_room;
    Room* next = current;
    while( time(NULL)-start_time <= game_time ) { //while there is still time
        string room_name = current->get_name();
        
    
//2) player is prompted their choices and questions based on which room they are in
        int cin_max = 0;
        cout<<"You are near the "<< room_name <<endl;
        if ( room_name  == "window" ){
            cout<< "Would you like to look out the window?" <<endl;
            cout<< "1-yes \t 0-no" <<endl;
            cin_max = 1;
        } else if ( room_name == "cabin" ){
            current->prompt_actions();
            cin_max = 3;
        } else {
            cout<< "To ask a question input 0"<<endl;
            cout<< "To do an action input 1" <<endl;
            cout<< "To move back in the plane one row input 2" <<endl;
            cout<< "To move up the plane one row input 3"<<endl;
            cout<< "To go to the window input 4"<<endl;
            cout<< "To run to the cabin input 5"<<endl;
            cin_max = 5;
        }

        int response = intput( cin_max );

        if ( cin_max == 1 ){    //if window
            if( response == 0 ){
                cout << "Fine then." <<endl;
                cout << "Which row would you like to go to? (1-4)" <<endl;
                cout << "To go to the cabin input 0" <<endl;
            } else {
                current->ask_question(1);    
                cout << endl << "Which row would you like to go to now? (1-4)" <<endl;
                cout << "To go to the cabin input 0" <<endl;
            }
            int res2 = intput(4);
            
            switch( res2 ){
                case 0:
                    next = cabin;
                    break;
                case 1:
                    next = row1;
                    break;
                case 2:
                    next = row2;
                    break;
                case 3:
                    next = row3;
                    break;
                case 4:
                    next = row4;
                    break;
                default:            
                    cout << "You shouldn't see this. main-game()-window section" <<endl;
            }
        } else if ( cin_max == 3 ){     // if cabin
            int res2 = response;    //<- just a happy little accident

            if ( res2 == 0 ){       //move to front row
                next = row1;
            } else if ( res2 == 1 ){    //throw thing into bomb box
                pause();
                if ( you.get_held_int() != 0 ){
                    cout << "You quickly throw the "<< you.get_held_string() <<" into the box!"<< endl;
                } else {
                    cout << "Your hands are empty..." <<endl;
                }
                int obj = you.get_held_int();
                if (obj == 1){      //YOU WIN THE GAME!!!!
                    cout << "The plane is safe thanks to you" <<endl;
                    pause();
                    cout << "You won the game after "<< (time(NULL)-start_time)/60 << " minutes"<<endl;
                    pause();
                    cout << "Congrats!!" <<endl;


                    delete row1;
                    delete row2;
                    delete row3;
                    delete row4;
                    delete window;
                    delete cabin;
                    return 1;
                }
                you.grab_object(0);
                                                                                   //indentation gets messed up somewhere around this region
            } else {
                you.grab_object( res2 );
            }

        } else if ( cin_max == 5 ){     //if row
    //0- question, 1-action, 2-move back, 3-move up, 4-window, 5-cabin
            int res2;
            switch( response ){
                case 0:                     //question
                    prompt_approved_questions();
                    res2 = intput(3);
                    if ( res2 == 3 ){   //stare at them
                        cout <<"..."<<endl;
                        pause();
                    } else {            //ask actual question
                        current->ask_question( res2 );
                    }
                    break;
                case 1:                     //action
                    current->prompt_actions();
                    //check if player has blanket and it talking to the nanny
                    if ( current == row3 && you.get_held_int() == 2 ){
                        cout<< "To give the nanny the pillow input 3"<<endl;
                        res2 = intput(3);
                    } else { 
                        res2 = intput(2);
                    }

                    if ( res2 == 0 ){   //stare at them
                        cout<<"..."<<endl;
                        pause();
                    }else if( res2== 3 ){
                        cout << "\"Thank you!\"" <<endl;
                        cout << "When the nanny pulls the blanket off the baby you see that the baby has been watching movies on a Samsung Note 7!!"<<endl;
                        cout << "To explain the situation to the nanny and grab the phone it input 1" << endl;
                        cout << "To let it be input 0" <<endl;
                        if ( intput(1) ){
                            cout << "The nanny is understanding and lets you take the phone"<<endl;
                            cout <<"You now have a possibly explosive device in your hand" <<endl;
                            you.grab_object(0);
                            you.grab_object(1);
                        } else {
                            cout<< "Wow. You are too nice" <<endl;
                            pause();
                            cout << "smh" <<endl;
                        }
                    }else {
                        current->do_action( res2 );
                    }
                    break;
                case 2:                     //move back
                    if ( current->after == NULL ){
                        cout << "You are at the last occupied row of the plane, you cannot move any further back"<<endl;
                    } else {
                        next = current->after;
                        cout << "You walk over to the row occupied by  "<< next->get_name() <<endl;
                    }
                    break;
                case 3:                     //move up
                    //no check needed bc all rows have befores
                    next = current->before;
                    cout << "You walk over to the row occupied by "<< next->get_name() << endl;
                    break;
                case 4:                     //window
                    cout << "You look out the window..."<<endl;
                    next = current->window;
                    break;
                case 5:                     //cabin
                    cout << "You rush to the front of the plane and the cabin"<< endl;
                    next = current->front;
                    break;
                default:
                    cout << "This shouldn't be seen"<<endl;
                }
            }   
        
        cout<<endl<<endl;
        pause();
        current = next;
    }//loop

    
//ran out of time
    fail();
    
    delete row1;
    delete row2;
    delete row3;
    delete row4;
    delete window;
    delete cabin;
    return 0;
}
void prompt_approved_questions(){
    cout<< "To ask them how they are doing input 0" <<endl;
    cout<< "To ask what phone they have input 1" <<endl;
    cout<< "To ask them if any of the other passangers seem strange to them input 2" <<endl;
    cout<< "To not ask them any questions and instead just stare at them input 3" <<endl;
}
