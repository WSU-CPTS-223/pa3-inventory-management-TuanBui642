/*
    Name: Tuan Bui
    Date: 10/25/25
    Program: PA3, Inventory Management
*/

#include "ProductClass.hpp"

ProductElements::ProductElements(const ProductElements& rhs){//Hard Copy constructor
    this->UniqueID = rhs.UniqueID;
    this->ProductName = rhs.ProductName;
    this->BrandName = rhs.BrandName;
    this->Asin = rhs.Asin;
    this->Category = rhs.Category;
    this->UpcEanCode = rhs.UpcEanCode;
    this->ListPrice = rhs.ListPrice;
    this->SellingPrice = rhs.SellingPrice;
    this->Quantity = rhs.Quantity;
    this->ModelNumber = rhs.ModelNumber;
    this->AboutProduct = rhs.AboutProduct;
    this->ProductSpecificiations = rhs.ProductSpecificiations;
    this->TechnicalDetails = rhs.TechnicalDetails;
    this->ShippingWeight = rhs.ShippingWeight;
    this->ProductDimensions = rhs.ProductDimensions;
    this->Image = rhs.Image;
    this->variants = rhs.variants;
    this->sku = rhs.sku;
    this->ProductURL = rhs.ProductURL;
    this->stock = rhs.stock;
    this->ProductDetails = rhs.ProductDetails;
    this->Dimensions = rhs.Dimensions;
    this->Color = rhs.Color;
    this->Ingredients = rhs.Ingredients;
    this->DirectionToUse = rhs.DirectionToUse;
    this->IsAmazonSeller = rhs.IsAmazonSeller;
    this->SizeQuantityVarient = rhs.SizeQuantityVarient;
    this->ProductDescription = rhs.ProductDescription;
}

//Setters for each elements attributes
void ProductElements::SetUniqueID(string NewID){
    this->UniqueID = NewID;
}

void ProductElements::SetProductName(string NewName){
    this->ProductName = NewName;
}

void ProductElements::SetBrandName(string NewName){
    this->BrandName = NewName;
}

void ProductElements::SetAsin(string NewAsin){
    this->Asin = NewAsin;
}

void ProductElements::SetNewCategory(string NewCategory){
    this->Category = NewCategory;
}

void ProductElements::SetUpcEanCode(string NewUpcEanCode){
    this->UpcEanCode = NewUpcEanCode;
}

void ProductElements::SetListPrice(string NewListPrice){
    this->ListPrice = NewListPrice;
}

void ProductElements::SetSellingPrice(string NewSellPrice){
    this->SellingPrice = NewSellPrice;
}

void ProductElements::SetQuantity(string NewQuantity){
    this->Quantity = NewQuantity;
}

void ProductElements::SetModelNumber(string NewModelNumber){
    this->ModelNumber = NewModelNumber;
}

void ProductElements::SetAboutProduct(string NewAboutProduct){
    this->AboutProduct = NewAboutProduct;
}

void ProductElements::SetProductSpecifications(string NewProductSpecificiations){
    this->ProductSpecificiations = NewProductSpecificiations;
}

void ProductElements::SetTechnicalDetails(string NewTechnicalDetails){
    this->TechnicalDetails = NewTechnicalDetails;
}

void ProductElements::SetShippingWeight(string NewShippingWeight){
    this->ShippingWeight = NewShippingWeight;
}

void ProductElements::SetProductDimensions(string NewProductDimensions){
    this->ProductDimensions = NewProductDimensions;
}

void ProductElements::SetImage(string NewImage){
    this->Image = NewImage;
}

void ProductElements::SetVariants(string NewVariants){
    this->variants = NewVariants;
}

void ProductElements::SetSku(string NewSKU){
    this->sku = NewSKU;
}

void ProductElements::SetProductURL(string NewURL){
    this->ProductURL = NewURL;
}

void ProductElements::SetStock(string Newstock){
    this->stock = Newstock;
}

void ProductElements::SetProductDetails(string NewProductDetails){
    this->ProductDetails = NewProductDetails;
}

void ProductElements::SetDimensions(string NewDimensions){
    this->Dimensions = NewDimensions;
}

void ProductElements::SetColor(string NewColor){
    this->Color = NewColor;
}

void ProductElements::SetIngredients(string NewIngredients){
    this->Ingredients = NewIngredients;
}

void ProductElements::SetDirectionToUse(string NewDirectionToUse){
    this->DirectionToUse = NewDirectionToUse;
}

void ProductElements::SetIsAmazonUser(string NewIsAmazonUser){
    this->IsAmazonSeller = NewIsAmazonUser;
}

