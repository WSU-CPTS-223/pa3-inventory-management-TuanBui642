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
#include <cassert>

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
void evalCommand(string line, HashTable<ProductElements>& Table);
int NumToASCII(string ConversionString);

//Test Functions
void TESTfind();
void TESTinsert();
void TestFindCategory();

template<typename V, typename I> //T = Node, V = Value, K = Key
void bootStrap(HashTable<ProductElements>& Table, AVL_MAP_BST<I,V>& AVLTREE)
{
    //HashTable<ContainerList<ProductElements>> Table(1000000);

    ifstream ReadFile("AmazonMarketingSample.csv");
    //AVL_MAP_BST<int,ProductElements> AVLTREE;

    if(ReadFile.is_open() == true){ //File is open successfully
        cout << "File is open successfully" << endl;

        string FileLine;
        int Iterations = 1;
        while(getline(ReadFile, FileLine)){ //Continue Parsing through csv and populating the AVL BST

            //cout << FileLine << endl;

            int ASCIINum = 0;
            //INitialized variables for holding values
            string InitUniqueID = "";           string InitProductName = "";    string InitBrandName = "";          string InitAsin = "";
            string InitCategory = "";           string InitUpcEanCode = "";     string InitListPrice = "";          string InitSellingPrice = "";
            string InitQuantity = "";           string InitModelNumber = "";    string InitAboutProduct = "";       string InitProductSpecificiations = "";
            string InitTechnicalDetails = "";   string InitShippingWeight = ""; string InitProductDimensions = "";  string InitImage = "";
            string Initvariants = "";           string Initsku = "";            string InitProductURL = "";         string Initstock = "";
            string InitProductDetails = "";     string InitDimensions = "";     string InitColor = "";              string InitIngredients = "";
            string InitDirectionToUse = "";     string InitIsAmazonSeller = ""; string InitSizeQuantityVarient = "";string InitProductDescription = "";
         
            std::istringstream StreamFileLine(FileLine); //Treates FileLine back into a stream format for getline to utilize and parse through commas

            //Get Line from file
            getline(StreamFileLine, InitUniqueID, ',');         getline(StreamFileLine, InitProductName, ',');              getline(StreamFileLine, InitBrandName, ',');
            getline(StreamFileLine, InitAsin, ',');             getline(StreamFileLine, InitCategory, ',');                 getline(StreamFileLine, InitUpcEanCode, ',');
            getline(StreamFileLine, InitListPrice, ',');        getline(StreamFileLine, InitSellingPrice, ',');             getline(StreamFileLine, InitQuantity, ',');
            getline(StreamFileLine, InitModelNumber, ',');      getline(StreamFileLine, InitAboutProduct, ',');             getline(StreamFileLine, InitProductSpecificiations, ',');
            getline(StreamFileLine, InitTechnicalDetails, ','); getline(StreamFileLine, InitShippingWeight, ',');           getline(StreamFileLine, InitProductDimensions, ',');
            getline(StreamFileLine, InitImage, ',');            getline(StreamFileLine, Initvariants, ',');                 getline(StreamFileLine, Initsku, ',');
            getline(StreamFileLine, InitProductURL, ',');       getline(StreamFileLine, Initstock, ',');                    getline(StreamFileLine, InitProductDetails, ',');
            getline(StreamFileLine, InitColor, ',');            getline(StreamFileLine, InitIngredients, ',');              getline(StreamFileLine, InitDirectionToUse, ',');
            getline(StreamFileLine, InitIsAmazonSeller, ',');   getline(StreamFileLine, InitSizeQuantityVarient, ',');      getline(StreamFileLine, InitProductDescription);
       
            //Initalized respective data classes for AVl tree and hashtable
            //Node<ProductElements>* ImportedDataNode = new Node<ProductElements>();
            ProductElements ImportedData;
            //ASCIINum = NumToASCII(InitUniqueID);
            string NA = "NA";
            if (InitQuantity == ""){
                InitQuantity = NA;
            }
            if (InitProductSpecificiations == ""){
                InitProductSpecificiations = NA;
            }
            if(InitProductDimensions == ""){
                InitProductDimensions = NA;
            }
            if (Initsku == ""){
                Initsku = NA;
            }
            if (InitProductDetails == ""){
                InitProductDetails = NA;
            }
            if (InitDirectionToUse == ""){
                InitDirectionToUse = NA;
            }
            if(InitProductDescription.empty()){
                InitProductDescription = NA;
            }
            if(InitAboutProduct == ""){
                InitAboutProduct = NA;
            }
            if (InitShippingWeight == ""){
                InitShippingWeight = NA;
            }
            if (Initvariants == ""){
                Initvariants = NA;
            }
            if (Initstock == ""){
                Initstock = NA;
            }
            if(InitIngredients == ""){
                InitIngredients = NA;
            }
            if (InitSizeQuantityVarient == ""){
                InitSizeQuantityVarient = NA;
            }
            if(InitUniqueID == ""){
                InitUniqueID = NA;
            }
            if (InitAsin == ""){
                InitAsin = NA;
            }
            if (InitListPrice == ""){
                InitListPrice = NA;
            }
            if (InitProductName == ""){
                InitProductName = NA;
            }
            if(InitBrandName == ""){
                InitBrandName = NA;
            }
            if (InitCategory == ""){
                InitCategory = NA;
            }
            if (InitUpcEanCode == ""){
                InitUpcEanCode = NA;
            }
            if (InitSellingPrice == ""){
                InitSellingPrice = NA;
            }
            if(InitModelNumber == ""){
                InitModelNumber = NA;
            }
            if (InitTechnicalDetails == ""){
                InitTechnicalDetails = NA;
            }
            if (InitImage == ""){
                InitImage = NA;
            }
            if (InitProductURL == ""){
                InitProductURL = NA;
            }
            if(InitColor == ""){
                InitColor = NA;
            }
            if (InitIsAmazonSeller == ""){
                InitIsAmazonSeller = NA;
            }


            size_t sizeoftable = Table.GetSizeOfTable();
            size_t Hash2;
            hash<string> Hash;
            Hash2 = Hash(InitUniqueID);
            ASCIINum = static_cast<int>(Hash2 % sizeoftable);

            //Setting Data elements
            ImportedData.SetUniqueID(InitUniqueID);                 ImportedData.SetProductName(InitProductName);                   ImportedData.SetBrandName(InitBrandName);
            ImportedData.SetAsin(InitAsin);                         ImportedData.SetNewCategory(InitCategory);                      ImportedData.SetUpcEanCode(InitUpcEanCode);
            ImportedData.SetListPrice(InitListPrice);               ImportedData.SetSellingPrice(InitSellingPrice);                 ImportedData.SetQuantity(InitQuantity);
            ImportedData.SetModelNumber(InitModelNumber);           ImportedData.SetAboutProduct(InitAboutProduct);                 ImportedData.SetProductSpecifications(InitProductSpecificiations);
            ImportedData.SetTechnicalDetails(InitTechnicalDetails); ImportedData.SetShippingWeight(InitShippingWeight);             ImportedData.SetProductDimensions(InitProductDimensions);
            ImportedData.SetImage(InitImage);                       ImportedData.SetVariants(Initvariants);                         ImportedData.SetSku(Initsku);
            ImportedData.SetProductURL(InitProductURL);             ImportedData.SetStock(Initstock);                               ImportedData.SetProductDetails(InitProductDetails);
            ImportedData.SetColor(InitColor);                       ImportedData.SetIngredients(InitIngredients);                   ImportedData.SetDirectionToUse(InitDirectionToUse);
            ImportedData.SetIsAmazonUser(InitIsAmazonSeller);       ImportedData.SetSizeQuantityVarient(InitSizeQuantityVarient);   ImportedData.SetProductDescription(InitProductDescription);

            //ImportedDataNode.SetData(ImportedDataBST);

            Table.Insert(ASCIINum, ImportedData);
            AVLTREE.insertGiven(Iterations, ImportedData);

            Iterations++;
            cout << Iterations << endl;
        }

        
    cout << "\n Welcome to Amazon Inventory Query System" << endl;
    cout << " enter :quit to exit. or :help to list supported commands." << endl;
    cout << "\n> ";

    }
    else {

        cout << "File was not open successfully" << endl;
    }   
}


#endif