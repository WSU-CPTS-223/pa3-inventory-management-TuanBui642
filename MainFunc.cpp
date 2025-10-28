/*
    Name: Tuan Bui
    Date: 10/25/25
    Program: PA3, Inventory Management
*/

#include "MainHeader.hpp"

void printHelp()
{
    cout << "Supported list of commands: " << endl;
    cout << " 1. find <inventoryid> - Finds if the inventory exists. If exists, prints details. If not, prints 'Inventory not found'." << endl;
    cout << " 2. listInventory <category_string> - Lists just the id and name of all inventory belonging to the specified category. If the category doesn't exists, prints 'Invalid Category'.\n"
         << endl;
    cout << " Use :quit to quit the REPL" << endl;
}

bool validCommand(string line)
{
    return (line == "help") ||
           (line.rfind("find", 0) == 0) ||
           (line.rfind("listInventory") == 0);
}

void evalCommand(string line, HashTable<ProductElements>& Table){
    if (line == "help")
    {
        printHelp();
    }
    // if line starts with find
    else if (line.rfind("find", 0) == 0)
    {
        // Look up the appropriate datastructure to find if the inventory exist

        string targetstring;
        cout << "Input Target Unique ID: ";
        cin >> targetstring;

        Table.Find(targetstring);

        //cout << "YET TO IMPLEMENT!" << endl;
    }
    // if line starts with listInventory
    else if (line.rfind("listInventory", 0) == 0)
    {
        // Look up the appropriate datastructure to find all inventory belonging to a specific category

        string targetstring;
        cout << "Input Target Category: ";
        getline(cin, targetstring); //Get's the whole line (Toys & Games, not Toys)

        Table.ListInventoryCategory(targetstring);

        //cout << "YET TO IMPLEMENT!" << endl;
    }
}

int NumToASCII(string ConversionString){

    int SumOfNumAscii = 0;

    int SizeOfString = ConversionString.size(); //Gets the size of the string

    for(int i = 0; i < SizeOfString; i++){ //Loops through the whole string

        SumOfNumAscii += static_cast<int>(ConversionString.at(i)); //Converts the character to it's integer equivalent, and adds it to the sum
    }

    return SumOfNumAscii;
}


