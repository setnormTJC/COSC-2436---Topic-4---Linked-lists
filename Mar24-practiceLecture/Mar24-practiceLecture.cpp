#include <iostream>
#include <string>

using std::cout; 
using std::cin; 
using std::endl; 
using std::string;

template <typename T>
struct Node
{
	T info;
	Node <T>* link;//often called “next” for singly-linked list
};

template <typename T>
class LinkedList
{
public: 
//private:
	int nodeCount; //not mandatory, but convenient 
	Node<T>* first;
	Node<T>* last;


public:
	LinkedList()
	{
		nodeCount = 0;
		first = NULL; //or nullptr keyword, or 0
		last = NULL;
	}

	void print() {
		Node<T>* current;
		current = first;
		while (current != NULL) {
			cout << current->info << endl;
			current = current->link;
		}
	}//end print() function 

	int length()
	{
		return nodeCount;
	};

	void insertFirst(const T& newInfo)
	{
		Node<T>* newNode = new Node<T>;
		newNode->info = newInfo;
		newNode->link = first; //inserts newNode at front (AKA: push_front in <list>)

		first = newNode;

		if (last == NULL)
		{
			cout << "last was null!\n";
			last = newNode;
		}

		nodeCount++;

	};

	void insertAfter(Node<T>* previous, const T& insertedValue)
	{
		Node<T>* newNode = new Node<T>;
		newNode->info = insertedValue;

		newNode->link = previous->link;
		previous->link = newNode;
	};

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

	void deleteNodeWithInfo(const T& infoToDelete)
	{
		Node<T>* current;
		Node<T>* temp;
		bool found;


		//...


	}
	
};//end LinkedList class def




int main()
{
	LinkedList<string>* ll = new LinkedList<string>; 
	ll->insertFirst("Alice");
	ll->insertFirst("Carol");
	ll->insertFirst("Darth"); 

	
	ll->print();

	Node<string>* previous = ll->getNode(1); 
	//ll->insertAfter(previous, "Bob");
	ll->insertAfter(ll->first->link, "Bob");


	cout << "\n\nafter inserting bob: \n";
	ll->print(); 


	return 0; 
}