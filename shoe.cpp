#include "shoe.h"
#include <string>

using namespace std;


shoe::shoe()
{
	brand = "null";
	model = "null";
	color = "null";
}


shoe::~shoe()
{
}

void shoe::setBrand(string b)
{
	brand = b;
}

void shoe::setModel(string m)
{
	model = m;
}

void shoe::setColor(string c)
{
	color = c;
}

string shoe::getBrand() const
{
	return brand;
}

string shoe::getModel() const
{
	return model;
}

string shoe::getColor() const
{
	return color;
}
