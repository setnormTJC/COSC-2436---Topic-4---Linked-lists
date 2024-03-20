#include <iostream>

#include"LinkedList.h"

using namespace std;


//
//void traverseList(Node<string>& headNode)
//{
//    Node<string>* current = &headNode; 
//
//
//    while (current != nullptr)
//    {
//        cout << current->data << endl; 
//        current = current->next; 
//        //this line of code (20) is analagous to i++ 
//    }
//}

int main()
{
    LinkedList<string> airportList; 

    cout << "the length of the list is: " << airportList.length() << endl;
    airportList.print(); 

    airportList.insertFirst("LAX"); 
    airportList.insertFirst("TOY");
    airportList.insertFirst("LAHORE");

    cout << "After calling `insertFirst` thrice: " << endl; 

    airportList.print(); 

    //Node<string>  firstNode; 
    //firstNode.data = "LAX"; 
    //firstNode.next = nullptr; 

    //Node<string> secondNode; 
    //secondNode.data = "TOY"; 
    //secondNode.next = nullptr; 

    //firstNode.next = &secondNode; 


    //add a third Node (AKA: airport) to this singly-linked list and then TRAVERSE!
    //Node<string> thirdNode; 
    //thirdNode.data = "Lahore"; 
    //thirdNode.next = nullptr; 

    //secondNode.next = &thirdNode; 


    //traverseList(firstNode); 




    return 0;
}