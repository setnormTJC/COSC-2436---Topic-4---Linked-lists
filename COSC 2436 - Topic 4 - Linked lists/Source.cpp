#include <iostream>

using namespace std;


struct Node
{
    int data; 
    Node* link; 
};

int main()
{

    //int a = 3; 
    //cout << &a << endl; 

    Node firstNode; 
    firstNode.data = 4; 
    firstNode.link = nullptr; 
    //cout << nullptr << endl; 

    Node secondNode; //the OS allocates memory for this (AKA: it gives an address) 
    secondNode.data = 6; 
    secondNode.link = nullptr; 

    //update the link of the first node to point at the second node: 
    firstNode.link = &secondNode; 

    cout << "first node's data: " << firstNode.data << endl;
    cout << "first node's link: " << firstNode.link << endl;


    cout << "Second node's data: " << secondNode.data << endl; 
    cout << "firstNode.link.data ...?" << (*firstNode.link).data << endl; 
    //another way of doing line 35: 
    cout << "firstNode.link->data ...?" << firstNode.link->data << endl;


    //cout << "Hello World";

    int numbers[5] = { 0, 1, 3, 4 };
    //inserting 2 at index 2:
    numbers[4] = numbers[3];
    numbers[3] = numbers[2];
    numbers[2] = 2;






    return 0;
}