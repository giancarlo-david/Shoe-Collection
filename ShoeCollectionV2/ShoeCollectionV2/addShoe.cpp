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

void addShoe(vector<shoe> &shoeList, int &numberOfShoes)
{
   int shoesToAdd;
   cout << "\nHow many shoes would you like to add?: ";
   cin >> shoesToAdd;
   errorCatcherInt(shoesToAdd);

   for (int i = 0; i < shoesToAdd; i++)
   {
      /* Variables to hold various items
      tempBrand, tempModel, tempColor all hold the current shoe's brand, model, and color respectively
      tempShoe holds the current shoe to make it easier to add to the shoeList vector
       */
      string tempBrand, tempModel, tempColor;
      shoe tempShoe;

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
      numberOfShoes++;
   }

   sortList(shoeList);

   cout << "Finished adding shoes\n";
}

void removeShoe(vector<shoe> &shoeList, int &numberOfShoes)
{
   int shoesToRemove;
   int shoeIndex;

   cout << "\nHow many shoes would you like to remove?: ";
   cin >> shoesToRemove;

   errorCatcherInt(shoesToRemove);

   for (int i = 0; i < shoesToRemove; i++)
   {
      int shoeNumber;
      cout << "Enter the number of the shoe you want to remove: ";
      cin >> shoeNumber;

      errorCatcherInt(shoeNumber);

      shoeIndex = shoeNumber - 1;

      shoeList[shoeIndex] = shoeList.back();
      shoeList.pop_back();
      numberOfShoes--;
   }


   sortList(shoeList);
   cout << "Finished removing shoes\n";
}

