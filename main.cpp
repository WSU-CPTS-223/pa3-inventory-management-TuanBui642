/*
    Name: Tuan Bui
    Date: 10/25/25
    Program: PA3, Inventory Management
*/

#include "MainHeader.hpp"
//AVL_MAP_BST<int,ProductElements>;

int main(int argc, char const *argv[])
{
    HashTable<ProductElements> Table(1000000);
    AVL_MAP_BST<int,ProductElements> AVLTREE;

    string line;
    bootStrap(Table, AVLTREE);
    while (getline(cin, line) && line != ":quit")
    {
        if (validCommand(line))
        {
            evalCommand(line);
        }
        else
        {
            cout << "Command not supported. Enter :help for list of supported commands" << endl;
        }
        
    }
    return 0;
}


/*

Uniq Id,Product Name,Brand Name,Asin,Category,Upc Ean Code,List Price,Selling 
    Price,Quantity,Model Number,About Product,Product Specification,Technical Details,
        Shipping Weight,Product Dimensions,Image,Variants,Sku,Product Url,Stock,Product Details,Dimensions,
            Color,Ingredients,Direction To Use,Is Amazon Seller,Size Quantity Variant,Product Description

*/