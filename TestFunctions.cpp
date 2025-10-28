/*
    Name: Tuan Bui
    Date: 10/25/25
    Program: PA3, Inventory Management
*/

#include "MainHeader.hpp"

void TESTfind(){

    HashTable<ProductElements> TestTable(300);

    ProductElements InsertedElement1;
    ProductElements InsertedElement2;

    //Instantiate test variables or ideas
    InsertedElement1.SetUniqueID("abc"); //294
    InsertedElement2.SetUniqueID("ABC"); //198

    //Insrting those two test ideas/variables into hashtable
    TestTable.Insert(294, InsertedElement1);
    TestTable.Insert(198, InsertedElement1);

    //Normal Case (Should return true [in table])
    assert(TestTable.Find("abc") == true);
    assert(TestTable.Find("ABC") == true);

    //Edge Case (Should return false [not in table])
    assert(TestTable.Find("AAA") == false);
}

void TESTinsert(){

    HashTable<ProductElements> TestTable(300);

    ProductElements InsertedElement1;
    ProductElements InsertedElement2;

    

}

void TestFindCategory(){



}