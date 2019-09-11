#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Declare function prototypes
void mainMenu(int &numberOfShoes, string *shoeList);
void readInput(int &numberOfShoes, string *shoeList);
void allocateData(int numberOfShoes, string *shoeList);
void numberToAdd(int &numberOfShoes);
void checkNumberOfShoes(int &numberOfShoes);
void addShoes(int numberOfShoes, string *shoeList);
void sortShoeList(int numberOfShoes, string *shoeList);
void displayList(int numberOfShoes, string *shoeList);
void printToText(int numberOfShoes, string *shoeList);
void switchMenu(int numberOfShoes, string *shoesList);


int main()
{
	/* Declare variables
	numberOfShoes = Number of shoes being entered into program
	*shoeList = Will store all shoes in dynamic array
	*/
	int numberOfShoes;
	string *shoeList;

	// Welcome message
	cout << "\t\tWelcome to the Simple Shoe Sorter!" << endl;

	numberToAdd(numberOfShoes);
	checkNumberOfShoes(numberOfShoes);

	// Dynamically allocate shoeList
	shoeList = new (nothrow) string[numberOfShoes];

	// Error message if allocating memory goes wrong
	if (shoeList == nullptr)
	{
		cout << "Error allocating memory!" << endl;
	}


	addShoes(numberOfShoes, shoeList);

	cout << "\n\nList Completed." << endl;

	switchMenu(numberOfShoes, shoeList);

	delete[] shoeList;

	system("pause");
	return 0;
}

// Function to get number of shoes to add to list
void numberToAdd(int &numberOfShoes)
{
	cout << "\nHow many shoes would you like to enter into the list?" << endl;
	cout << "Number of shoes: ";
	cin >> numberOfShoes;
}

// Function that checks that the correct number is entered for variable 'numberOfShoes'
void checkNumberOfShoes(int &numberOfShoes)
{
	// Declare variable that stores Yes/No answer
	string choiceCheck;

	// Do while loop for until variable 'choiceCheck' equals yes
	do
	{
		// Prompt and get answer to see if number entered is correct
		cout << "\nIs " << numberOfShoes << " the correct number? (Y/N)" << endl;
		cin >> choiceCheck;

		// If statement for when variable 'choiceCheck' equals Yes
		if (choiceCheck == "y" || choiceCheck == "Y")
		{
			cout << "\nTime to add shoes!\n" << endl;
		}

		// If statement for when variable 'choiceCheck' equals No
		else if (choiceCheck == "n" || choiceCheck == "N")
		{
			cout << "\nPlease enter the correct number: ";
			cin >> numberOfShoes;
		}

		// Else statmement for when variable 'choiceCheck' does not equal Yes or No
		else
		{
			cout << "Please enter (Y/N)" << endl;
		}

	} while (choiceCheck != "y" && choiceCheck != "Y");
}


