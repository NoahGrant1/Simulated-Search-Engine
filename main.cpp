/*
 * main.cpp
 *
 *  Created on: 25 Apr,2019
 *      Author: antec
 */

#include "AVL_ADT.h"
#include "dictionary.h"

using namespace std;
//dont need live typing but only when the user presses enter

int main()
{
    SearchTree  data;
    string choice;

    //choice loop
    while(choice != "end")
    {
    //options to choose from
    cout << "                              " << endl;
    cout << "  Welcome to search engine    " << endl;
    cout <<"-------------------------------" << endl;
    cout << "What do you want to do: " << endl;
    cout << "read textfile (1)" << endl;
    cout << "print dictionary(2)" << endl;
    cout << "print tree(3)" << endl;
    cout << "search List(4)" << endl;
    cout << "save Dictionary to file(5)" << endl;
    cout << "read Dictionary from file(6)" << endl;
    cout <<"-------------------------------" << endl;
    cout << "    end to cancel session     " << endl;
    cout << "                              " << endl;
    cin >> choice;

    //detect choice and run it
    if (choice == "1")
    {
    	data.readFile();
    }
    else if (choice == "2")
    {
    	data.printDictionary();
    }
    else if (choice == "3")
    {
    	data.printTree();
    }
    else if (choice == "4")
    {
        data.search();
    }
    else if (choice == "5")
    {
    	data.saveDictionary();
    }
    else if ( choice == "end")
    {
    	cout << "session canceled" << endl;
    }


    }

	return 0;
}




