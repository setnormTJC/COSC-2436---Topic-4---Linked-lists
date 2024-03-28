#include <iostream>

#include"C:/Users/Work/Downloads/LinkedList.h"

using namespace std;


struct Song
{
    //public: 

    string composerName;
    string songName;

    Song() {};
    Song(string composerName, string songName)
        :composerName(composerName),
        songName(songName)
    {
    }

    bool operator == (const Song& otherSong)
    {
        return (this->composerName == otherSong.composerName
            &&
            this->songName == otherSong.songName);

    }

    bool operator != (const Song& otherSong)
    {
        return

            !((this->composerName == otherSong.composerName
            &&
            this->songName == otherSong.songName));
    }

    friend ostream& operator << (ostream& os, const Song& songObj);
};


ostream& operator << (ostream& os, const Song& songObj)
{
    os << songObj.composerName << "\t" << songObj.songName << endl; 

    return os; 
}

int main()
{
    
    unorderedLinkedList<Song> songsList; 
    songsList.insertFirst(Song{ "Beethoven", "Rage over a lost penny" });
    Song secondSong{ "Nickelback", "How you remind me" };

    songsList.insertFirst(secondSong);

    songsList.insertFirst(Song{ "Debussy", "La fille aux cheveux de lin" });

    cout << "Initial playlist contents: \n";
    songsList.print(); 


    cout << "Back method returns: " << endl; 
    cout << songsList.back() << endl; 
  
    cout << "Second song in list? : " << endl; 

    auto begin = songsList.begin(); 
    ++begin; 
    
    cout << *begin << endl; 

    songsList.initializeList(); 

    cout << "What did the initilaize list function do? " << endl; 
    cout << songsList.length() << endl; 
    songsList.print(); 

    return 0;
}