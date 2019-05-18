#include <iostream>
#include "heap.h"
#include <queue>
namespace Final_project{
    void heap::create_root(const node::value_type& entry, const std::string event){
        root_ptr = new node(entry,event);
        current_ptr = root_ptr;
    };
    void heap::insert(const node::value_type& entry, const std::string event){
        //insert root
        if(root_ptr == NULL){
            create_root(entry, event);
        }
        else{
            std::queue<node*> tree_ptr;
            tree_ptr.push(root_ptr);

            while(true){
                node* temp;
                node* cursor;
                temp = new node(entry,event);
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
        std::cout<<root_ptr->data()<<std::endl;
    };
}