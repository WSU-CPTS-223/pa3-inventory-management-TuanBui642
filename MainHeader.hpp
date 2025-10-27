/*
    Name: Tuan Bui
    Date: 10/25/25
    Program: PA3, Inventory Management
*/

#ifndef MAINHEADER
#define MAINHEADER

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stack>
#include <sstream>
#include <cstdlib>
#include <map>
#include <list>
#include <stdlib.h>
#include <cstdlib>
#include <chrono>

#include "HashTable.hpp"
#include "AVL_BST.hpp"
#include "BSTNode.hpp"
#include "ProductClass.hpp"
#include "ListChaining.hpp"
#include "NodeChaining.hpp"

using std::cout; // cout <<
using std::endl; // endl
using std::string;
using std::cin;
using std::ostream;
using std::ifstream;
using std::ofstream;
using std::vector;
using std::stack;
using std::clock;

using std::ifstream; //Writing
using std::ofstream; //Reading
using namespace std;

void printHelp();
bool validCommand(string line);
void evalCommand(string line);
int NumToASCII(string ConversionString);


template<typename T, typename V, typename I> //T = Node, V = Value, K = Key
void bootStrap(HashTable<T>& Table, AVL_MAP_BST<I,V>& AVLTREE)
{
    cout << "\n Welcome to Amazon Inventory Query System" << endl;
    cout << " enter :quit to exit. or :help to list supported commands." << endl;
    cout << "\n> ";

   //HashTable<ContainerList<ProductElements>> Table(1000000);

    ifstream ReadFile("marketing_sample_for_amazon_com-ecommerce_20200101_20200131_10k_data-1.csv");
    //AVL_MAP_BST<int,ProductElements> AVLTREE;

    if(ReadFile.is_open()== true){ //File is open successfully
        cout << "File is open successfully" << endl;

        string FileLine;
        int Iterations = 1;
        while(getline(ReadFile, FileLine)){ //Continue Parsing through csv and populating the AVL BST

            cout << FileLine << endl;

            int ASCIINum = 0;
            //INitialized variables for holding values
            string InitUniqueID = "";
            string InitProductName = "";
            string InitBrandName = "";
            string InitAsin = "";
            string InitCategory = "";
            string InitUpcEanCode = "";
            string InitListPrice = "";
            string InitSellingPrice = "";
            string InitQuantity = "";
            string InitModelNumber = "";
            string InitAboutProduct = "";
            string InitProductSpecificiations = "";
            string InitTechnicalDetails = "";
            string InitShippingWeight = "";
            string InitProductDimensions = "";
            string InitImage = "";
            string Initvariants = "";
            string Initsku = "";
            string InitProductURL = "";
            string Initstock = "";
            string InitProductDetails = "";
            string InitDimensions = "";
            string InitColor = "";
            string InitIngredients = "";
            string InitDirectionToUse = "";
            string InitIsAmazonSeller = "";
            string InitSizeQuantityVarient = "";
            string InitProductDescription = "";
         
            std::istringstream StreamFileLine(FileLine); //Treates FileLine back into a stream format for getline to utilize and parse through commas

            //Get Line from file
            getline(StreamFileLine, InitUniqueID, ',');
            getline(StreamFileLine, InitProductName, ',');
            getline(StreamFileLine, InitBrandName, ',');
            getline(StreamFileLine, InitAsin, ',');
            getline(StreamFileLine, InitCategory, ',');
            getline(StreamFileLine, InitUpcEanCode, ',');
            getline(StreamFileLine, InitListPrice, ',');
            getline(StreamFileLine, InitSellingPrice, ',');
            getline(StreamFileLine, InitQuantity, ',');
            getline(StreamFileLine, InitModelNumber, ',');
            getline(StreamFileLine, InitAboutProduct, ',');
            getline(StreamFileLine, InitProductSpecificiations, ',');
            getline(StreamFileLine, InitTechnicalDetails, ',');
            getline(StreamFileLine, InitShippingWeight, ',');
            getline(StreamFileLine, InitProductDimensions, ',');
            getline(StreamFileLine, InitImage, ',');
            getline(StreamFileLine, Initvariants, ',');
            getline(StreamFileLine, Initsku, ',');
            getline(StreamFileLine, InitProductURL, ',');
            getline(StreamFileLine, Initstock, ',');
            getline(StreamFileLine, InitProductDetails, ',');
            getline(StreamFileLine, InitColor, ',');
            getline(StreamFileLine, InitIngredients, ',');
            getline(StreamFileLine, InitDirectionToUse, ',');
            getline(StreamFileLine, InitIsAmazonSeller, ',');
            getline(StreamFileLine, InitSizeQuantityVarient, ',');
            getline(StreamFileLine, InitProductDescription, ',');
       
            //Initalized respective data classes for AVl tree and hashtable
            Node<ProductElements>* ImportedDataNode = new Node<ProductElements>();
            ProductElements ImportedDataBST;

            ASCIINum = NumToASCII(InitUniqueID);

            //Setting data elements for Node (HashTable)
            ImportedDataNode->GetData().SetUniqueID(InitUniqueID);
            ImportedDataNode->GetData().SetProductName(InitProductName);
            ImportedDataNode->GetData().SetBrandName(InitBrandName);
            ImportedDataNode->GetData().SetAsin(InitAsin);
            ImportedDataNode->GetData().SetNewCategory(InitCategory);
            ImportedDataNode->GetData().SetUpcEanCode(InitUpcEanCode);
            ImportedDataNode->GetData().SetListPrice(InitListPrice);
            ImportedDataNode->GetData().SetSellingPrice(InitSellingPrice);
            ImportedDataNode->GetData().SetQuantity(InitQuantity);
            ImportedDataNode->GetData().SetModelNumber(InitModelNumber);
            ImportedDataNode->GetData().SetAboutProduct(InitAboutProduct);
            ImportedDataNode->GetData().SetProductSpecifications(InitProductSpecificiations);
            ImportedDataNode->GetData().SetTechnicalDetails(InitTechnicalDetails);
            ImportedDataNode->GetData().SetShippingWeight(InitShippingWeight);
            ImportedDataNode->GetData().SetProductDimensions(InitProductDimensions);
            ImportedDataNode->GetData().SetImage(InitImage);
            ImportedDataNode->GetData().SetVariants(Initvariants);
            ImportedDataNode->GetData().SetSku(Initsku);
            ImportedDataNode->GetData().SetProductURL(InitProductURL);
            ImportedDataNode->GetData().SetStock(Initstock);
            ImportedDataNode->GetData().SetProductDetails(InitProductDetails);
            ImportedDataNode->GetData().SetColor(InitColor);
            ImportedDataNode->GetData().SetIngredients(InitIngredients);
            ImportedDataNode->GetData().SetDirectionToUse(InitDirectionToUse);
            ImportedDataNode->GetData().SetIsAmazonUser(InitIsAmazonSeller);
            ImportedDataNode->GetData().SetSizeQuantityVarient(InitSizeQuantityVarient);
            ImportedDataNode->GetData().SetProductDescription(InitProductDescription);
            

            //Setting Data elements for BST nodes for AVL TREE
            ImportedDataBST.SetUniqueID(InitUniqueID);
            ImportedDataBST.SetProductName(InitProductName);
            ImportedDataBST.SetBrandName(InitBrandName);
            ImportedDataBST.SetAsin(InitAsin);
            ImportedDataBST.SetNewCategory(InitCategory);
            ImportedDataBST.SetUpcEanCode(InitUpcEanCode);
            ImportedDataBST.SetListPrice(InitListPrice);
            ImportedDataBST.SetSellingPrice(InitSellingPrice);
            ImportedDataBST.SetQuantity(InitQuantity);
            ImportedDataBST.SetModelNumber(InitModelNumber);
            ImportedDataBST.SetAboutProduct(InitAboutProduct);
            ImportedDataBST.SetProductSpecifications(InitProductSpecificiations);
            ImportedDataBST.SetTechnicalDetails(InitTechnicalDetails);
            ImportedDataBST.SetShippingWeight(InitShippingWeight);
            ImportedDataBST.SetProductDimensions(InitProductDimensions);
            ImportedDataBST.SetImage(InitImage);
            ImportedDataBST.SetVariants(Initvariants);
            ImportedDataBST.SetSku(Initsku);
            ImportedDataBST.SetProductURL(InitProductURL);
            ImportedDataBST.SetStock(Initstock);
            ImportedDataBST.SetProductDetails(InitProductDetails);
            ImportedDataBST.SetColor(InitColor);
            ImportedDataBST.SetIngredients(InitIngredients);
            ImportedDataBST.SetDirectionToUse(InitDirectionToUse);
            ImportedDataBST.SetIsAmazonUser(InitIsAmazonSeller);
            ImportedDataBST.SetSizeQuantityVarient(InitSizeQuantityVarient);
            ImportedDataBST.SetProductDescription(InitProductDescription);

            //ImportedDataNode.SetData(ImportedDataBST);

            Table.Insert(ASCIINum, ImportedDataBST);
            AVLTREE.insertGiven(Iterations, ImportedDataBST);

            Iterations++;
        }


    }
    else {

        cout << "File was not open successfully" << endl;
    }
}


#endif