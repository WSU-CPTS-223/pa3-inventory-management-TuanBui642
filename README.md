[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/pAwGQi_N)

# PA4 Skeleton Code
We expect a fully functioninig command line REPL application for an inventory querying system. Feel free to modify the skeleton code as you see fit.

### How to run the current skeleton code
`make` will compile and execute the skeleton code

Feel free to modify Makefile as you see fit.


TestCases Explainations

For Each Test Case, I initialized a testtable, and 2-3 test elements of ProductElements class and fitted those Product Element Classes with a couple of data sets to test (Unique ID) and from the Unique ID, would be the ASCII equivalent of those Unique ID (AAA = 195, ABC = 294, abc = 198). Then pivoting from this, I would do insert into list for all three test cases (insert, find, listInventory) since there needed to be data to begin testing. For insert, i would have inserted data and use another function to help return a boolean value to determine if the inserted piece of data was present (Since i used a hashtable [vector] that is populated with a linked list), i would then check if the index of that vector would be filled or not (nullptr or not) and then see if the data of that index matches with it's correct respective value. Such as if i inserted ABC, then i would expect it to be in index 294 and have the unique ID element of "ABC", Then for TestFind, same idea populate test table with elements, and then use my insert function with respective argument parameters and see if it'll spit out a boolean value (true/false). Lastly for listInventory, i had to make another function such that it could return a boolean value but if it did return a boolean value, then it would only be a singular category read. So i populated the list with one target category with other elements being other categories. Ran the alternative/tweaked version of the listInventory function and it would return a true if that category was in the list. For it's edge case, i would do the opposite and input a not true category that isn't in the list to test. 
