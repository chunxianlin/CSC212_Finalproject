#include <iostream>
#include "node.h"
#include "heap.h"
#include <string>
using namespace Final_project;
void To_to_list();

int main(){
    return 0;
}
void To_to_list(){
    std::cout<<"<<TO DO LIST>>"<<std::endl;
    std::string user_input;
    heap my_list;
    while(user_input != "EXIT"){
        std::cout<<"NEXT INSTRUCTION:";
        std::getline(std::cin,user_input);
        user_input = Capitalize(user_input);
        if(user_input =="HELP"){
            std::cout<<"NEW TASK--put a new task on the to do list"<<std::endl;
            std::cout<<"TO DO--show the first thing on the to do list"<<std::endl;
            std::cout<<"FINISHED--check and delete the first task"<<std::endl;
            std::cout<<"VIEW TASKS--view all the tasks in their order"<<std::endl;
            std::cout<<""<<std::endl;
        }
        else if(user_input == "NEW TASK"){
            std::string new_task;
            std::cout<<"ENTER THE NEW TASK:";
            std::getline(std::cin, new_task);std::cout<<std::endl;
            my_list.DLD(new_task);
            std::cout<<"NEW TASK RECORDED."<<std::endl;
        }
        else if(user_input == "TO DO"){
            my_list.Most_important();
        }
        else if(user_input == "FINISHED"){
            my_list.root_remove();
            std::cout<<"YOU HAVE FINISHED A TASK! CONGRADUATION!"<<std::endl;
        }
        else if(user_input == "VIEW TASKS"){
            std::cout<<"YOUR TASKS:"<<std::endl;
            my_list.print_tasks();
        }
        else if(user_input == "SAVE"){

        }
        else if(user_input == "LOAD"){

        }
        else{
            std::cout<<"INVALID INSTRUCTION! ENTER 'HELP' FOR INSTRUCTION REFRENCE."<<std::endl;
        }

    }
}