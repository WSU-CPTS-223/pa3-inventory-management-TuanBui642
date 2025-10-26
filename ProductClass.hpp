/*
    Name: Tuan Bui
    Date: 10/25/25
    Program: PA3, Inventory Management
*/

#ifndef PRODUCTCLASS
#define PRODUCTCLASS

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

class ProductELements{

    public:
        



    private:
        string UniqueID;
        string ProductName;
        string BrandName;
        string Asin;
        string Category;
        string UpcEanCode;
        string ListPrice;
        string SellingPrice;
        string Quantity;
        string ModelNumber;
        string AboutProduct;
        string ProductSpecificiations;
        string TechnicalDetails;
        string ShippingWeight;
        string ProductDimensions;
        string Image;
        string variants;
        string sku;
        string ProductURL;
        string stock;
        string ProductDetails;
        string Dimensions;
        string Color;
        string Ingredients;
        string DirectionToUse;
        string IsAmazonSeller;
        string SizeQuantityVarient;
        string ProductDescription;
};



#endif
