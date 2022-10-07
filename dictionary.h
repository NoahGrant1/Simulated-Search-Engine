/*
 * Dictionary_Search.h
 *
 *  Created on: 25 Apr,2019
 *      Author: antec
 */

#ifndef DICTIONARY_H_
#define DICTIONARY_H_

#include <fstream>
#include <map>
#include <string>
#include <iostream>
#include <queue>
using namespace std;

struct Data
{
	string key; //used to store words
	int frequency; //used to store frequency
};

class SearchTree
{
public:
	void search();
	void readFile();
	string trimWord(string& line);
    void printDictionary();
    void printTree();
    void saveDictionary();
    void printqueue();
    void readDictionary();

private:
    AvlTree<Data,string> tree; //stores the AVL tr
    priority_queue<Data, vector<Data>,  less<Data> > wordPriority; //stores the order of the words
};

//reads the text file and puts the data into the tree
void SearchTree::readFile()
{
     ifstream myfile;
     myfile.open("search.txt");
     string line; //stores current line

     if (myfile.is_open() )
     {
    	 cout << "file opened successfully" << endl;
    	 while ( getline(myfile, line))
    	 {
    		  Data newItem;
    		  line = trimWord(line);

    		  //if items not in AVL tree
    		  if (tree.AVL_Retrieve(newItem, line) == false)
    		  {
    			  newItem.key = line;
    			  newItem.frequency = 1;
    			  tree.AVL_Insert(newItem);
    		  }
    		  //if item is already in AVL tree
    		  else
    		  {
    			  newItem.frequency +=1;
    			  tree.AVL_Update(line, newItem);
    		  }

    	 }
    	 myfile.close();
     }
     else if (!myfile)
     {
    	 cout << "unable to open file" << endl;
    	 exit(1);
     }

}

// trims any non alphabetic symbols
string SearchTree::trimWord(string& line)
{
	for ( unsigned int i=0; i < line.length(); i++)
	{
         if( !isalpha(line[i]) )
         {
              line.erase(i);
         }
	}

	return line;
}

//used to print dictionary
void print(Data d)
{
	cout << d.key << ", " << d.frequency << endl;
}

//prints the words and their frequency
void SearchTree:: printDictionary()
{
	 cout << "The dictionary contains: " << endl;
	 tree.AVL_Traverse(print);

	 if (tree.AVL_Empty() == true)
	 {
		 cout <<"                        " << endl;
		 cout << "The Dictionary is empty" << endl;
		 cout <<"                        " << endl;
	 }
}

//prints the entire tree
void SearchTree::printTree()
{
    cout << "The AVL tree contains: "<< endl;
	tree.AVL_Print();

	 if (tree.AVL_Empty() == true)
	 {
		 cout <<"                        " << endl;
		 cout << "The Tree is empty" << endl;
		 cout <<"                        " << endl;
	 }
}

//overload less<> operator for priority queue
template <class Type>
constexpr bool operator<(const Type &lhs, const Type &rhs)
{
        return lhs < rhs;
}
/*
bool searchTemp( Data &newItem)
{
	vector <string> temp;

	temp.insert(&newItem.key);

	for (int i =0; i < temp.size(); i++)
	{

	}

	return false;
}
*/

//allows user to search for words
void SearchTree::search()
{
	string word;

	//get user inputed word
	while (word != "end")
	{
    cout << "Enter a word to Search for: " << endl;
    cout << "(end = cancel session)      " << endl;
    cin >> word;

    Data newItem;
   // for (int i=0; i< 5; i++)
   // {
         tree.AVL_Retrieve(newItem,word);

        // if(searchTemp(newItem) == false)
        // {
              wordPriority.push(newItem);
         //}
   // }


    //if results found call function
    if(!wordPriority.empty() && newItem.key != "")
    {
        printqueue();
    }
    else if (word == "end")
    {
        cout << "                " << endl;
        cout << "session canceled" << endl;
        cout << "                " << endl;
    }
    else //if no results found
    {
        cout << "                           " << endl;
        cout << "No search results available" << endl;
        cout << "                           " << endl;
        wordPriority.pop();
    }

	}
}

// overloads << operator to work with the priority queue
ostream& operator << (ostream& out, const Data& newItem)
{
  	out << newItem.key <<" , " << newItem.frequency << endl;
  	return out;
}

//print the contents of the priority queue
void SearchTree::printqueue()
{
	cout << "                           " << endl;
	cout << "The top results are: " << endl;
	cout << "(Word), (frequency)" << endl;
	cout << "                           " << endl;

	if (wordPriority.empty())
	{
		cout << "No results found" << endl;
	}
	else
	{
		for (unsigned int i=0; i < wordPriority.size(); i++)
		{
			cout << " " << wordPriority.top()  << endl; //overload the operator
			wordPriority.pop();
		}
	}

}

//copies the dictionary to a text file
void SearchTree::saveDictionary()
{
	cout << "not fully implemented yet" << endl;
	cout << "Saving Dictionary to file" << endl;

	ofstream outfile;
	Data newItem;

	//create the new file
	outfile.open("Dictionary.txt");

    //outfile << tree.AVL_Traverse(print) << endl;

	cout << "Dictionary saved to file" << endl;
    outfile.close();
}

void SearchTree::readDictionary()
{
	ifstream file;
	     file.open("Dictionary.txt");
	     char line; //stores current line
	     int freq;

	     if (file.is_open() )
	     {
	    	 cout << "file opened successfully" << endl;
	    	 while ( getline(file, line))
	    	 {
	    		  Data newItem;
	    		  //line contains word, frequency

	    		  getchar()


	    	 }
	    	 file.close();
	     }
	     else if (!file)
	     {
	    	 cout << "unable to open file" << endl;
	    	 exit(1);
	     }

}


#endif /* DICTIONARY_H_ */
