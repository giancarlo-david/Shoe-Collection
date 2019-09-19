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

// Main function containing the main menu for user to select options
int main()
{
	// Variable intializations for exitBool (flags if user wants to exit program) and menuChoice (holds user menu choice)
	bool exitBool = false;
	int menuChoice;

	do
	{
		cout << "\tMain Menu" << endl;
		cout << "1)Create new collection\n2)Import and edit an existing collection\n3)Exit\n\n";
		cout << "Enter the number option you would like to choose: ";
		cin >> menuChoice;

		// Switch statement to go to designated menuChoice
		switch (menuChoice)
		{
		case 1:
			createNewCollection();
			break;
		case 2:
			importCollection();
			break;
		case 3:
			exitBool = true;
			break;
		}

	} while (exitBool == false);

	system("pause");
	exit(0);
	return 0;
}





