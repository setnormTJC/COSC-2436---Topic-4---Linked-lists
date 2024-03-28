#include <iostream>

#include<forward_list>
//Node1 -> Node2 
using namespace std;

template<typename T> 
struct Node
{
    T data; 
    Node* link; 
};



template<typename T> 
class LinkedList
{
    Node <T>* first; //a pointer is a variable that holds a memory address
    Node<T>* last; 
    int nodeCount; 

public: 
    /*creates an EMPTY linked list*/
    LinkedList()
    {
        cout << "Default constructor of linked list called!\n";
        first = nullptr; 
        last = nullptr; 
        nodeCount = 0; 
    }

    void insertFirst(const T& valueToInsert)
    {
        Node<T>* newNode = new Node<T>; //allocates space for a new node 

        newNode->data = valueToInsert; 
        newNode->link = first; 

        first = newNode; 

        if (last == NULL)
        {
            last = newNode;
            //if newNode is the only node,
            //it is both first and last
        }
        nodeCount++; 
    }

    int length() 
    {
        return nodeCount; 
    }

    void traverseList()
    {
        Node<T>* currentNode; //this is similar to int i in a for loop 
        currentNode = first; //i = 1
        while (currentNode != nullptr)
        {
            cout << currentNode->data << endl;
            currentNode = currentNode->link; //this is similar to i++ in a for loop 
        }
    }

    void insertAfter(Node<T>* previous, T insertedValue)
    {
        Node<T>* newNode = new Node<T>;
        newNode->data = insertedValue;

        //Diagram on next slides walks through two lines below:
        //previous->link = newNode;
        newNode->link = previous->link;
        previous->link = newNode;
    }


    Node<T>* getNode(int nodePosition)
    {
        Node<T>* current = new Node<T>;
        current = first;
        int i = 0;
        while (i < nodePosition)
        {
            current = current->link;
            i++;
        }
        return current;
    }

    bool search(const T& targetValue)
    {
        Node<T>* currentNode = first; 
        bool found = false; 

        while (currentNode != nullptr && !found)
        {
            if (currentNode->data == targetValue)
            {
                found = true; 
            }

            else
            {
                currentNode = currentNode->link;
            }
        } //end while

        return found; 
    }

    void deleteNodeWithInfo(const T& infoToDelete)
    {
        Node<T>* current;
        Node<T>* temp;
        bool found;

        if (first->data == infoToDelete)
        {
            found = true;
            current = first;
            first = first->link;

            delete current;

            nodeCount--;
        }

        else //this means that the data we want to delete is NOT in 
            //the first node (and this includes the possiblity that the data
            //is not in the list at all!) 
        {
            found = false; //so far
            temp = first;

            current = first->link; //advance to next node

            while (current != NULL and !found) {
                if (current->data != infoToDelete) {
                    temp = current;//advance both along the “chain”
                    current = current->link;
                }
                else {
                    found = true;
                }
            } //end while

            if (found)
            {

                if (last == current)
                    //make sure last doesn't get “lost”
                {
                    last = temp;
                }


                delete current;

                nodeCount--;
            }

            else
            {
                cout << "The value " << infoToDelete << " was NOT found :(\n";
            }


        } //end else (target value is NOT in the first node) 
    }
}; //end `LInkedList` class def: 

int main()
{

    //forward_list<int> flObject; 
    //flObject.

    LinkedList<int>* pointerToFrontOfList = new LinkedList<int>; 
    pointerToFrontOfList->insertFirst(5);
    pointerToFrontOfList->insertFirst(4);
    pointerToFrontOfList->insertFirst(2);
    pointerToFrontOfList->insertFirst(1);

    cout << "The contents of the integer list BEFORE inserting in the middle: " << endl;
    pointerToFrontOfList->traverseList(); 
    
    auto previousNode = pointerToFrontOfList->getNode(1);
    pointerToFrontOfList->insertAfter(previousNode, 3);
        
   cout << "\n\nThe contents of the integer list AFTER inserting in the middle: " << endl;
   pointerToFrontOfList->traverseList(); 


   int targetElement = 1; //an "edge case" (a term in software development) 
                        //
   cout << "Is the element " << targetElement << " in this list? " << endl; 
   cout << std::boolalpha; 
   cout << pointerToFrontOfList->search(targetElement) << endl; 
   //std::find()
   

   const int VALUE_TO_DELETE = 4; 
   cout << "can we successfully erase the NODe containing the value"
       << VALUE_TO_DELETE << " ?\n ";

   pointerToFrontOfList->deleteNodeWithInfo(VALUE_TO_DELETE); //deletes FRONT node

   pointerToFrontOfList->traverseList(); 


    //firstNode.

/*
    LinkedList <string> firstAirport; //this will call the default constructor 
    firstAirport.insertFirst("LAX");
    firstAirport.insertFirst("Atlanta");
    firstAirport.insertFirst("Chicago");


    cout << "Was the number of nodes updated correctly? " << endl; 
    cout << firstAirport.length() << endl; 

    firstAirport.traverseList(); 

    //Node<string>* firstNode; 

    //cout << firstNode.link->data << endl; 

    //Node<string> firstAirport;

    //firstAirport.data = "Los Angeles"; 
    //firstAirport.link = nullptr; 

    //Node<string> secondAirport; 
    //secondAirport.data = "Atlanta";
    //

    //firstAirport.link = &secondAirport; 

    //Node<string> thirdAirport; 
    //thirdAirport.data = "Chicago";

    //thirdAirport.link = nullptr; 

    //secondAirport.link = &thirdAirport; 

    ////print the nodes in order: 
    //traverseList(firstAirport); 
    /*
    cout << firstAirport.data << endl; 
    cout << secondAirport.data << endl; 
    cout << thirdAirport.data << endl; 
    */
    

    //Node<string> head; 
    //head.data = "PI";
    ////quizQuestion2FirstNode.link = nullptr; //explicitly iniitalizing 

    //Node<string> current = head; 


    //Node<string> secondNode;
    //secondNode.data = "Euler's number"; 
    //secondNode.link = nullptr; 

    //update first node's link: 
   // head.link = &secondNode; 

   // //cout << head.link->data << endl; 


   // Node<string> tail; 
   // tail.data = "golden ratio";
   // tail.link = nullptr; 

   // secondNode.link = &tail; 


   // cout << "Q1: " << head.link->link << endl; 
   // cout << "Q2: " << head.link->data << endl; 

   // traverseList(head); 


   //Node firstNode;
   // firstNode.data = 1; 
   // firstNode.link = nullptr; //nullptr is 0x0000 0000 0000 0000 

   // Node secondNode; 
   // secondNode.data = -42; 
   // secondNode.link = nullptr; 

   // //update the link of firstNode
   // firstNode.link = &secondNode; 

   // cout << "first node's data: " << firstNode.data << endl; 
   // cout << "SECOND node's data: " << secondNode.data << endl; 
   // 
   // cout << "a less direct approach to getting second node's data: "
   //     << firstNode.link->data << endl; 


    //Node thirdNode; 
    //thirdAirport.data = 12345; 
    //thirdAirport.link = nullptr; 

    //secondNode.link = &thirdAirport;
    //int a = 32; 


    //int thirdNodesData = firstNode.link->link->data; 
    //cout << "12345? " << thirdNodesData << endl; 
    //int* pointerToA = &a; 

    //cout << pointerToA << "\t" << *pointerToA << endl; 

    //cout << nullptr << endl; 
    
    //cout << &nullptr << endl;// NULL << endl;
   
   

    
    return 0;
}