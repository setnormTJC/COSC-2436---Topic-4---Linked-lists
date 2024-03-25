#include <iostream>

#include<forward_list>

using namespace std;


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

        if (last == nullptr)
        {
            last = newNode; 
        }


        nodeCount++; 
        /*
        * Insert the last bit!
        */



    }

    void insertAfter(Node<T>* previous, const T& insertedValue)
    {
        Node<T>* newNode = new Node<T>;
        newNode->data = insertedValue;

        //Diagram on next slides walks through two lines below:

        newNode->next = previous->next;
        previous->next = newNode;


        nodeCount++; 
    }

    Node<T>* getNode(int nodePosition)
    {

        Node<T>* current = new Node<T>;
        current = first;
        int i = 0;
        while (i < nodePosition)
        {
            current = current->next;
            i++;
        }
        return current;
    }

    int length() 
    {
        return nodeCount;
    }


    bool search(const T& valueToFind)
        //alternative to bool: return the node object or position?
    {
        Node<T>* current = first;

        bool found = false;


        while (current != nullptr && !found)
        {
            if (current->data == valueToFind)
            {
                found = true; 
            }
            else
            {
                current = current->next;
            }
        }

        return found; 
    }
};

int main()
{

    LinkedList<int> ll; 
    ll.insertFirst(5); 
    ll.insertFirst(4);
    ll.insertFirst(2);
    ll.insertFirst(1);

    Node <int>* previousNode = ll.getNode(1);

    ll.insertAfter(previousNode, 3); 

    cout << "Was the insertion successful?" << endl; 
    cout << ll.length() << endl; 
    ll.print(); 


    cout << "Is the number 1 in the list? " << endl; 
    cout << std::boolalpha; 
    cout << ll.search(1) << endl; 

    //std::forward_list<int> fl; 
    //fl.insert_after
    //LinkedList<string>* airportList = new LinkedList<string> ; 

    //cout << "the initial length of the list is: " << airportList->length() << endl;
    //airportList->print();

    //airportList->insertFirst("LAX");
    //airportList->insertFirst("TOY");
    //airportList->insertFirst("LAHORE");

    //cout << "After calling `insertFirst` thrice: " << endl; 

    //airportList->print();

    //cout << "WAS the size (AKA: length or number of nodes) updated? "
    //    << airportList->length() << endl; 


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