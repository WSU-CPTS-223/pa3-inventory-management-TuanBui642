/*
    Name: Tuan Bui
    Date: 10/25/25
    Program: PA3, Inventory Management
*/

#include "MainHeader.hpp"

int main(int argc, char const *argv[])
{
    string line;
    bootStrap();
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
        cout << "> ";
    }
    return 0;
}


/*

Uniq Id,Product Name,Brand Name,Asin,Category,Upc Ean Code,List Price,Selling 
    Price,Quantity,Model Number,About Product,Product Specification,Technical Details,
        Shipping Weight,Product Dimensions,Image,Variants,Sku,Product Url,Stock,Product Details,Dimensions,
            Color,Ingredients,Direction To Use,Is Amazon Seller,Size Quantity Variant,Product Description

*/