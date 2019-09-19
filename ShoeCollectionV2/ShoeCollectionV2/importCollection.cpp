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

// Function that imports a collection that was previously made and saved via txt file
void importCollection(vector<shoe> &shoeList, int &numberOfShoes)
{
   string fileName, fileNameHolder;
   ifstream inputFile;

   // Prompts the user to enter the name of the file that they are trying to access
   cout << "What is the name of your saved collection? (Exclude .txt): ";
   cin.ignore();
   getline(cin, fileNameHolder);
   fileName = fileNameHolder + ".txt";

   // Try statement that checks to see if the file that the user is trying to open exists
   // If it does then it imports all the shoes that are saved within that file ore else it throws an exception
   try
   {
      cout << "Loading collection..." << endl;
      inputFile.open(fileName);
      
      if (inputFile.is_open())
      {
         /* Variables to hold various items
         tempBrand, tempModel, tempColor all hold the current shoe's brand, model, and color respectively
         tempShoe holds the current shoe to make it easier to add to the shoeList vector
         */
         string tempBrand, tempModel, tempColor;
         shoe tempShoe;

         while (!inputFile.eof())
         {
            string ignored;
            getline(inputFile, tempBrand, '|');
            tempShoe.setBrand(tempBrand);

            getline(inputFile, tempModel, '|');
            tempShoe.setModel(tempModel);

            getline(inputFile, tempColor, '|');
            tempShoe.setColor(tempColor);

            // Honestly not sure why I have to do this, but without it the import takes the shoes in wrong
            getline(inputFile, ignored, '\n');

            shoeList.push_back(tempShoe);
            numberOfShoes++;
         }

         printList(shoeList, numberOfShoes);
      }
      else
         throw 1;
   }

   // Catches the exception letting the user know the file they are trying to access was not found, then returns to main menu
   catch (int x)
   {
      cout << "File not found! Returning to main menu" << endl << endl;
   }
}