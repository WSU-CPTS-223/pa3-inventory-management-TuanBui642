/*
    Name: Tuan Bui
    Date: 10/25/25
    Program: PA3, Inventory Management
*/

#ifndef HASHTABLE
#define HASHTABLE

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "ListChaining.hpp"
//#include "MainFunc.cpp"

using std::cout; // cout <<
using std::endl; // endl
using std::string;
using std::cin;
using std::ostream;
using std::ifstream;
using std::ofstream;
using std::vector;
using std::pair;
using std::hash;
using std::istringstream;

template<typename T> //T = List/node so then we have a vector of linked list and int as index/key
class HashTable{

    public:
        HashTable(int size);
        void Insert(int IndexPlacement, const T& Data);
        bool Find(string TargetString);
        void ListInventoryCategory(string TargetCategory);
        int GetSizeOfTable();
        

    private:
        vector<ContainerList<T>> H_table; //T = headptr of each linked lists

};

template<typename T>
HashTable<T>::HashTable(int size){

    this->H_table.resize(size);
}

template<typename T>
void HashTable<T>::Insert(int IndexPlacement, const T& Data){

    Node<T>* NewDataNode = new Node<T>;
    NewDataNode->SetData(Data);

    H_table[IndexPlacement].AddToList(NewDataNode);
}

template<typename T>
bool HashTable<T>::Find(string TargetString){

    size_t sizeoftable = this->H_table.size();
    size_t Hash2;
    hash<string> Hash;
    Hash2 = Hash(TargetString);
    int TargetIndex = static_cast<int>(Hash2 % sizeoftable);
    bool foundState = false;
    Node<T>* traversepointer = this->H_table[TargetIndex].GetHeadPointer();

    if (traversepointer == nullptr){ //Breaks here for not found inputs

        cout << "Given target string of " << TargetString << "could not be found at " << TargetIndex << endl;
        foundState = true;
    }
    else if (traversepointer->GetData().GetUniqueID() == TargetString){ //Sees if the first one is equivalent to target string

        cout << "Target String: " << TargetString << " has been found at index: " << TargetIndex << endl;
        cout << traversepointer->GetData() << endl;
        foundState = true;
    }
    else{

        while(traversepointer != nullptr){

            if(traversepointer->GetData().GetUniqueID() == TargetString){ //Found in linked list container of that index

                 cout << "Target String: " << TargetString << " has been found at index: " << TargetIndex << endl;
                 cout << traversepointer->GetData() << endl;
                 foundState = true;
                 break;
            }
            else{

                traversepointer = traversepointer->GetNextPtr(); //Traverse further down
            }
        }

        if (foundState == false){

            cout << "Given target string of " << TargetString << "could not be found at " << TargetIndex << endl;
        }

    }

    return foundState;
}



template<typename T>
void HashTable<T>::ListInventoryCategory(string TargetCategory){

    int sizeoftable = this->H_table.size();
    

    for (int i = 0; i < sizeoftable; i++){

        Node<T>* traversepointer = this->H_table[i].GetHeadPointer();

            while(traversepointer != nullptr){

                string FullCatagoryOfItem = traversepointer->GetData().GetCategory();
                istringstream FileFullCategoryofitem(FullCatagoryOfItem); //Same idea from parsing, convert back to file line like use for parsing
                string Token;

                while (getline(FileFullCategoryofitem, Token, '|')){ //Loops through the entire categories of the item parsing the individual categories between '|'

                    if (Token.at(0) == ' '){ //Deletes front white space
                        Token.erase(0,1);
                    }
                    if (Token.at(Token.size() - 1 ) == ' '){ //Deletes last white space
                        Token.erase(Token.size() - 1 ,1);
                    }
                    
                    if(Token == TargetCategory){

                        cout << "Found!" << endl;
                        cout << traversepointer->GetData() << endl;
                    }
                }
                
                traversepointer = traversepointer->GetNextPtr(); //Traverse further down   
            }
    }
}

template<typename T>
int HashTable<T>::GetSizeOfTable(){

    return this->H_table.size();

}

#endif