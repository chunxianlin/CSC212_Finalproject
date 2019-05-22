# CSC212_Finalproject
# Final project for CSC212
#    For the final project I decided to do a to do list. The data structure I'm using is heap. By putting tasks onto the list, the list will rearrange tasks and returning them in a customized order. I had a total of six files for this project, main.cpp, node,cpp, node.h, heap.cpp, heap.h, and a Cmake file. Main.cpp is a simple file that calls the TO_DO_LIST() function. Node.h is a file containing class node initialized as int type. Within the class node there is a constructor node, member functions of node, and private member variables. The constructor is initialized as having an empty string, an empty int, two NULL pointers. The functions for the class are setters and getters. All functions in this class have a time complexity of O(1). Private member variables are data_field that holds string, value_field holds int, left_child and right_child hold pointers. Since everything is done in node.h, node.cpp is actually empty but just in case I need to put some functions there.

#   Heap.h and heap.cpp are the main parts of the project. Heap.h has a constructor of heap with node type, setting private member root_ptr and current_ptr to NULL. There are 13 member functions in heap.h. Create_root(#1) is use for create root pointer and the time complexity is O(1) there's no loop in the function. Function insert(#2) is to insert a new node into the heap. The time complexity is O(nln(n)) because there is a loop and a function call of reheapification which is O(ln(n)) and it will be O(nln(n)). Inorder(#3) is a function of reheapification. The reason why calling it inorder is because inorder will take in a parameter and when I call reheapification I don't need to give any parameter. Inorder is O(ln(n)) because it is recursive function. Same for reheapification because it is just calling inorder. Root_remove(#4) is the function for removing the root pointer. It has O(2nln(n)) or O(nln(n)) as time complexity because there are two while loops inside the function and a function call of reheapification. Most_important(#5) is use for cout the first task on the list and it is O(1). Insert_left and insert_right(#6) are functions for insert without reheapification. these two are used only for the question list and both are O(1). Questions(#7) are questions for user to answer, it is a binary tree of questions just like the animal tree. It has a time complexity of O(1) because everything inside is constant. DLD(#8) stands for difficulty level determination which is asking the user how much do they weight their tasks. The time complexity is O(n) because of the while loop. Print_task(#9) is a funciton that prints all the tasks from the list. IT IS NOT IN DEFINITE ORDER. The time complexity is O(n) because of while loop. Count(#10) is used for counting the number of tasks on the list. It is not necessary but just a feature for the user to have. The time complexity and reason are same as count. To_do_list(#11) is the last and most important funciton. It is combination of all other functions. the time complexity can be O(n*2), O(nln(n)) or O(n) depending on user's input. What is does is depending on user's input, this funcion will do one of the smaller functions inside and as a whole it will work as a to do list. (Detailed explanation of time complexity will be down below actul code will be in other files)

#    The reason for choosing this project is to organize things in live. When people don't know what should they do next, they can use this as a reference. It can organize things in a priority queue sequence which is able to remind user what they should to first. Just like heap will arrange nodes by its weight. The advantages of this are to keep trak of tasks, and it is costomized for everyone. The disadvantages are costomized for everyone. Because it is under limited amount of time and it is costomized for myself only. weighting tasks are depending on my habits and costomizing is only available for programmer. Once it's compiling, there is no way to change it. Besides that it is not precise enough. people may want it to be precise to minutes. Options for weighting tasks are extremely limited in this case. I chose heap because I want the most important thing on my list, not a random thing from the list. It is perfect data structure for this topic because its unique property match the purpose of to do list. Heap is good for sorting and seleting max or min from an array. Compare to other data structures, it is limited for specific applications. Unlike others are able to use in a wide open field.

#1
#void heap::create_root(const node::value_type& entry, const std::string task){
#        node* temp;
#        temp = new node(entry,task);           //constant step will be counted as 1
#        root_ptr = temp;
#        current_ptr = root_ptr;
#    };

#2
#void heap::insert(const node::value_type& entry, const std::string task){
#        //insert root
#        if(root_ptr == NULL){              //constant for calling create root
#            create_root(entry, task);
#        }
#        else{
#            std::queue<node*> tree_ptr;    
#            tree_ptr.push(root_ptr);
#            while(true){...}           //single while loop is O(n)
#            reheapification();         //reheapification is O(ln(n))
#        }                              //combined will be O(nln(n))
#    };

