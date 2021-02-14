//
//  main.cpp
//  LinkedList
//
//  Created by Andrew Hartsfield on 2/11/21.
//

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "LinkedListInterface.h"

using namespace std;

template<typename T>
class LinkedList: public LinkedListInterface<T> {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& d, Node* n) : data(d), next(n) {}
        ~Node() = default;
    };
    Node *head;
    
public:
    LinkedList() : head(NULL) {}
    
    ~LinkedList() { clear(); }
    
    void push_front(const T& value) {
        head = new Node(value, head);
        return;
        cout << head->data;
    }
    //delete first item in linked list
    void pop_front(void) {
        if (head == NULL) {
            cout << "Empty!";
        }
        else {
            Node* holder = head;
            head = head->next;
            delete holder;
            cout << "OK";
        }
    }
    
    //output first item in the linked list
    T& front(void) {
        if (head == NULL) {
            T string;
            string = "Empty!";
            return string;
        }
        else {
            return head->data;
        }
    }
    
    //If list is empty, return true. s
    bool empty(void) const {
        if (head == NULL) {
            return true;
        }
        else {
            return false;
        }
    }
    
    //Removing all nodes with values from linked lists
    virtual void remove(const T& value) {
        Node* current_node = head;
        Node* next_node = head->next;
        delete head;
        while (current_node != NULL) {
            delete current_node;
            current_node = next_node;
            next_node = current_node->next;
        }
        
    }
    void clear(void) {
        Node* node_pointer = head;
        while (node_pointer != NULL) {
            Node* saved_pointer = node_pointer->next;
            delete node_pointer;
            node_pointer = saved_pointer;
        }
    }
    
    //Reverse all the nodes in the linked list
    void reverse(void) {
        Node* current = head;
        Node* next = NULL;
        Node* prev = NULL;
        while (current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
    
    //Return the number of nodes in the linked list
    size_t size(void) const {
        Node* current_node = head;
        Node* next_node = head->next;
        int size = 0;
        while (current_node != NULL) {
            size++;
            current_node = next_node;
            next_node = current_node->next;
        }
        return size;
    }
     
    
     //Returns contents of linked list seperated by a space.
    string toString(void) const {
        stringstream out;
        Node* current_node = head;
        while (current_node != NULL) {
            out << current_node->data;
            current_node = current_node->next;
        }
           return out.str();
    }
    
    friend std::ostream& operator<< (ostream& os, const LinkedList& LinkedList)
    {
       os << LinkedList.toString();
       return os;
    }
};



int main(int argc, const char * argv[]) {
    
    if (argc < 3)  {
        cerr << "Please provide name of input and output files";
        return 1;
    }
    cout << "Input file: " << argv[1] << endl;
    ifstream in(argv[1]);
    if(!in) {
        cerr << "Unable to open" << argv[1] << " for Input";
        return 2;
    }
    
                                                                          
    cout << "Output file: " << argv[2] << endl;
    ofstream out(argv[2]);
    if (!out) {
        in.close();
        cerr << "Unable to open" << argv[2] << " for output";
        return 3;
    }
    LinkedList<string> linked_list;
    for (string line; getline(in, line);)
    {
       string item1, item2;
       if (line.size() == 0) continue;
       out << endl << line;
       istringstream iss(line);
       iss >> item1;
       if (item1 == "Insert") {
          while (iss >> item2) {
              linked_list.push_front(item2);
          }
       }
       else if (item2 == "PrintList") {
           while (iss >> item2) {
               //out << endl << item2;
               linked_list.toString();
           }
       }
       else if(item1 == "Clear") {
           while (iss >> item2) {
               out << endl << item2;
               linked_list.clear();
           }
       }
       else if(item1 == "Delete") {
           while (iss >> item2) {
               out << endl << item2;
               linked_list.pop_front();
           }
       }
       else if(item1 == "Insert") {
           while (iss >> item2) {
               out << endl << item2;
               linked_list.push_front(item2);
           }
       }
       else if(item1 == "Reverse") {
           while (iss >> item2) {
               out << endl << item2;
               linked_list.reverse();
           }
       }
       else if(item1 == "Size") {
           while (iss >> item2) {
               out << endl << item2;
               linked_list.size();
           }
       }
       else if(item1 == "Empty") {
           while (iss >> item2) {
               out << endl << item2;
               linked_list.empty();
           }
       }
       else if(item1 == "Remove") {
           while (iss >> item2) {
               out << endl << item2;
               linked_list.remove(item2);
           }
       }
    
    }

    
    
    return 0;
}
