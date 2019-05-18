#ifndef HEAP_H
#define HEAP_H
#include "node.h"
#include <iostream>
#include <queue>
#include <cstdlib>
namespace Final_project{
    class heap{
        public:
            heap(){
                root_ptr = NULL;
                current_ptr = NULL;
            }
            void create_root(const node::value_type& entry, const std::string event); 
            void insert(const node::value_type& entry, const std::string event);    
            void root_remove();
            void reheapification();
            void inorder(node* this_ptr);
            void Most_important();
        private:
            node* root_ptr;
            node* current_ptr;
    };
}


#endif