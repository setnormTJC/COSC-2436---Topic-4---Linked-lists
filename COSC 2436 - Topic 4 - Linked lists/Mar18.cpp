#include <iostream>

using namespace std;


struct Node
{
    int data; 
    Node* link; 

    /*prints the ADDRESS of the node*/
    friend ostream& operator << (ostream& os, const Node& n);
};

ostream& operator << (ostream& os, const Node& n)
{
    os << &n << endl; 

    return os; 
}


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

    cout << "&secondNode: " << &secondNode << endl; 
    cout << "secondNode (overloaded << prints address of secondNode): " << secondNode << endl;

    cout << "firstNode.link: " << firstNode.link << endl; 




    return 0;
}