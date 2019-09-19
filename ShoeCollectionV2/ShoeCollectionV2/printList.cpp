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

// Function to print out the current collection being held by the program
void printList(vector<shoe> shoeList, int numberOfShoes)
{
	cout << "\nHere is your current collection" << endl;

	for (int i = 0; i < numberOfShoes; i++)
	{
		cout << i + 1 << ") " << shoeList[i].getBrand() << " " << shoeList[i].getModel() << " " << shoeList[i].getColor() << endl;
	}
	cout << endl;
}

// Function to save the current collection being held into a txt file named by the user
// Each property is separated by the character '|' to make importing easier
void outputList(vector<shoe> shoeList, int numberOfShoes)
{
	ofstream outputFile;
	string fileNameHolder;
	string fileName;

	cout << "\nWhat would you like to name your collection? (Exclude .txt): ";
	cin.ignore();
	getline(cin, fileNameHolder);

	fileName = fileNameHolder + ".txt";

	outputFile.open(fileName);
	{
      for (int i = 0; i < numberOfShoes; i++)
      {
         outputFile << shoeList[i].getBrand() << "|" << shoeList[i].getModel() << "|" << shoeList[i].getColor() << "|" << endl;
      }
	}
	outputFile.close();
}