void ProductElements::SetSizeQuantityVarient(string NewSizeQuantityVarient){
    this->SizeQuantityVarient = NewSizeQuantityVarient;
}

void ProductElements::SetProductDescription(string NewProductDescription){
    this->ProductDescription = NewProductDescription;
}

//Getters for each elements attributes
string ProductElements::GetUniqueID() const{
    return this->UniqueID;
}

string ProductElements::GetProductName() const{
    return this->ProductName;
}

string ProductElements::GetBrandName() const{
    return this->BrandName;
}

string ProductElements::GetAsin() const{
    return this->Asin;
}

string ProductElements::GetCategory() const{
    return this->Category;
}

string ProductElements::GetUpcEanCode() const{
    return this->UpcEanCode;
} 

string ProductElements::GetListPrice() const{
    return this->ListPrice;
}

string ProductElements::GetSellingPrice() const{
    return this->SellingPrice;
}

string ProductElements::GetQuantity() const{
    return this->Quantity;
}

string ProductElements::GetModelNumber() const{
    return this->ModelNumber;
}

string ProductElements::GetAboutProduct() const{
    return this->AboutProduct;
}

string ProductElements::GetProductSpecifications() const{
    return this->ProductSpecificiations;
}

string ProductElements::GetTechnicalDetails() const{
    return this->TechnicalDetails;
}

string ProductElements::GetShippingWeight() const{
    return this->ShippingWeight;
}

string ProductElements::GetProductDimensions() const{
    return this->ProductDimensions;
}

string ProductElements::GetImage() const{
    return this->Image;
}

string ProductElements::GetVariants() const{
    return this->variants;
}

string ProductElements::GetSku() const{
    return this->sku;
}

string ProductElements::GetProductURL() const{
    return this->ProductURL;
}

string ProductElements::GetStock() const{
    return this->stock;
}

string ProductElements::GetProductDetails() const{
    return this->ProductDetails;
}

string ProductElements::GetDimensions() const{
    return this->Dimensions;
}

string ProductElements::GetColor() const{
    return this->Color;
}

string ProductElements::GetIngredients() const{
    return this->Ingredients;
}

string ProductElements::GetDirectionToUse() const{
    return this->DirectionToUse;
}

string ProductElements::GetIsAmazonUser() const{
    return this->IsAmazonSeller;
}

string ProductElements::GetSizeQuantityVarient() const{
    return this->SizeQuantityVarient;
}

string ProductElements::GetProductDescription() const{
    return this->ProductDescription;
}

//Overloaded friend operator to print attributes of Class
ostream& operator<< (ostream& lhs, const ProductElements& rhs){

    lhs << endl;
    lhs << "Unique ID: " << rhs.UniqueID << endl;
    lhs << "Brand Name: " << rhs.BrandName << " Sell Price: " << rhs.SellingPrice << endl;

    return lhs;
}

ProductElements ProductElements::operator= (const ProductElements rhs){

    this->SetUniqueID(rhs.UniqueID);
    this->SetProductName(rhs.ProductName);
    this->SetBrandName(rhs.BrandName);
    this->SetAsin(rhs.Asin);
    this->SetNewCategory(rhs.Category);
    this->SetUpcEanCode(rhs.UpcEanCode);
    this->SetListPrice(rhs.ListPrice);
    this->SetSellingPrice(rhs.SellingPrice);
    this->SetQuantity(rhs.Quantity);
    this->SetModelNumber(rhs.ModelNumber);
    this->SetAboutProduct(rhs.AboutProduct);
    this->SetProductSpecifications(rhs.ProductSpecificiations);
    this->SetTechnicalDetails(rhs.TechnicalDetails);
    this->SetShippingWeight(rhs.ShippingWeight);
    this->SetProductDimensions(rhs.ProductDimensions);
    this->SetImage(rhs.Image);
    this->SetVariants(rhs.variants);
    this->SetSku(rhs.sku);
    this->SetProductURL(rhs.ProductURL);
    this->SetStock(rhs.stock);
    this->SetProductDetails(rhs.ProductDetails);
    this->SetDimensions(rhs.Dimensions);
    this->SetColor(rhs.Color);
    this->SetIngredients(rhs.Ingredients);
    this->SetDirectionToUse(rhs.DirectionToUse);
    this->SetIsAmazonUser(rhs.IsAmazonSeller);
    this->SetSizeQuantityVarient(rhs.SizeQuantityVarient);
    this->SetProductDescription(rhs.ProductDescription);     

    return *this;   
}