// Function that adds shoes to the program
void addShoes(int numberOfShoes, string *shoeList)
{
	// Declare the pointers for dynamic arrays of each part of shoe
	string *brand;
	string *model;
	string *colorway;

	// Declare string to store combined aspects of shoe
	string combineName;

	// Declare string to store blank from getline function
	string x;

	// Declare character variable for Yes/No questions
	string check;

	// Initiate dynamic arrays
	brand = new (nothrow) string[numberOfShoes];
	model = new (nothrow) string[numberOfShoes];
	colorway = new (nothrow) string[numberOfShoes];

	// Error code if dynamic array fails to allocate memory
	if (brand == nullptr || model == nullptr || colorway == nullptr)
	{
		cout << "Error allocating memory!" << endl;
	}

	// For loop to go through the numberOfShoes
	for (int i = 0; i < numberOfShoes; i++)
	{
		// Get information about the shoe
		getline(cin, x);
		cout << "Enter the brand of shoe #" << i + 1 << ":";
		getline(cin, brand[i]);
		cout << "Enter the model of shoe #" << i + 1 << ":";
		getline(cin, model[i]);
		cout << "Enter the colorway of shoe #" << i + 1 << ":";
		getline(cin, colorway[i]);
		cout << endl;

		// Do while loop until variable 'check' equals yes
		do
		{
			cout << "Is " << brand[i] << " " << model[i] << " " << colorway[i] << " correct? (Y/N)" << endl;
			cin >> check;

			// If statement for when variable 'check' equals yes
			if (check == "y" || check == "Y")
			{
				// Store components of shoe into variable combineName
				combineName = brand[i] + " " + model[i] + " " + colorway[i];

				// Store the full shoe name into its spot in the dynamic array shoeList
				shoeList[i] = combineName;
				cout << endl;
			}

			// If statement for when variable 'check' equals no
			else if (check == "n" || check == "N")
			{
				cout << "\n Please enter the information again." << endl;
				i -= 1;
			}

			// Else statment for when variable doesn't equal yes or no
			else
			{
				cout << "\nPlease enter (Y/n)\n" << endl;
			}
		} while (check != "y" && check != "n" && check != "Y" && check != "N");
	}

	// Delete temporary dynamic arrays that held information of the shoe that is now stored in *shoeList
	delete[] brand;
	delete[] model;
	delete[] colorway;
}

// Function to sort shoes in alphabetical order
void sortShoeList(int numberOfShoes, string *shoeList)
{
	string temp;

	// Prompt to let user know program is sorting 
	cout << endl << "\nSorting..." << endl;

	// Sort in ascending order
	for (int i = 0; i < numberOfShoes; i++)
	{
		for (int j = i + 1; j < numberOfShoes; j++)
		{
			if (shoeList[j] < shoeList[i])
			{
				temp = shoeList[i];
				shoeList[i] = shoeList[j];
				shoeList[j] = temp;
			}
		}
	}

	// Prompt to let user know program is done sorting
	cout << "Complete!" << endl << endl;
}

// Function to display currrent shoe list 
void displayList(int numberOfShoes, string *shoeList)
{
	// Extra line before list prints for aesthetic
	cout << endl;

	// Display the current list of shoes
	for (int i = 0; i < numberOfShoes; i++)
	{
		cout << shoeList[i] << endl;
	}

	// Extra line after list prints for aesthetic
	cout << endl;
}

// Function to print list to personalized txt file
void printToText(int numberOfShoes, string *shoeList)
{
	// Declare output file and string variable to store name
	ofstream shoeFile;
	string name;

	// Ask for your user's name to personalize the output list
	cout << "\nEnter your name: ";
	getline(cin, name);
	getline(cin, name);

	// Open ShoeFile.txt output file
	shoeFile.open(name + "'sShoeFile.txt");

	// Output the collection
	shoeFile << "\t" << name << "'s Shoe Collection" << endl << endl;
	for (int i = 0; i < numberOfShoes; i++)
	{
		shoeFile << shoeList[i] << endl;
	}

	// Close file
	shoeFile.close();

	// Prompt to let user know the file has finished printing
	cout << "\nFile printed!" << endl << endl;
}

// Function for menu after inputting shoes
void switchMenu(int numberOfShoes, string *shoeList)
{
	// Declare variable choice and the output file
	int choice;
	ofstream shoeFile;

	// Enter do while loop for until user wants to exit the program
	do
	{
		// Show menu and prompt for user choice
		cout << "Select an option to continue:" << endl;
		cout << "1. Show list" << endl;
		cout << "2. Sort List" << endl;
		cout << "3. Print list to text file" << endl;
		cout << "4. Exit Program" << endl;
		cin >> choice;

		// Switch to emulate menu
		switch (choice)
		{
		case 1:
			displayList(numberOfShoes, shoeList);
			break;
		case 2:
			sortShoeList(numberOfShoes, shoeList);
			break;
		case 3:
			printToText(numberOfShoes, shoeList);
			break;
		case 4:
			break;
		default:
			cout << "Please enter one of the options" << endl;
			break;
		}
	} while (choice != 4);
}