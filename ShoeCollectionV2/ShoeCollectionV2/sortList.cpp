#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include "shoe.h"

using namespace std;

// Boolean function that acts as the key on how the shoe list is sorted
bool compareTwoShoes(shoe a, shoe b)
{
	if (a.getBrand() != b.getBrand())
		return a.getBrand() < b.getBrand();

	if (a.getModel() != b.getModel())
		return a.getModel() < b.getModel();

	return a.getColor() < b.getColor();
}

// Function that sorts the current list
void sortList(vector<shoe> &list)
{
	sort(list.begin(), list.end(), compareTwoShoes);
}