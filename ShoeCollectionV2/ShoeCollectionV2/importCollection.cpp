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

void importCollection(vector<shoe> &shoeList, int &numberOfShoes)
{
   string fileName, fileNameHolder;
   ifstream inputFile;

   cout << "What is the name of your saved collection? (Exclude .txt): ";
   cin.ignore();
   getline(cin, fileNameHolder);
   fileName = fileNameHolder + ".txt";

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
            getline(inputFile, tempBrand, '|');
            tempShoe.setBrand(tempBrand);

            getline(inputFile, tempModel, '|');
            tempShoe.setModel(tempModel);

            getline(inputFile, tempColor, '|');
            tempShoe.setColor(tempColor);

            inputFile.ignore();

            // Current work around since once loop gets to end of file it reads the last line again with no brand
            if (tempBrand == "")
               break;

            shoeList.push_back(tempShoe);
            numberOfShoes++;
         }

         printList(shoeList, numberOfShoes);
      }
      else
         throw 1;
   }

   catch (int x)
   {
      cout << "File not found! Returning to main menu" << endl << endl;
   }
}