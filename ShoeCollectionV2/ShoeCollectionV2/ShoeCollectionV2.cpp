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
void sortList(vector<shoe> list);
int errorCatcherInt(int &x);
void shoeCheck(string &x, string &y, string &z);
void printList(vector<shoe> shoeList, int numberOfShoes);

// Main function containing the main menu for user to select options
int main()
{
	// Variable intializations for exitBool (flags if user wants to exit program) and menuChoice (holds user menu choice)
	bool exitBool = false;
	int menuChoice;

	do
	{
		cout << "\tMain Menu" << endl;
		cout << "1) Create new collection\n2)Import and edit an existing collection\n3)Exit\n\n";
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

	//NEED TO INSERT SORT FUNCTION HERE

	printList(shoeList, numberOfShoes);
}

void importCollection()
{
	
}

void sortList(vector<shoe> list)
{

}

int errorCatcherInt(int &x)
{
	char yn;
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
	}while (yn != 'y' || yn != 'Y');
}

void printList(vector<shoe> shoeList, int numberOfShoes)
{
	ofstream outputFile;
	string fileNameHolder;
	string fileName, brandFile, modelFile, colorFile;

	cout << "Here is your current collection" << endl;

	for (int i = 0; i < numberOfShoes; i++)
	{
		cout << i + 1 << ") " << shoeList[i].getBrand() << " " << shoeList[i].getModel() << " " << shoeList[i].getColor() << endl;
	}
	cout << endl;

	cout << "What would you like to name your collection? ";
	cin.ignore();
	getline(cin, fileNameHolder);

	fileName = fileNameHolder + ".txt";
	brandFile = fileNameHolder + "Brands.txt";
	modelFile = fileNameHolder + "Models.txt";
	colorFile = fileNameHolder + "Colors.txt";

	outputFile.open(fileName);
	{
		for (int i = 0; i < numberOfShoes; i++)
		{
			outputFile << i + 1 << ") " << shoeList[i].getBrand() << " " << shoeList[i].getModel() << " " << shoeList[i].getColor() << endl;
		}
		cout << endl;
	}
	outputFile.close();

	outputFile.open(brandFile);
	{
		for (int i = 0; i < numberOfShoes; i++)
		{
			outputFile << shoeList[i].getBrand() << endl;
		}
	}
	outputFile.close();

	outputFile.open(modelFile);
	{
		for (int i = 0; i < numberOfShoes; i++)
		{
			outputFile << shoeList[i].getModel() << endl;
		}
	}
	outputFile.close();

	outputFile.open(colorFile);
	{
		for (int i = 0; i < numberOfShoes; i++)
		{
			outputFile << shoeList[i].getColor() << endl;
		}
	}
	outputFile.close();

}
