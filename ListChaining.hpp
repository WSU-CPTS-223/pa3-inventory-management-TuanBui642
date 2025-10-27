/*
    Name: Tuan Bui
    Date: 10/25/25
    Program: PA3, Inventory Management
*/

#ifndef LISTCONTAINER
#define LISTCONTAINER

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

#include "NodeChaining.hpp"
#include "ProductClass.hpp"

template <typename Value> //Value is Nodes that are templated with product class
class ContainerList{
    public:
            ContainerList(); //Constructor

            Node<Value>* GetHeadPointer();//Getters
            Node<Value>* GetTailPointer();

            void SetHeadPointer(Node<Value>* NewHeadPointer); //Setters
            void SetTailPointer(Node<Value>* NewTailPointer);

            //Print/Display all
            int TraverseLinkedListPRINT();

            //Insert to list
            void AddToList(Node<Value>* NewNode);

            //Read from csv File, populate likedList
            void PopulateLinkedList(ifstream &FileName,  ProductElements& NewData);

            ~ContainerList(); //Destructor


    private:

            Node<Value>* HeadPointer;
            Node<Value>* TailPointer;
};

template <typename Value> 
    ContainerList<Value>::ContainerList(){ //Sets both headptr and tailptr to nullptr

        this->HeadPointer = nullptr;
        this->TailPointer = nullptr;
    }

    template <typename Value> 
    Node<Value>* ContainerList<Value>::GetHeadPointer(){

        return this->HeadPointer;
    }

template <typename Value> 
    Node<Value>* ContainerList<Value>::GetTailPointer(){

        return this->TailPointer;
    }

template <typename Value> 
    void ContainerList<Value>::SetHeadPointer(Node<Value>* NewHeadPointer){

        this->HeadPointer = NewHeadPointer;
    }

template <typename Value> 
    void ContainerList<Value>::SetTailPointer(Node<Value>* NewTailPointer){

        this->TailPointer = NewTailPointer;
    }

    template <typename Value> 
    ContainerList<Value>::~ContainerList(){

        if (this->HeadPointer == this->TailPointer){

            this->HeadPointer = nullptr;
            this->TailPointer = nullptr;
        }
        else{

            Node<Value>* traverse = this->GetHeadPointer();
            
            while (traverse != nullptr ){

                Node<Value>* DeletePtr = traverse;
                traverse = traverse->GetNextPtr();
                delete DeletePtr;
            }

            this->HeadPointer = nullptr;
            this->TailPointer = nullptr;
        }
    }

template <typename Value> 
    int ContainerList<Value>::TraverseLinkedListPRINT(){

        Node<Value>* TempPtr = nullptr;

        if(this->HeadPointer == nullptr){

            cout << "List is Empty" << endl;
            return 0;
        }
        else {

            TempPtr = this->HeadPointer;

            while (TempPtr != nullptr){

                cout << TempPtr->GetData() << endl;

                TempPtr = TempPtr->GetNextPtr();
            }
        }

        return 1;
    }

//Insert to list
template <typename Value> 
void ContainerList<Value>::AddToList(Node<Value>* NewNode){

    if(this->HeadPointer == nullptr){ //Empty list

        this->HeadPointer = NewNode;
        this->TailPointer = NewNode;
    }
    else{ //Not empty, insert at end

        Node<Value>* tempPtr = this->TailPointer;
        tempPtr->SetNextPtr(NewNode);
        this->TailPointer = this->TailPointer->GetNextPtr();

    }
}


#endif