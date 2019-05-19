#include <iostream>
#include "heap.h"
#include <queue>
#include <string>
namespace Final_project{
    void heap::create_root(const node::value_type& entry, const std::string task){
        root_ptr = new node(entry,task);
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
                if(cursor->left() == NULL){
                    cursor->set_left(temp);
                    current_ptr = temp;
                    break;
                }
                else if(cursor->right() == NULL){
                    cursor->set_right(temp);
                    current_ptr = temp;
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
            delete root_ptr;
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
                cursor = cursor->left();
                delete cursor;
                break;
            }
            else if(cursor->right()==current_ptr){
                node_ptr.push(cursor->left());
                cursor = cursor->right();
                delete cursor;
                break;
            }
            else{
                if(cursor->left()!=NULL){node_ptr.push(cursor->left());}
                if(cursor->right()!=NULL){node_ptr.push(cursor->right());}
            }
        }
        //set the current pointer to the last node
        while(node_ptr.size()>1){
            node_ptr.pop();
        }
        current_ptr = node_ptr.front();
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

}