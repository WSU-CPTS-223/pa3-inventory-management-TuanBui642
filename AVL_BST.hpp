/*
    Name: Tuan Bui
    Date: 10/25/25
    Program: PA3, Inventory Management
*/

#ifndef BINARYSEARCHTREE
#define BINARYSEARCHTREE

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <stack>

using std::cout; // cout <<
using std::endl; // endl
using std::string;
using std::cin;
using std::ostream;
using std::ifstream;
using std::ofstream;
using std::list;

#include "BSTNode.hpp"

template<typename Key, typename Value>
class AVL_MAP_BST {

public:
	//Constructor
	AVL_MAP_BST();

	//Getter for Root Node
	BSTnode<Key,Value>* GetRootNode() const;
	int GetBalancedFactor() const;
	int GetLeftBalancedFactor() const;
	int GetRightBalancedFactor() const;

	//Setter for Root Node
	void SetRootNode(BSTnode<Key,Value>* NewRootNode);
	void SetBalancedFactor(int NewBalancedFactor);
	void SetRightBalancedFactor(int NewNum);
	void SetLeftBalancedFactor(int NewNum);

	//Destructor
	~AVL_MAP_BST();

	//Public functions to call a private function to do their respective functionalites
	void traversalPrint() const;
	void traversalSearch(Key SearchValue) const; 
	//BSTnode<Key,Value>* insert(Key NewKey, Value NewValue, BSTnode<Key,Value>* pTree);

	//NOTE: Given Function Declarations from Rubric
    void insertGiven(const Key& key, const Value& value); // Inserts key-value pair
    BSTnode<Key,Value>* eraseGiven(BSTnode<Key,Value>* Node, const Key& key); // Removes key-value pair
	void Erase( const Key& key);
    //iterator findGiven(const Key& key); // Returns an iterator

	void UpdateHeight(BSTnode<Key,Value>* GivenNode);
	int CalculateBalance(BSTnode<Key,Value>* Node);

	//Finds max/min that is below a given node (i.e. furthest left/right down)
	BSTnode<Key,Value>* FindMin(BSTnode<Key,Value>* Node);
	BSTnode<Key,Value>* FindMax(BSTnode<Key,Value>* Node);

	//Rotations
	BSTnode<Key,Value>*  RightRotation(BSTnode<Key,Value>* ImbalancedNode);
	BSTnode<Key,Value>*  LeftRotation(BSTnode<Key,Value>* ImbalancedNode);

	BSTnode<Key,Value>* RightLeftRotation(BSTnode<Key,Value>* ImbalancedNode);
	BSTnode<Key,Value>*  LeftRightRotation(BSTnode<Key,Value>* ImbalancedNode);

private:
	//Private functions to execute respective functionalities, called by public functions
	BSTnode<Key,Value>* insert(Key NewKey, Value NewValue, BSTnode<Key,Value>* pTree);

	void traversalPrint(BSTnode<Key,Value>* pTree) const;
	void traversalSearch(BSTnode<Key,Value>* pTree, Key SearchValue) const;
	void destroyTreeTraverse(BSTnode<Key,Value>* pTree);

	BSTnode<Key,Value>* RootNode;
	int balancedFactor;

};

template<typename Key, typename Value>
AVL_MAP_BST<Key,Value>::AVL_MAP_BST(){ //Constructor, sets rootnode to nullptr

	this->RootNode = nullptr;
}

template<typename Key, typename Value> 
BSTnode<Key,Value>* AVL_MAP_BST<Key,Value>::GetRootNode() const{ //Getter for root node

	return this->RootNode;
}

template<typename Key, typename Value> 
int AVL_MAP_BST<Key,Value>::GetBalancedFactor() const{

	return this->balancedFactor;
}

template<typename Key, typename Value> 
int AVL_MAP_BST<Key,Value>::CalculateBalance(BSTnode<Key,Value>* Node){

	if(Node == nullptr){

		return 0;
	}
	else {
		int Left = -1; //Set to -1 to avoid issue with minusing one another and then getting the wrong output in the end
		int Right = -1;

		if (Node->GetLeft() != nullptr){
			Left = Node->GetLeft()->GetHeight();
		}
		if (Node->GetRight() != nullptr){
			Right = Node->GetRight()->GetHeight();
		}

		int balance = Left - Right;
		this->SetBalancedFactor(balance);

		return balance;
	}
}

template<typename Key, typename Value> 
int AVL_MAP_BST<Key,Value>::GetLeftBalancedFactor() const{

	return this->LeftBalancedFactor;
}

template<typename Key, typename Value> 
int AVL_MAP_BST<Key,Value>::GetRightBalancedFactor() const{

	return this->RightBalancedFactor;
}

