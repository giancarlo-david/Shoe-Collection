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

void printList(vector<shoe> shoeList, int numberOfShoes)
{
	char yn;

	cout << "Here is your current collection" << endl;

	for (int i = 0; i < numberOfShoes; i++)
	{
		cout << i + 1 << ") " << shoeList[i].getBrand() << " " << shoeList[i].getModel() << " " << shoeList[i].getColor() << endl;
	}
	cout << endl;

	cout << "Would you like to save your collection? (Y/N): ";
	cin >> yn;

	do
	{
		if (yn == 'y' || yn == 'Y')
			outputList(shoeList, numberOfShoes);
		else if (yn == 'n' || yn == 'N')
			cout << "You can save it later if you change your mind" << endl;
		else
			cout << "Please enter either Y or N)" << endl;
	} while (yn != 'y' || yn != 'Y' || yn != 'n' || yn != 'N');
}

void outputList(vector<shoe> shoeList, int numberOfShoes)
{
	ofstream outputFile;
	string fileNameHolder;
	string fileName;

	cout << "What would you like to name your collection? ";
	cin.ignore();
	getline(cin, fileNameHolder);

	fileName = fileNameHolder + ".txt";

	outputFile.open(fileName);
	{
		for (int i = 0; i < numberOfShoes; i++)
		{
			outputFile << shoeList[i].getBrand() << "|" << shoeList[i].getModel() << "|" << shoeList[i].getColor() << endl;
		}
		cout << endl;
	}
	outputFile.close();
}