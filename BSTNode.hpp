/*
    Name: Tuan Bui
    Date: 10/25/25
    Program: PA3, Inventory Management
*/

#ifndef BSTNODE
#define BSTNODE

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

template<typename Key, typename Value> 
class BSTnode {

public:
	BSTnode();
	BSTnode(const BSTnode<Key,Value>& rhs); 
	BSTnode(const Key & NewKey,const Value & NewValue);

	BSTnode<Key,Value>* GetRight();
	BSTnode<Key,Value>* GetLeft();

	Key GetUniqueID();
	Value GetProductClass();
	int GetHeight();

	void SetUniqueID(const Key &NewKey);
	void SetProductClass(const Value &NewValue);
	void SetHeight(int NewHeight);

	void SetRight(BSTnode<Key,Value>* NewRight);
	void SetLeft(BSTnode<Key,Value>* NewLeft);

	int CalculateHeight(BSTnode<Key,Value>* TargetHeightNode);

	~BSTnode();

private:
	BSTnode<Key,Value>* ptrRight, *ptrLeft;
	int Height;
	Key UniqIdentification;
	Value ProductClass;

};

template<typename Key, typename Value>
BSTnode<Key, Value>::BSTnode() { //Default Constructor

	this->ptrRight = nullptr;
	this->ptrLeft = nullptr;
	this->Height = 0;
	this->UniqIdentification = Key();
	this->ProductClass = Value();
}

template<typename Key, typename Value>
BSTnode<Key, Value>::BSTnode(const Key & NewKey,const Value & NewValue){

	this->ptrLeft = nullptr;
	this->ptrRight = nullptr;

	this->SetHeight(0);
	this->SetUSCityValue(NewValue);
	this->SetZipCodeKey(NewKey);

}

template<typename Key, typename Value>
BSTnode<Key, Value>::BSTnode(const BSTnode<Key,Value>& rhs)  {

	this->SetLeft(nullptr);
	this->SetRight(nullptr);

	this->SetHeight(rhs.GetHeight());
	this->SetUSCityValue(rhs.GetUSCityValue());
	this->SetZipCodeKey(rhs.GetZipCodeKey());

	if (rhs.GetRight() != nullptr){
		BSTnode<Key,Value>* Right = new BSTnode<Key,Value>(* rhs.GetRight());
		this->SetRight(Right);
	}

	if (rhs.GetLeft() != nullptr){
		BSTnode<Key,Value>* Left = new BSTnode<Key,Value>(* rhs.GetLeft());
		this->SetLeft(Left);
	}
}

template<typename Key, typename Value>
BSTnode<Key,Value>* BSTnode<Key, Value>::GetRight() { 

	return this->ptrRight;
}

template<typename Key, typename Value>
BSTnode<Key,Value>* BSTnode<Key, Value>::GetLeft() {

	return this->ptrLeft;
}

template<typename Key, typename Value>
Key BSTnode<Key, Value>::GetUniqueID(){

	return this->UniqIdentification;
}

template<typename Key, typename Value>
Value BSTnode<Key, Value>::GetProductClass(){

	return this->ProductClass;
}

template<typename Key, typename Value>
int BSTnode<Key, Value>::GetHeight(){

	return this->Height;
}

template<typename Key, typename Value>
void BSTnode<Key, Value>::SetUniqueID(const Key &NewKey){

	this->UniqIdentification = NewKey;
}

template<typename Key, typename Value>
void BSTnode<Key, Value>::SetProductClass(const Value &NewValue){

	this->ProductClass = NewValue;
}

template<typename Key, typename Value>
void BSTnode<Key, Value>::SetHeight(int NewHeight){

	this->Height = NewHeight;
}
	
template<typename Key, typename Value>
void BSTnode<Key, Value>::SetRight(BSTnode<Key,Value>* NewRight) {

	this->ptrRight = NewRight;
}

template<typename Key, typename Value>
void BSTnode<Key, Value>::SetLeft(BSTnode<Key,Value>* NewLeft) {

	this->ptrLeft = NewLeft;
}

template<typename Key, typename Value>
BSTnode<Key, Value>::~BSTnode() {

}

template<typename Key, typename Value>
int BSTnode<Key, Value>::CalculateHeight(BSTnode<Key,Value>* TargetHeightNode){ //Assuming that it has been inserted already

	if (TargetHeightNode != nullptr){

		int Right = -1, Left = -1;

		if (TargetHeightNode->GetRight() != nullptr){
			Right = TargetHeightNode->GetRight()->GetHeight();
		}
		if (TargetHeightNode->GetLeft() != nullptr){
			 Left = TargetHeightNode->GetLeft()->GetHeight();
		}
		if (Left > Right){

			return Left + 1;
		}
		else {
			return Right + 1;
		}
	}

	return -1;
}


#endif