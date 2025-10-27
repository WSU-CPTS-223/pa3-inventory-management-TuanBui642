/*
    Name: Tuan Bui
    Date: 10/25/25
    Program: PA3, Inventory Management
*/

#ifndef NODECONTAINER
#define NODECONTAINER

#include <iostream>
#include <fstream>
#include <string>

using std::cout; // cout <<
using std::endl; // endl
using std::string;
using std::cin;
using std::ostream;
using std::ifstream;
using std::ofstream;
using std::pair;

template<typename Value> //Value = Product Class
class Node{
    public:

    Value& GetData();
    void SetData(Value NewData);

    Node* GetNextPtr();
    void SetNextPtr(Node<Value>* NewPtrNext);

    private:
    Value Data;
    Node<Value>* PtrNext = nullptr;
};

    template <typename Value>
     Value& Node<Value>::GetData(){

        return this->Data;
     }

     template <typename Value>
     void Node<Value>::SetData(Value NewData){

        this->Data = NewData;
     }

     template <typename Value>
     Node<Value>* Node<Value>::GetNextPtr(){

        return this->PtrNext;
     }

     template <typename Value>
     void Node<Value>::SetNextPtr(Node<Value>* NewPtrNext){

        this->PtrNext = NewPtrNext;
     }




#endif