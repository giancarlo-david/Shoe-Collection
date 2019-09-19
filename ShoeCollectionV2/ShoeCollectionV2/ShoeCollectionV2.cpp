#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <stdlib.h>
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

// Main function containing the main menu for user to select options
int main()
{
	/* Variable intializations for exitBool (flags if user wants to exit program) and menuChoice (holds user menu choice)
   shoeList holds the list of shoes in the form of a vector
	numberOfShoes holds the number of shoes the user wants to add
   */
	bool exitBool = false;
	int menuChoice;
   vector<shoe> shoeList;
   int numberOfShoes = 0;

	do
	{
		cout << "\tMain Menu" << endl;
		cout << "1) Create new collection\n2) Import an existing collection\n3) Exit\n\n";
		cout << "Enter the number option you would like to choose: ";
		cin >> menuChoice;

		// Switch statement to go to designated menuChoice
		switch (menuChoice)
		{
		case 1:
			createNewCollection(shoeList, numberOfShoes);
			break;
		case 2:
			importCollection(shoeList, numberOfShoes);
			break;
		case 3:
			exitBool = true;
			break;
		}

      // If statement to go on to the editing menu when there is a list that is already held by the program
      if (numberOfShoes > 0)
         break;

	} while (exitBool == false);

   // If statement to exit the program should the user want to exit from the main menu
   if (exitBool == true)
   {
      system("pause");
      exit(0);
   }

   // Editing menu for the user to access once the program contains a list of shoes
   do
   {
      cout << "\n\tEditing Menu" << endl;
      cout << "1) Add Shoe\n2) Remove Shoe\n3) Show Collection\n4) Save Collection\n5) Exit\n\n";
      cout << "Enter the number option you would like to choose: ";
      cin >> menuChoice;

      // Switch menu that calls a function based on user choice
      switch (menuChoice)
      {
      case 1:
         addShoe(shoeList, numberOfShoes);
         break;
      case 2:
         removeShoe(shoeList, numberOfShoes);
         break;
      case 3:
         printList(shoeList, numberOfShoes);
         break;
      case 4:
         outputList(shoeList, numberOfShoes);
         break;
      case 5:
         exitBool = true;
         break;
      }
   } while (exitBool == false);


	system("pause");
	exit(0);
	return 0;
}





