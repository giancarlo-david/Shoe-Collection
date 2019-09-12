#pragma once
#include <string>

using namespace std;

class shoe
{
private:
	string brand; // To hold brand of shoe
	string model; // To hold the model of the shoe
	string color; // To hold the colorway of the shoe
public:
	shoe();
	~shoe();
	void setBrand(string);
	void setModel(string);
	void setColor(string);
	string getBrand() const;
	string getModel() const;
	string getColor() const;
};