template<typename Key, typename Value> 
void AVL_MAP_BST<Key,Value>::SetRightBalancedFactor(int NewNum){

	this->RightBalancedFactor = NewNum;
}

template<typename Key, typename Value> 
void AVL_MAP_BST<Key,Value>::SetLeftBalancedFactor(int NewNum){

	this->LeftBalancedFactor = NewNum;
}

template<typename Key, typename Value> 
void AVL_MAP_BST<Key,Value>::SetBalancedFactor(int NewBalancedFactor){

	this->balancedFactor = NewBalancedFactor;
}

template<typename Key,typename Value> 
void AVL_MAP_BST<Key,Value>::SetRootNode(BSTnode<Key,Value>* NewRootNode){ //Sets current root node to new root node

	this->RootNode = NewRootNode;
}

template<typename Key,typename Value> 
AVL_MAP_BST<Key,Value>::~AVL_MAP_BST(){ //Destructor calls a function to destroy/delete the entirity of the tree

	destroyTreeTraverse(this->RootNode); //Calls private function to delete
	this->RootNode = nullptr;
}

template<typename Key,typename Value> 
void AVL_MAP_BST<Key,Value>::UpdateHeight(BSTnode<Key,Value>* GivenNode){

	if(GivenNode->GetLeft() != nullptr && GivenNode->GetRight() != nullptr){ //Both aren't empty nodes ptrs

		if(GivenNode->GetLeft()->GetHeight() > GivenNode->GetRight()->GetHeight()){

			GivenNode->SetHeight(GivenNode->GetLeft()->GetHeight() + 1);
		}
		else{
			GivenNode->SetHeight(GivenNode->GetRight()->GetHeight() + 1);
		}
	}
	else if (GivenNode->GetLeft() == nullptr && GivenNode->GetRight() != nullptr) {//Right has node, left is empty

		GivenNode->SetHeight(GivenNode->GetRight()->GetHeight() + 1);
	}
	else if (GivenNode->GetLeft() != nullptr && GivenNode->GetRight() == nullptr){ //Left has node, right is empty

		GivenNode->SetHeight(GivenNode->GetLeft()->GetHeight() + 1);
	}
	else{ //Leaf Node essentially, height = 0

		GivenNode->SetHeight(0);
	}
}

template<typename Key,typename Value> 
BSTnode<Key,Value>* AVL_MAP_BST<Key,Value>::RightRotation(BSTnode<Key,Value>* ImbalancedNode){ 

	//Instantiate Temp1 and Temp2 to be equal to Imbalances left and typically another node or nulllptr
	BSTnode<Key,Value>* Temp1 = ImbalancedNode->GetLeft(); 
	BSTnode<Key,Value>* Temp2 = Temp1->GetRight();

	//Switching around nodes to be balanced
	Temp1->SetRight(ImbalancedNode);
	ImbalancedNode->SetLeft(Temp2);

	//Updating Heights for the moved nodes (Temp2/Node2 doesn't move all the time (i.e. situation == nullptr))
	UpdateHeight(ImbalancedNode);
	UpdateHeight(Temp1);

	return Temp1;
}

template<typename Key,typename Value> 
BSTnode<Key,Value>* AVL_MAP_BST<Key,Value>::LeftRotation(BSTnode<Key,Value>* ImbalancedNode){

	//Instantiate Temp1 and Temp2 to be equal to Imbalances left and typically another node or nulllptr
	BSTnode<Key,Value>* Temp1 = ImbalancedNode->GetRight();
	BSTnode<Key,Value>* Temp2 = Temp1->GetLeft();

	//Switching around nodes to be balanced
	Temp1->SetLeft(ImbalancedNode);
	ImbalancedNode->SetRight(Temp2);

	//Updating Heights for the moved nodes (Temp2/Node2 doesn't move all the time (i.e. situation == nullptr))
	UpdateHeight(ImbalancedNode);
	UpdateHeight(Temp1);

	return Temp1;
}

template<typename Key,typename Value> 
BSTnode<Key,Value>*  AVL_MAP_BST<Key,Value>::RightLeftRotation(BSTnode<Key,Value>* ImbalancedNode){ //Same Idea as single rotations, but double it in rotations in opposite directions

	BSTnode<Key,Value>* Temp = RightRotation(ImbalancedNode->GetRight());
	ImbalancedNode->SetRight(Temp);

	BSTnode<Key,Value>* Temp2 = LeftRotation(ImbalancedNode);

	return Temp2;
}

template<typename Key,typename Value> 
BSTnode<Key,Value>*  AVL_MAP_BST<Key,Value>::LeftRightRotation(BSTnode<Key,Value>* ImbalancedNode){ //Same Idea as single rotations, but double it in rotations in opposite directions


	BSTnode<Key,Value>* Temp = LeftRotation(ImbalancedNode->GetLeft());
	ImbalancedNode->SetLeft(Temp);

	BSTnode<Key,Value>* Temp2 = RightRotation(ImbalancedNode);

	return Temp2;
}