#3
#void heap::inorder(node* this_ptr){
#        if(this_ptr == NULL){return;}
#        //go to the deepest and work backwards
#        inorder(this_ptr->left());         //recursion happened here
#        if(this_ptr->left() != NULL && (this_ptr->left())->value() > this_ptr->value()){ 
#            int hold;                      
#            std::string hold_string;       //inside the if statement will be constant
#            //hold value and data
#            hold = (this_ptr->left())->value();
#            hold_string = (this_ptr->left())->data();
#            //switch values and data
#            (this_ptr->left())->set_value(this_ptr->value());
#            (this_ptr->left())->set_data(this_ptr->data());
#            this_ptr->set_value(hold);
#            this_ptr->set_data(hold_string);
#        }
#        inorder(this_ptr->right());          //recursion happened here as well
#        if(this_ptr->right() != NULL && (this_ptr->right())->value() > this_ptr->value()){
#            int hold;
#            std::string hold_string;
#
#            hold = (this_ptr->right())->value();
#            hold_string = (this_ptr->right())->data();
#
#            (this_ptr->right())->set_value(this_ptr->value());
#            (this_ptr->right())->set_data(this_ptr->data());
#            this_ptr->set_value(hold);
#            this_ptr->set_data(hold_string);
#        }
#    };

#4
#void heap::root_remove(){
#        //delete root directly if there's no leafs
#        if(root_ptr == NULL){return;}                                    //constant
#        if(root_ptr->left()==NULL&&root_ptr->right()==NULL){
#            root_ptr = NULL;
#            return;
#        }
#        //set the current pointer or the last to the root
#        root_ptr->set_data(current_ptr->data());
#        root_ptr->set_value(current_ptr->value());
#        //use queue to do level order traversal
#        std::queue<node*> node_ptr;
#        node* cursor;
#        node_ptr.push(root_ptr);
#        //delete the last node
#        while(true){...}                   //while loop is O(n)
#        //set the current pointer to the last node
#        while(node_ptr.size()>1){          //two separate while loop is O(2n) or O(n)
#            node_ptr.pop();
#        }
#        if(root_ptr == NULL){
#            current_ptr = NULL;
#        }
#        else{
#        current_ptr = node_ptr.front();
#        }
#        //rearrange
#        reheapification();                 //O(ln(n)) X O(n) = O(nln(n))

#5
#void heap::Most_important(){
#        if(root_ptr != NULL){              //constant statements will be O(1)
#        std::cout<<"YOUR TASK WILL BE: "<<root_ptr->data()<<std::endl;     
#        }
#        else{
#            std::cout<<"THERE'S NO MORE TASK FOR YOU."<<std::endl;
#        }
#    };

#6
# void heap::insert_left(const int val,node* this_ptr){
#        node* temp;
#        temp = new node(val);          //both functions are constant and time complexity will be O(1)
#        this_ptr->set_left(temp);  
#    };
# void heap::insert_right(const int val,node* this_ptr){
#        node* temp;
#        temp = new node(val);
#        this_ptr->set_right(temp);
#    };

#7
#node* heap::questions(){
#        //8 nodes for the question
#        node* root;
#        node* level1_L;
#        node* level1_R;            //this function is constant so it is O(1)
#        node* level2_LL;
#        node* level2_LR;
#        node* level2_RL;
#        node* level2_RR;
#        //questions
#        std::string question1("Is the deadline soon?(3 days as a range)");
#        std::string question2("Will this task take 3 hours?");
#        std::string question3("Do you consider this task as a challenging task?");
#        //put the questions in
#        root = new node(1,question1);
#        level1_L = new node(1,question2);
#        level1_R = new node(1,question2);
#        level2_LL = new node(1, question3);
#        level2_LR = new node(1, question3);
#        level2_RL = new node(1, question3);
#        level2_RR = new node(1, question3);
#        //root to depth1
#        root->set_left(level1_L);
#        root->set_right(level1_R);
#        //depth 1 to depth2
#        level1_L->set_left(level2_LL);
#        level1_L->set_right(level2_LR);
#        level1_R->set_left(level2_RL);
#        level1_R->set_right(level2_RR);
#        //depth2 to depth3
#        insert_left(5,level2_LL);
#        insert_right(6,level2_LL);
#        insert_left(7,level2_LR);
#        insert_right(8,level2_LR);
#        insert_left(1,level2_RL);
#        insert_right(2,level2_RL);
#        insert_left(3,level2_RR);
#        insert_right(4,level2_RR);
#        return root;
#    };

#8
#void heap::DLD(std::string task){
#        node* question_list;
#        std::string user_input;
#        question_list = questions();                  //it has a while loop and it will O(n)
#        while(question_list->left()!= NULL){
#            std::cout<<question_list->data()<<"  Yes(Y) or No(N)"<<std::endl;
#            std::cin>>user_input;
#            user_input = Capitalize(user_input);
#            if(user_input == "YES"||user_input =="Y"){
#                question_list = question_list->left();
#            }
#            else if(user_input == "NO" || user_input == "N"){
#                question_list = question_list->right();
#            }
#            else{
#                std::cout<<"INVALID INPUT! PLEASE TRY AGAIN!"<<std::endl;
#            }
#        }
#        int level;
#        level = question_list->value();
#        std::cout<<"The level is "<<level<<std::endl;
#        this->insert(level, task);
#        return;

#9
#void heap::print_tasks(){
#        std::queue<node*> print;
#        print.push(root_ptr);              //it has a while loop and it will O(n)
#        while(!print.empty()){
#           if(print.front()->left()!=NULL){
#                print.push(print.front()->left());
#            }
#            if(print.front()->right()!=NULL){
#                print.push(print.front()->right());
#            }
#            std::cout<<print.front()->data()<<std::endl;
#            print.pop();
#        }
#    };

