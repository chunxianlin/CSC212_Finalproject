#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <cstdlib>
#include <string>

namespace Final_project{
    
    class node{
        public:
            typedef int value_type;
            node(const value_type& init_value = value_type(), std::string init_data ="",node* init_left = NULL, node* init_right = NULL){
                value_field = init_value;
                data_field = init_data;
                left_child = init_left;
                right_child = init_right;
            }
            //setter
            void set_value(const value_type& new_value){value_field = new_value;}
            void set_data(const std::string new_data){data_field = new_data;}
            void set_left(node* new_left){left_child = new_left;}
            void set_right(node* new_right){right_child = new_right;}
            //getter
            const value_type& value() const {return value_field;}
            const std::string data() const {return data_field;}
            const node* left() const {return left_child;}
            node* left(){return left_child;}
            const node* right() const {return right_child;}
            node* right(){return right_child;}
        private:
            std::string data_field;
            value_type value_field;
            node* left_child;
            node* right_child;
    };
}
#endif