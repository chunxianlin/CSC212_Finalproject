#include <iostream>
#include "heap.h"
#include <queue>
#include <string>
#include <fstream>
namespace Final_project{
    void heap::create_root(const node::value_type& entry, const std::string task){
        node* temp;
        temp = new node(entry,task);
        root_ptr = temp;
        current_ptr = root_ptr;
    };
    void heap::insert(const node::value_type& entry, const std::string task){
        //insert root
        if(root_ptr == NULL){
            create_root(entry, task);
        }
        else{
            std::queue<node*> tree_ptr;
            tree_ptr.push(root_ptr);
            while(true){
                node* temp;
                node* cursor;
                temp = new node(entry,task);
                cursor = tree_ptr.front();
                if(cursor->left()!=NULL){
                    if((cursor->left())->data()==task){
                        std::cout<<"THIS TASK IS ALREADY EXIST!"<<std::endl;
                        break;
                    }
                }
                else if (cursor->right()!=NULL){
                    if((cursor->right())->data()==task){
                        std::cout<<"THIS TASK IS ALREADY EXIST!"<<std::endl;
                        break;
                    }
                }
                if(cursor->left() == NULL){
                    cursor->set_left(temp);
                    current_ptr = temp;
                    break;
                }
                else if(cursor->right() == NULL){
                    cursor->set_right(temp);
                    current_ptr = temp;;
                    break;
                }
                else if(cursor->left() != NULL && cursor->right() != NULL){
                    tree_ptr.push(cursor->left());
                    tree_ptr.push(cursor->right());
                    tree_ptr.pop();
                }
            }
            reheapification();
        }
    };
    void heap::inorder(node* this_ptr){
        if(this_ptr == NULL){return;}
        //go to the deepest and work backwards
        inorder(this_ptr->left());
        if(this_ptr->left() != NULL && (this_ptr->left())->value() > this_ptr->value()){
            int hold;
            std::string hold_string;
            //hold value and data
            hold = (this_ptr->left())->value();
            hold_string = (this_ptr->left())->data();
            //switch values and data
            (this_ptr->left())->set_value(this_ptr->value());
            (this_ptr->left())->set_data(this_ptr->data());
            this_ptr->set_value(hold);
            this_ptr->set_data(hold_string);
        }
        inorder(this_ptr->right());
        if(this_ptr->right() != NULL && (this_ptr->right())->value() > this_ptr->value()){
            int hold;
            std::string hold_string;

            hold = (this_ptr->right())->value();
            hold_string = (this_ptr->right())->data();

            (this_ptr->right())->set_value(this_ptr->value());
            (this_ptr->right())->set_data(this_ptr->data());
            this_ptr->set_value(hold);
            this_ptr->set_data(hold_string);
        }
    };
    void heap::reheapification(){
        if(root_ptr == NULL || (root_ptr->left() == NULL && root_ptr->right() == NULL)){return;}
        heap::inorder(root_ptr);
    };
    void heap::root_remove(){
        //delete root directly if there's no leafs
        if(root_ptr == NULL){return;}
        if(root_ptr->left()==NULL&&root_ptr->right()==NULL){
            root_ptr = NULL;

            return;
        }
        //set the current pointer or the last to the root
        root_ptr->set_data(current_ptr->data());
        root_ptr->set_value(current_ptr->value());
        //use queue to do level order traversal
        std::queue<node*> node_ptr;
        node* cursor;
        node_ptr.push(root_ptr);
        //delete the last node
        while(true){
            cursor = node_ptr.front();
            if(cursor->left()==current_ptr){
                cursor->set_left(NULL);
                break;
            }
            else if(cursor->right()==current_ptr){
                node_ptr.push(cursor->left());
                cursor->set_right(NULL);
                break;
            }
            else{
                if(cursor->left()!=NULL){node_ptr.push(cursor->left());}
                if(cursor->right()!=NULL){node_ptr.push(cursor->right());}
                node_ptr.pop();
            }
        }
        //set the current pointer to the last node
        while(node_ptr.size()>1){
            node_ptr.pop();
        }
        if(root_ptr == NULL){
            current_ptr = NULL;
        }
        else{
        current_ptr = node_ptr.front();
        }
        //rearrange
        reheapification();
    };
    void heap::Most_important(){
        if(root_ptr != NULL){
        std::cout<<"YOUR TASK WILL BE: "<<root_ptr->data()<<std::endl;
        }
        else{
            std::cout<<"THERE'S NO MORE TASK FOR YOU."<<std::endl;
        }
    };
    void heap::insert_left(const int val,node* this_ptr){
        node* temp;
        temp = new node(val);
        this_ptr->set_left(temp);
    };
    void heap::insert_right(const int val,node* this_ptr){
        node* temp;
        temp = new node(val);
        this_ptr->set_right(temp);
    };
    node* heap::questions(){
        //8 nodes for the question
        node* root;
        node* level1_L;
        node* level1_R;
        node* level2_LL;
        node* level2_LR;
        node* level2_RL;
        node* level2_RR;
        //questions
        std::string question1("Is the deadline soon?(3 days as a range)");
        std::string question2("Will this task take 3 hours?");
        std::string question3("Do you consider this task as a challenging task?");
        //put the questions in
        root = new node(1,question1);
        level1_L = new node(1,question2);
        level1_R = new node(1,question2);
        level2_LL = new node(1, question3);
        level2_LR = new node(1, question3);
        level2_RL = new node(1, question3);
        level2_RR = new node(1, question3);
        //root to depth1
        root->set_left(level1_L);
        root->set_right(level1_R);
        //depth 1 to depth2
        level1_L->set_left(level2_LL);
        level1_L->set_right(level2_LR);
        level1_R->set_left(level2_RL);
        level1_R->set_right(level2_RR);
        //depth2 to depth3
        insert_left(5,level2_LL);
        insert_right(6,level2_LL);
        insert_left(7,level2_LR);
        insert_right(8,level2_LR);
        insert_left(1,level2_RL);
        insert_right(2,level2_RL);
        insert_left(3,level2_RR);
        insert_right(4,level2_RR);
        return root;
    };
    std::string Capitalize(std::string word){
        std::string hold;
        std::string upper_case;
        for(unsigned int i = 0; i<word.size();i++){
            upper_case = toupper(word[i]);
            hold += upper_case;
        }
        return hold;
    };
    void heap::DLD(std::string task){
        node* question_list;
        std::string user_input;
        question_list = questions();
        while(question_list->left()!= NULL){
            std::cout<<question_list->data()<<"  Yes(Y) or No(N)"<<std::endl;
            std::cin>>user_input;
            user_input = Capitalize(user_input);
            if(user_input == "YES"||user_input =="Y"){
                question_list = question_list->left();
            }
            else if(user_input == "NO" || user_input == "N"){
                question_list = question_list->right();
            }
            else{
                std::cout<<"INVALID INPUT! PLEASE TRY AGAIN!"<<std::endl;
            }
        }
        int level;
        level = question_list->value();
        std::cout<<"The level is "<<level<<std::endl;
        this->insert(level, task);
        return;
    };
    void heap::print_tasks(){
        std::queue<node*> print;
        print.push(root_ptr);
        while(!print.empty()){
            if(print.front()->left()!=NULL){
                print.push(print.front()->left());
            }
            if(print.front()->right()!=NULL){
                print.push(print.front()->right());
            }
            std::cout<<print.front()->data()<<std::endl;
            print.pop();
        }
    };
    void heap::count(){
        std::queue<node*> traverse;
        std::queue<node*> number_of_task;
        node* cursor;
        number_of_task.push(root_ptr);
        traverse.push(root_ptr);
        while(!traverse.empty()){
            cursor = traverse.front();
            if(cursor->left()!=NULL){
                traverse.push(cursor->left());
                number_of_task.push(cursor->left());
            }
            if(cursor->right()!=NULL){
                traverse.push(cursor->right());
                number_of_task.push(cursor->right());
            }
            traverse.pop();
        }
        std::cout<<"YOU hAVE "<<number_of_task.size()<<" TASK(S) LEFT."<<std::endl;
        
    };
    void To_do_list(){
        std::cout<<"<<TO DO LIST>>"<<std::endl;
        std::cout<<"ENTER 'HELP' FOR INSTRUCTION MANUAL"<<std::endl;
        std::cout<<"NEXT INSTRUCTION:";
        std::string user_input;
        heap my_list;
        std::string exit;
        while(exit != "EXIT"){
            if(!iscntrl(user_input[0])){
            std::cout<<"NEXT INSTRUCTION:";
            }
            std::getline(std::cin,user_input);
            user_input = Capitalize(user_input);
            if(user_input =="HELP"){
                std::cout<<"NEW TASK--put a new task on the to do list."<<std::endl;
                std::cout<<"TO DO--show the first thing on the to do list."<<std::endl;
                std::cout<<"FINISHED--check and delete the first task."<<std::endl;
                std::cout<<"VIEW TASKS--view all the tasks."<<std::endl;
                std::cout<<"REMAINING--show remaining task(s)"<<std::endl;
                std::cout<<"LOAD--load your tasks from saved file."<<std::endl;
                std::cout<<"SAVE--save your tasks into a file."<<std::endl;
                std::cout<<"EXIT--to exit your to do list."<<std::endl;
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
                std::string filename = "mylist.txt";
                std::ofstream outFile;
                outFile.open(filename.c_str());
                while(my_list.return_root() != NULL){
                    std::string task = my_list.return_root()->data();
                    int val = my_list.return_root()->value();
                    outFile<<task<<std::endl;
                    outFile<<val<<std::endl;
                    my_list.root_remove();
                }
                outFile.close();
            }
            else if(user_input == "LOAD"){
                std::string filename = "mylist.txt";
                std::string line;
                std::string hold_string;
                std::ifstream inFile;
                inFile.open(filename.c_str());
                while(std::getline(inFile, line)){
                    if(line.size()==1){
                        char i = line[0];
                        int val = i -'0';
                        my_list.insert(val, hold_string);
                        hold_string = "";
                        val = 0;
                    }
                    else if(line.size() != 1){
                        hold_string = line;
                    }
                }
                inFile.close();
            }
            else if(user_input == "REMAINING"){
                my_list.count();
            }
            else if(user_input == "EXIT"){
                std::cout<<"DID YOU SAVE YOUR LIST?(Y/N)"<<std::endl;
                std::getline(std::cin, exit);
                exit = Capitalize(exit);
                if(exit == "Y"|| exit == "YES"){
                    exit = "EXIT";
                }
                else if(exit == "N" || exit == "NO"){
                    std::cout<<"PLEASE SAVE YOUR LIST FIRST THEN EXIT AGAIN!"<<std::endl;
                }
            }
        }
    }
}
