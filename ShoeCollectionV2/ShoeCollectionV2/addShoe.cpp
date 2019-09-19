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

// Function to add shoes when a collection has either been created or imported into the program
void addShoe(vector<shoe> &shoeList, int &numberOfShoes)
{
   // Gets user input of how many shoes they want to add
   int shoesToAdd;
   cout << "\nHow many shoes would you like to add?: ";
   cin >> shoesToAdd;
   errorCatcherInt(shoesToAdd);

   // For loop to add the shoes, repeats until number of shoes user wants to add is met
   for (int i = 0; i < shoesToAdd; i++)
   {
      /* Variables to hold various items
      tempBrand, tempModel, tempColor all hold the current shoe's brand, model, and color respectively
      tempShoe holds the current shoe to make it easier to add to the shoeList vector
       */
      string tempBrand, tempModel, tempColor;
      shoe tempShoe;

      // Prompts user to enter the details of the shoe
      cout << "Enter the brand of shoe #" << i + 1 << ": ";
      cin.ignore();
      getline(cin, tempBrand);
      cout << "Enter the model of shoe #" << i + 1 << ": ";
      getline(cin, tempModel);
      cout << "Enter the colorway of shoe #" << i + 1 << ": ";
      getline(cin, tempColor);

      shoeCheck(tempBrand, tempModel, tempColor);

      // Sets the properties for the temporary shoe and then adds it to the vector, then updates the count of the number of shoes
      tempShoe.setBrand(tempBrand);
      tempShoe.setModel(tempModel);
      tempShoe.setColor(tempColor);

      shoeList.push_back(tempShoe);
      numberOfShoes++;
   }

   sortList(shoeList);

   cout << "Finished adding shoes\n";
}

// Function to remove shoes when a list has been created or imported
void removeShoe(vector<shoe> &shoeList, int &numberOfShoes)
{
   // Variables declared to keep track of the number of shoes to remove and the index of each shoe that the user wants to remove
   int shoesToRemove;
   int shoeIndex;

   // Prompts the user to enter how many shoes they would like to remove
   cout << "\nHow many shoes would you like to remove?: ";
   cin >> shoesToRemove;

   errorCatcherInt(shoesToRemove);

   // For loop that iterates until it reaches the number of shoes the user wanted to remove
   for (int i = 0; i < shoesToRemove; i++)
   {
      int shoeNumber;
      cout << "Enter the number of the shoe you want to remove: ";
      cin >> shoeNumber;

      errorCatcherInt(shoeNumber);

      // Sets shoeIndex to the index of the shoe the user wants to remove, places that shoe at the end of the vector, then deletes that shoe off the vector
      shoeIndex = shoeNumber - 1;
      shoeList[shoeIndex] = shoeList.back();
      shoeList.pop_back();
      numberOfShoes--;
   }


   sortList(shoeList);
   cout << "Finished removing shoes\n";
}