#10
#void heap::count(){
#        std::queue<node*> traverse;
#        std::queue<node*> number_of_task;
#        node* cursor;
#        number_of_task.push(root_ptr);
#        traverse.push(root_ptr);               //it has a while loop and it will O(n)
#        while(!traverse.empty()){
#            cursor = traverse.front();
#            if(cursor->left()!=NULL){
#                traverse.push(cursor->left());
#                number_of_task.push(cursor->left());
#            }
#            if(cursor->right()!=NULL){
#                traverse.push(cursor->right());
#                number_of_task.push(cursor->right());
#            }
#            traverse.pop();
#        }
#        std::cout<<"YOU hAVE "<<number_of_task.size()<<" TASK(S) LEFT."<<std::endl;
#        
#    };

#11
#void To_do_list(){
#        std::cout<<"<<TO DO LIST>>"<<std::endl;
#        std::cout<<"ENTER 'HELP' FOR INSTRUCTION MANUAL"<<std::endl;
#        std::cout<<"NEXT INSTRUCTION:";
#        std::string user_input;
#        heap my_list;
#        std::string exit;
#        while(exit != "EXIT"){                           //there is a while loop so it is at least a O(n)
#            if(!iscntrl(user_input[0])){                 //if running individual funtion separately will be
#                std::cout<<"NEXT INSTRUCTION:";          //O(n) mulitply by the time complexity of each little
#            }                                            //functions
#            std::getline(std::cin,user_input);
#            user_input = Capitalize(user_input);
#            if(user_input =="HELP"){
#                std::cout<<"NEW TASK--put a new task on the to do list."<<std::endl;
#                std::cout<<"TO DO--show the first thing on the to do list."<<std::endl;
#                std::cout<<"FINISHED--check and delete the first task."<<std::endl;
#                std::cout<<"VIEW TASKS--view all the tasks."<<std::endl;
#                std::cout<<"REMAINING--show remaining task(s)"<<std::endl;             //O(1)
#                std::cout<<"LOAD--load your tasks from saved file."<<std::endl;
#                std::cout<<"SAVE--save your tasks into a file."<<std::endl;
#                std::cout<<"EXIT--to exit your to do list."<<std::endl;
#            }
#            else if(user_input == "NEW TASK"){
#                std::string new_task;
#                std::cout<<"ENTER THE NEW TASK:";              //O(nln(n))
#                std::getline(std::cin, new_task);std::cout<<std::endl;
#                my_list.DLD(new_task);
#                std::cout<<"NEW TASK RECORDED."<<std::endl;
#            }
#            else if(user_input == "TO DO"){
#                my_list.Most_important();          //O(1)
#            }
#            else if(user_input == "FINISHED"){
#                my_list.root_remove();                 //O(nln(n))
#                std::cout<<"YOU HAVE FINISHED A TASK! CONGRADUATION!"<<std::endl;
#            }
#            else if(user_input == "VIEW TASKS"){
#                std::cout<<"YOUR TASKS:"<<std::endl;   //O(n)
#                my_list.print_tasks();
#            }
#            else if(user_input == "SAVE"){
#                std::string filename = "mylist.txt";
#                std::ofstream outFile;
#                outFile.open(filename.c_str());            //O(n)
#                while(my_list.return_root() != NULL){   
#                    std::string task = my_list.return_root()->data();
#                    int val = my_list.return_root()->value();
#                    outFile<<task<<std::endl;
#                    outFile<<val<<std::endl;
#                    my_list.root_remove();
#                }
#                outFile.close();
#            }
#            else if(user_input == "LOAD"){
#                std::string filename = "mylist.txt";
#                std::string line;
#                std::string hold_string;          //O(n)
#                std::ifstream inFile;
#                inFile.open(filename.c_str());
#                while(std::getline(inFile, line)){
#                    if(line.size()==1){
#                        char i = line[0];
#                        int val = i -'0';
#                        my_list.insert(val, hold_string);
#                        hold_string = "";
#                        val = 0;
#                    }
#                    else if(line.size() != 1){
#                        hold_string = line;
#                    }
#                }
#                inFile.close();
#            }
#            else if(user_input == "REMAINING"){
#                my_list.count();               //O(n)
#            }
#            else if(user_input == "EXIT"){
#                std::cout<<"DID YOU SAVE YOUR LIST?(Y/N)"<<std::endl;
#                std::getline(std::cin, exit);
#                exit = Capitalize(exit);           O(1)
#                if(exit == "Y"|| exit == "YES"){
#                    exit = "EXIT";
#                }
#                else if(exit == "N" || exit == "NO"){
#                    std::cout<<"PLEASE SAVE YOUR LIST FIRST THEN EXIT AGAIN!"<<std::endl;
#                }
#            }
#        }
#    };