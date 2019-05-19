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
            void create_root(const node::value_type& entry, const std::string task); 
            void insert(const node::value_type& entry, const std::string task);    
            void root_remove();
            void reheapification();
            void inorder(node* this_ptr);
            void Most_important();

            void insert_left(const int val,node* this_ptr);
            void insert_right(const int val, node* this_ptr);
            node* questions();
            void DLD(std::string task);
            void print_tasks();
            node* return_root(){return root_ptr;}
            void count();
        private:
            node* root_ptr;
            node* current_ptr;
    };
    std::string Capitalize(std::string word);
    void To_do_list();
}


#endif