template<typename Key,typename Value> 
void AVL_MAP_BST<Key,Value>::destroyTreeTraverse(BSTnode<Key,Value>* pTree){

	if (pTree == nullptr){ //Tree is empty

		return;
	}
	else{
		//Post Order deleition
		destroyTreeTraverse(pTree->GetLeft());
		destroyTreeTraverse(pTree->GetRight());
		delete pTree;
	}
}

template<typename Key,typename Value> 
void AVL_MAP_BST<Key,Value>::insertGiven(const Key& key, const Value& value){ //Wrapper Function for insert

	this->RootNode = insert(key,value, this->RootNode);
}

template<typename Key,typename Value> 
BSTnode<Key,Value>* AVL_MAP_BST<Key,Value>::insert(Key NewKey, Value NewValue, BSTnode<Key,Value>* pTree){

	if (pTree == nullptr) { //Case where tree is empty

		BSTnode<Key,Value>* New = new BSTnode<Key,Value>();

		New->SetProductClass(NewValue);
		New->SetUniqueID(NewKey);
		New->SetHeight(0); //Rootnode height is zero

		return New;
	}
	else { //Tree is not empty

		if (NewKey < pTree->GetUniqueID()) {//Traversal depending on the character, Going left

			if (pTree->GetLeft() == nullptr) {//Case where the ptr left is pointing to NOTHING

				BSTnode<Key,Value>* New = new BSTnode<Key,Value>();

				New->SetProductClass(NewValue);
				New->SetUniqueID(NewKey);
				New->SetHeight(0); //New Leaf Node is always height 0
				pTree->SetLeft(New);
				cout << "Inserted Left" << endl;
				
			}
			else { //Continue traversal down 

				pTree->SetLeft(insert(NewKey, NewValue, pTree->GetLeft())); //Continue Traversal
			}
		}
		else if (NewKey > pTree->GetUniqueID() ){ //Traversal depending on the character, Going left

			if(pTree->GetRight() == nullptr) {

				BSTnode<Key,Value>* New = new BSTnode<Key,Value>();

				New->SetProductClass(NewValue);
				New->SetUniqueID(NewKey);
				New->SetHeight(0); //New Leaf Node is always height 0
				pTree->SetRight(New);
				cout << "Inserted Right" << endl;
			}
			else {//Continue traversal down 

				pTree->SetRight(insert(NewKey, NewValue, pTree->GetRight())); //Continue Traversal
			}
		}
		else{ //Duplicate scenario

			return pTree;
		}

		UpdateHeight(pTree); //Updates height of new node (insert node)

		int balance = CalculateBalance(pTree);
		cout << "Balance: " << balance << endl;
		if (balance < -1) {//Right Heavy

			if(pTree->GetRight() != nullptr){

				if(NewKey > pTree->GetRight()->GetUniqueID()){ //LL Rotation
					//cout << "Right Rotations Before" << endl;
					pTree = LeftRotation(pTree);
					//cout << "Right Rotations" << endl;
				}
				else{ //LR Rotation
					//cout << "Right Left Rotations Before" << endl;
					pTree = RightLeftRotation(pTree);
					//cout << "Right Rotations" << endl;
				}
			}
			
		}
		else if (balance > 1){ //Left Heavy

			if(pTree->GetLeft() != nullptr){

				
				if(NewKey < pTree->GetLeft()->GetUniqueID()){ //RR Rotation
					//cout << "Left Rotations Before" << endl;
					pTree = RightRotation(pTree);
					//cout << "Left Rotations" << endl;
				}
				else{ //RL Rotation
					//cout << "Left Right Rotations Before" << endl;
					pTree = LeftRightRotation(pTree);
					//cout << "Left Rotations" << endl;
				}
			}
			
		}
		else if (balance == 0){ //Perfectly Balanced

			return pTree;
		}
	}

	return pTree;
}

template<typename Key,typename Value> 
void AVL_MAP_BST<Key,Value>::traversalPrint() const{ //A function to call another function to print

	traversalPrint(this->RootNode); //Private function to traverse and print it
}

template<typename Key,typename Value> 
void AVL_MAP_BST<Key,Value>::traversalPrint(BSTnode<Key,Value>* pTree) const{ //Inorder traversal to print the binary search tree

	if(pTree != nullptr){

		traversalPrint(pTree->GetLeft());
		cout << pTree->GetProductClass() << endl << endl; //Prints here using UScity's overloaded operator function
		traversalPrint(pTree->GetRight());
	}

}

