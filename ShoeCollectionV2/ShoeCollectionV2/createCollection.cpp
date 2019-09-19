#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include "shoe.h"

using namespace std;

// Function prototypes
void createNewCollection(vector<shoe> &shoeList, int &numberOfShoes);
void importCollection(vector<shoe> &shoeList, int &numberOfShoes);
bool compareTwoShoes(shoe a, shoe b);
void sortList(vector<shoe> &list);
int errorCatcherInt(int &x);
void shoeCheck(string &x, string &y, string &z);
void printList(vector<shoe> shoeList, int numberOfShoes);
void outputList(vector<shoe> shoeList, int numberOfShoes);
void addShoe(vector<shoe> &shoeList, int &numberOfShoes);
void removeShoe(vector<shoe> &shoeList, int &numberOfShoes);

// Function to create a new collection from scratch
void createNewCollection(vector<shoe> &shoeList, int &numberOfShoes)
{
	/* Variables to hold various items
	tempBrand, tempModel, tempColor all hold the current shoe's brand, model, and color respectively
	tempShoe holds the current shoe to make it easier to add to the shoeList vector
	*/
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
      // Prompts the user to enter the properties of the shoe they are currently adding
		cout << "Enter the brand of shoe #" << i + 1 << ": ";
		cin.ignore();
		getline(cin, tempBrand);
		cout << "Enter the model of shoe #" << i + 1 << ": ";
		getline(cin, tempModel);
		cout << "Enter the colorway of shoe #" << i + 1 << ": ";
		getline(cin, tempColor);

		shoeCheck(tempBrand, tempModel, tempColor);

      // Sets the properties of the temporary shoe based on user input then places the temporary shoe at the end of the vector
		tempShoe.setBrand(tempBrand);
		tempShoe.setModel(tempModel);
		tempShoe.setColor(tempColor);

		shoeList.push_back(tempShoe);
	}

	sortList(shoeList);

	printList(shoeList, numberOfShoes);
}