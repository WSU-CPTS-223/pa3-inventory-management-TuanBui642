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

class ProductElements{

    public:
        ProductElements() = default;
        ProductElements(const ProductElements& rhs); //Hard Copy constructor

        //Setters for each elements attributes
        void SetUniqueID(string NewID);
        void SetProductName(string NewName);
        void SetBrandName(string NewName);
        void SetAsin(string NewAsin);
        void SetNewCategory(string NewCategory);
        void SetUpcEanCode(string NewUpcEanCode);
        void SetListPrice(string NewListPrice);
        void SetSellingPrice(string NewSellPrice);
        void SetQuantity(string NewQuantity);
        void SetModelNumber(string NewModelNumber);
        void SetAboutProduct(string NewAboutProduct);
        void SetProductSpecifications(string NewProductSpecificiations);
        void SetTechnicalDetails(string NewTechnicalDetails);
        void SetShippingWeight(string NewShippingWeight);
        void SetProductDimensions(string NewProductDimensions);
        void SetImage(string NewImage);
        void SetVariants(string NewVariants);
        void SetSku(string NewSKU);
        void SetProductURL(string NewURL);
        void SetStock(string Newstock);
        void SetProductDetails(string NewProductDetails);
        void SetDimensions(string NewDimensions);
        void SetColor(string NewColor);
        void SetIngredients(string NewIngredients);
        void SetDirectionToUse(string NewDirectionToUse);
        void SetIsAmazonUser(string NewIsAmazonUser);
        void SetSizeQuantityVarient(string NewSizeQuantityVarient);
        void SetProductDescription(string NewProductDescription);

        //Getters for each elements attributes
        string GetUniqueID() const;
        string GetProductName() const;
        string GetBrandName() const;
        string GetAsin() const;
        string GetCategory() const;
        string GetUpcEanCode() const; 
        string GetListPrice() const;
        string GetSellingPrice() const;
        string GetQuantity() const;
        string GetModelNumber() const;
        string GetAboutProduct() const;
        string GetProductSpecifications() const;
        string GetTechnicalDetails() const;
        string GetShippingWeight() const;
        string GetProductDimensions() const;
        string GetImage() const;
        string GetVariants() const;
        string GetSku() const;
        string GetProductURL() const;
        string GetStock() const;
        string GetProductDetails() const;
        string GetDimensions() const;
        string GetColor() const;
        string GetIngredients() const;
        string GetDirectionToUse() const;
        string GetIsAmazonUser() const;
        string GetSizeQuantityVarient() const;
        string GetProductDescription() const;

        //Destructor
        ~ProductElements() = default;

        //Overloaded friend operator to print attributes of Class
        friend ostream& operator<< (ostream& lhs, const ProductElements& rhs);
        ProductElements operator= (const ProductElements rhs);

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