template<typename Key,typename Value> 
void AVL_MAP_BST<Key,Value>::traversalSearch(Key SearchValue) const { //Search function that calls the private search function to search for given value

	BSTnode<Key,Value>* Traverse = this->RootNode;
	traversalSearch(Traverse, SearchValue);
}

template<typename Key, typename Value>
void AVL_MAP_BST<Key,Value>::traversalSearch(BSTnode<Key,Value>* pTree, Key SearchValue) const {

	if(pTree == nullptr){ //Can also be a not found condition as the traverse would keep traversing till nullptr (i.e. not in bst)

		cout << "Tree is empty/Not found given search value" << endl;
	}
	else{

		if(pTree->GetUniqueID() > SearchValue){ //Traverse left 

			traversalSearch(pTree->GetLeft(), SearchValue);
		}
		else if (pTree->GetUniqueID() < SearchValue){ //Traverse Right

			traversalSearch(pTree->GetRight(),SearchValue);
		}
		else if (pTree->GetZipCodeKey() == SearchValue){ //Found

			cout << "Found: " << pTree->GetUniqueID() << endl;
		}
	}

}

template<typename Key, typename Value>
void AVL_MAP_BST<Key,Value>::Erase(const Key& key){

	this->RootNode = eraseGiven(this->RootNode, key);
}

template<typename Key, typename Value>
BSTnode<Key,Value>* AVL_MAP_BST<Key,Value>::eraseGiven(BSTnode<Key,Value>* Node, const Key& key){ // Removes key-value pair

	BSTnode<Key,Value>* Temp2 = nullptr;

	if(Node->GetUniqueID() > key){ //Traverse down left of tree

		Node->SetLeft(eraseGiven(Node->GetLeft(), key));
	}
	else if (Node->GetUniqueID() < key){ //Traverse down right of tree

		Node->SetRight(eraseGiven(Node->GetRight(), key));
	}
	else if (Node->GetUniqueID() == key){ //Found!

		if(Node->GetRight() == nullptr && Node->GetLeft() == nullptr) {//Leaf Node, Can delete

			delete Node;
			return nullptr;
		}
		else if (Node->GetRight() == nullptr && Node->GetLeft() != nullptr){ //Right Empty, Left Exists

			Temp2 = Node->GetLeft(); //Temp ptr set to the child so we don't lose it (memory leak)
			delete Node; //Delete Node
			return Temp2;
		}
		else if (Node->GetRight() != nullptr && Node->GetLeft() == nullptr){ //Left empty, Right exists

			Temp2 = Node->GetRight(); //Temp ptr set to the child so we don't lose it (memory leak)
			delete Node; //Delete Node
			return Temp2;
		}
		else if (Node->GetRight() != nullptr && Node->GetLeft() != nullptr){ //Both Childs exists

			BSTnode<Key,Value>* TempNewNode = FindMin(Node->GetRight()); //We want to find the min that's in the greater than subtree to replace deletion node.
			
			//Update Current node with new node's data (i.e. replace)
			Node->SetProductClass(TempNewNode->GetProductClass());
			Node->SetUniqueID(TempNewNode->GetUniqueID());
			Node->SetRight(eraseGiven(Node->GetRight(), TempNewNode->GetUniqueID()));
		}

		if(Node != nullptr){ //Avoids height update for deleted leaf node

			UpdateHeight(Node);

			int balance = CalculateBalance(Node);

			if (balance < -1) {//Right Heavy

				if(Node->GetRight() != nullptr){

					if(key > Node->GetRight()->GetUniqueID()){ //LL Rotation

						Node = LeftRotation(Node);
					}
					else{ //RL Rotation

						Node = RightLeftRotation(Node);
					}
				}
			}
			else if (balance > 1){ //Left Heavy

				if(Node->GetLeft() != nullptr){

					if(key < Node->GetLeft()->GetUniqueID()){ //RR Rotation

						Node = RightRotation(Node);
					}
					else{ //LR Rotation
						Node = LeftRightRotation(Node);
					}
				}
			}
		}
	}
	else{
		cout << "Key Could Not be Found" << endl;
		return nullptr;
	}

	return Node;
}

template<typename Key, typename Value>
BSTnode<Key,Value>* AVL_MAP_BST<Key,Value>::FindMin(BSTnode<Key,Value>* Node){ //Traverses down a subtree for it's min value

	BSTnode<Key,Value>* Temp = Node;

	while(Temp->GetLeft() != nullptr){

		Temp = Temp->GetLeft();
	}

	return Temp;
}

template<typename Key, typename Value>
BSTnode<Key,Value>* AVL_MAP_BST<Key,Value>::FindMax(BSTnode<Key,Value>* Node){//Traverses down a subtree for it's max value

		BSTnode<Key,Value>* Temp = Node;

	while(Temp->GetRight() != nullptr){

		Temp = Temp->GetRight();
	}

	return Temp;
}

#endif