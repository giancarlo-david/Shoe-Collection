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

// Function to make sure that the user entered the right number
int errorCatcherInt(int &x)
{
   
	char yn;
   // Do while loop that checks if the user meant to enter the number, if not then they can enter the number that they want to
   // Repeats until the user declares that the right number has been entered. 
	do
	{
		cout << "\nIs " << x << " the correct number? (Y/N): ";
		cin >> yn;

		if (yn == 'y' || yn == 'Y')
			break;

		else if (yn == 'n' || yn == 'N')
		{
			cout << "Please enter the correct number: ";
			cin >> x;
		}

		else
		{
			cout << "Enter either Y or N";
		}
	} while (yn != 'y' || yn != 'Y');

	return x;
}

// Function to check with user if the properties they entered are correct, if not the user re-enters the information
// Repeats until user is satisfied with the shoe they are entering
void shoeCheck(string &x, string &y, string &z)
{
	char yn;
	do
	{
		cout << "\nIs " << x << " " << y << " " << z << " correct (Y/N): ";
		cin >> yn;
		cout << endl;

		if (yn == 'y' || yn == 'Y')
			break;

		else if (yn == 'n' || yn == 'N')
		{
			cout << "Please enter the correct brand: ";
			cin >> x;
			cout << "Please enter the correct model: ";
			cin >> y;
			cout << "Please enter the correct colorway: ";
			cin >> z;
		}

		else
		{
			cout << "Enter either Y or N";
		}
	} while (yn != 'y' || yn != 'Y');
}

