#include <iostream>

#include<forward_list>

#include<xtree>

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

    //Linked(T value)
    void traverse() {
        Node<T>* current;
        current = first;
        while (current != NULL) {
            cout << current->data << endl;
            current = current->next;
        }
    }//end print() function


    void insertFirst(const T& newInfo)
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

    //insert other "desirable" member functions? 
    void deleteNodeWithInfo(T infoToDelete)
    {
        Node<T>* current;
        Node<T>* temp;
        bool found; //if not found - we might display a message to that effect
        
        if (first->data== infoToDelete)
        {
            found = true;
            current = first;
            first = first->next;
            delete current;
            nodeCount--;
        }

        else //info is NOT in first node
            // OR it is not in the list at all
        {
            found = false; //so far
            temp = first;
            current = first->next;
            while (current != NULL and !found)
            {
                if (current->data != infoToDelete) {
                    temp = current;//advance both along the “chain”
                    current = current->next;
                }
                else 
                {
                    found = true;
                }
            } //end while 

            if (found)
            { //remember, found is a boolean type
                temp->next = current->next;

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
                cout << "The node value " << infoToDelete << " is not in the list!\n";
            }
        } //end of else (data is not in first node (or not in the list at all!))
    } //end func. def. 


    ~LinkedList()
    {
        cout << "Calling destructor for list[0] = " << first->info << endl;
        Node<T>* temp;
        while (first != nullptr)
        {
            temp = first;
            first = first->link;
            delete temp;
        }
        last = nullptr;
        nodeCount = 0;
    }
};

int main()
{
    forward_list<int> fl; 
    
    //fl.erase_after()
    //fl.erase_after(;
    

    LinkedList<int> ll; 
    ll.insertFirst(5); 
    ll.insertFirst(4);
    ll.insertFirst(2);
    ll.insertFirst(1);

    Node <int>* previousNode = ll.getNode(1);

    ll.insertAfter(previousNode, 3); 

    cout << "Was the insertion successful?" << endl; 
    cout << ll.length() << endl; 
    ll.traverse(); 


    cout << "Is the number 1 in the list? " << endl; 
    cout << std::boolalpha; 
    cout << ll.search(1) << endl; 

    const int valueToDelete = -5; 
    cout << "\n\n\ntesting deletion of value: " << valueToDelete << endl; 
    ll.deleteNodeWithInfo(valueToDelete); 
    ll.traverse(); 


    return 0;
}