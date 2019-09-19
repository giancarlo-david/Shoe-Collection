#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include "shoe.h"

using namespace std;

// Function prototypes
void createNewCollection();
void importCollection();
bool compareTwoShoes(shoe a, shoe b);
void sortList(vector<shoe> &list);
int errorCatcherInt(int &x);
void shoeCheck(string &x, string &y, string &z);
void printList(vector<shoe> shoeList, int numberOfShoes);
void outputList(vector<shoe> shoeList, int numberOfShoes);

// Function to create a new collection from scratch
void createNewCollection()
{
	/* Variables to hold various items
	shoeList holds the list of shoes in the form of a vector
	numberOfShoes holds the number of shoes the user wants to add
	tempBrand, tempModel, tempColor all hold the current shoe's brand, model, and color respectively
	tempShoe holds the current shoe to make it easier to add to the shoeList vector
	*/
	vector<shoe> shoeList;
	int numberOfShoes;
	string tempBrand, tempModel, tempColor;
	shoe tempShoe;

	// Gets user input to how many shoes they want to add and checks to see if the number is correct
	cout << "\nEnter the number of shoes you would like to add: ";
	cin >> numberOfShoes;
	errorCatcherInt(numberOfShoes);

	// For loop to get user input on the details of each shoe, looping until it reaches the number of shoes wanted
	//  and adds each shoe to the shoeList vector 
	for (int i = 0; i < numberOfShoes; i++)
	{

		cout << "Enter the brand of shoe #" << i + 1 << ": ";
		cin.ignore();
		getline(cin, tempBrand);
		cout << "Enter the model of shoe #" << i + 1 << ": ";
		getline(cin, tempModel);
		cout << "Enter the colorway of shoe #" << i + 1 << ": ";
		getline(cin, tempColor);

		shoeCheck(tempBrand, tempModel, tempColor);

		tempShoe.setBrand(tempBrand);
		tempShoe.setModel(tempModel);
		tempShoe.setColor(tempColor);

		shoeList.push_back(tempShoe);
	}

	sortList(shoeList);

	printList(shoeList, numberOfShoes);
}