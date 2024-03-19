#include <iostream>

using namespace std;

template<typename T> 
struct Node
{
    T data; 
    Node* link; 
};

int main()
{
    Node<string> firstNode; 
    firstNode.data = "PI";
    //quizQuestion2FirstNode.link = nullptr; //explicitly iniitalizing 


    Node<string> secondNode;
    secondNode.data = "Euler's number"; 
    secondNode.link = nullptr; 

    //update first node's link: 
    firstNode.link = &secondNode; 


    cout << firstNode.link->link << endl; 


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