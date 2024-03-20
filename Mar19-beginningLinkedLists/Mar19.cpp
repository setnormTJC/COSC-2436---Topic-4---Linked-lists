#include <iostream>

using namespace std;

template<typename T> 
struct Node
{
    T data; 
    Node* link; 
};

template<typename T> 
void traverseList(Node<T>& startNode)
{
    Node<T>* current = &startNode; 

    while (current != nullptr)
    {
        cout << current->data << "\t" << current << endl;
        current = current->link; 
    }
}

int main()
{
    Node<string> head; 
    head.data = "PI";
    //quizQuestion2FirstNode.link = nullptr; //explicitly iniitalizing 

    Node<string> current = head; 


    Node<string> secondNode;
    secondNode.data = "Euler's number"; 
    //secondNode.link = nullptr; 

    //update first node's link: 
    head.link = &secondNode; 

    //cout << head.link->data << endl; 


    Node<string> tail; 
    tail.data = "golden ratio";
    tail.link = nullptr; 

    secondNode.link = &tail; 


    cout << "Q1: " << head.link->link << endl; 
    cout << "Q2: " << head.link->data << endl; 

    traverseList(head); 


   /* Node firstNode;
    firstNode.data = 1; 
    firstNode.link = nullptr; //nullptr is 0x0000 0000 0000 0000 

    Node secondNode; 
    secondNode.data = -42; 
    secondNode.link = nullptr; 

    //update the link of firstNode
    firstNode.link = &secondNode; 

    cout << "first node's data: " << firstNode.data << endl; 
    cout << "SECOND node's data: " << secondNode.data << endl; 
    
    cout << "a less direct approach to getting second node's data: "
        << firstNode.link->data << endl; 


    Node thirdNode; 
    thirdNode.data = 12345; 
    thirdNode.link = nullptr; 

    secondNode.link = &thirdNode;
    //int a = 32; 


    int thirdNodesData = firstNode.link->link->data; 
    cout << "12345? " << thirdNodesData << endl; 
    //int* pointerToA = &a; 

    //cout << pointerToA << "\t" << *pointerToA << endl; 

    //cout << nullptr << endl; 
    
    //cout << &nullptr << endl;// NULL << endl;
   
   */

    
    return 0;
}