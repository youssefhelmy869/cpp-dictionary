#include "map.h"
#include <string>
#include <iostream>

using namespace std;

int main()
{

    dictionary<string, int> dict;

    cout << "Inserting values...\n";
    dict.insert("apple", 10);
    dict.insert("banana", 20);
    dict.insert("cherry", 30);

    cout << "Size after insertions: " << dict.size() << endl;

    // Access values using operator[]
    cout << "Value of apple: " << dict["apple"] << endl;
    cout << "Value of banana: " << dict["banana"] << endl;

    // Update
    cout << "\nUpdating 'banana' to 99...\n";
    dict.update("banana", 99);
    cout << "Value of banana after update: " << dict["banana"] << endl;

    // Check does_have
    cout << "\nDoes dictionary have 'cherry'? " << (dict.does_have("cherry") ? "Yes" : "No") << endl;
    cout << "Does dictionary have 'orange'? " << (dict.does_have("orange") ? "Yes" : "No") << endl;

    // Delete a key
    cout << "\nDeleting 'apple'...\n";
    dict.delete_key("apple");
    cout << "Size after deleting apple: " << dict.size() << endl;

    // Try accessing a deleted key
    try
    {
        cout << dict["apple"] << endl;
    }
    catch (const exception &e)
    {
        cout << "Exception: " << e.what() << endl;
    }

    // Clear the dictionary
    cout << "\nClearing dictionary...\n";
    dict.clear();
    cout << "Is empty after clear? " << (dict.is_empty() ? "Yes" : "No") << endl;
    return 0;
}