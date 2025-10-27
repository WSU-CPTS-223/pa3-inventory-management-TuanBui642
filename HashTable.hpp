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

using std::cout; // cout <<
using std::endl; // endl
using std::string;
using std::cin;
using std::ostream;
using std::ifstream;
using std::ofstream;
using std::vector;
using std::pair;

template<typename T> //T = List/node so then we have a vector of linked list and int as index/key
class HashTable{

    public:
        HashTable(int size);
        void Insert(int IndexPlacement, const T& Data);
        

    private:
        vector<ContainerList<T>> H_table; //T = headptr of each linked lists

};

template<typename T>
HashTable<T>::HashTable(int size){

    this->H_table.resize(size);
    

}

template<typename T>
void HashTable<T>::Insert(int IndexPlacement, const T& Data){
    Node<T>* NewNode = new Node<T>;

    NewNode->SetData(Data);

    H_table[IndexPlacement].AddToList(NewNode);

}

#endif