#pragma once

#include<iostream> 

using std::cout; 
using std::endl; 


template <typename T>
struct Node
{
    T data;
    Node* next;
};


template<typename T> 
class LinkedList
{
    Node<T>* first; 
    Node<T>* last; 
    int nodeCount; //the number of nodes in the list 


    //member functions 

public: 

    /*this just creates an EMPTY linked list */
    LinkedList()
    {
        first = nullptr; 
        last = nullptr; 
        nodeCount = 0; 
    }

    void print() {
        Node<T>* current;
        current = first;
        while (current != NULL) {
            cout << current->data << endl;
            current = current->next;
        }
    }//end print() function


    void insertFirst(const T& newInfo)
        //pass info by constant reference
        //alternative approach: create a Node object and pass it in
    {
        Node<T>* newNode = new Node<T>;
        
        newNode->data = newInfo;
        newNode->next = first; //puts newNode before first
        
        first = newNode;
    }

    int length() { return nodeCount; }

};