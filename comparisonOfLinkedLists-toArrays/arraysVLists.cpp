#include <iostream>

#include<list> //doubly-linked list (forward_list is "singly-linked" list) 
#include<vector> 


#include<chrono> 

using namespace std;

int main()
{

    vector<int> vecNums; 
    list<int> listNums; 

    for (int i = 0; i < 100'000; i++)
    {
        vecNums.push_back(i); 
        listNums.push_back(i); 
    }

    const int MIDDLE_ELEMENT = 50'000;
    //measure time to search for element in middle ("average" case) for array 
    auto startVectorSearch = std::chrono::high_resolution_clock::now(); 

    std::find(vecNums.begin(), vecNums.end(), MIDDLE_ELEMENT);

    auto endVectorSearch = std::chrono::high_resolution_clock::now(); 

    cout << "Time for vector search of  " << vecNums.size() << " elements :"
         << (endVectorSearch - startVectorSearch).count() << endl; 
    
    //now the time for searching in LIST: 
    auto startListSearch = std::chrono::high_resolution_clock::now();
    std::find(listNums.begin(), listNums.end(), MIDDLE_ELEMENT); 
    auto endListSearch = std::chrono::high_resolution_clock::now();

    cout << "Time for LIST search (of same element and same data structure contents): "
        << (endListSearch - startListSearch).count() << endl; 


    //insert timing of ... insert :)
    
        
    return 0;
}