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

template<typename T> //T = List/node so then we have a vector of linked list and int as index/key
class HashTable{

    public:
        HashTable(int size);
        void Insert(int IndexPlacement, const T& Data);
        void Find(string TargetString);
        void ListInventoryCategory(string TargetCategory);
        

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
void HashTable<T>::Find(string TargetString){

    int sizeoftable = this->H_table.size();

    hash<string> Hash;
    int TargetIndex = static_cast<int>(Hash(TargetString)) % sizeoftable;
    bool foundState = false;

    if (this->H_table[TargetIndex].GetHeadPointer()->GetData().GetUniqueID() == TargetString){ //Sees if the first one is equivalent to target string

        cout << "Target String: " << TargetString << " has been found at index: " << TargetIndex << endl;
        cout << this->H_table[TargetIndex].GetHeadPointer()->GetData() << endl;
        foundState = true;
    }
    else{

        Node<T>* traversepointer = this->H_table[TargetIndex].GetHeadPointer();

        while(traversepointer != nullptr){

            if(traversepointer->GetData().GetUniqueID() == TargetString){ //Found in linked list container of that index

                 cout << "Target String: " << TargetString << " has been found at index: " << TargetIndex << endl;
                 cout << this->H_table[TargetIndex].GetHeadPointer()->GetData() << endl;
                 foundState = true;
            }
            else{

                traversepointer = traversepointer->GetNextPtr(); //Traverse further down
            }
        }

        if (foundState == false){

            cout << "Given target string of " << TargetString << "could not be found at " << TargetIndex << endl;
        }

    }
}



template<typename T>
void HashTable<T>::ListInventoryCategory(string TargetCategory){

    int sizeoftable = this->H_table.size();

    for (int i = 0; i < sizeoftable; i++){

        if (this->H_table[i].GetHeadPointer() == nullptr){ //Empty Index at hashtable

            //Skip
        }
        else{
            Node<T>* traversepointer = this->H_table[i].GetHeadPointer();

            while(traversepointer != nullptr){

                if(traversepointer->GetData().GetCategory() == TargetCategory){ //Found in linked list container of that index

                    cout << "Category Data has been found at index: " << i << endl;
                    cout << this->H_table[i].GetHeadPointer()->GetData() << endl;
                }
                 else{

                    traversepointer = traversepointer->GetNextPtr(); //Traverse further down
                }
            }
        }



    }



}

#endif