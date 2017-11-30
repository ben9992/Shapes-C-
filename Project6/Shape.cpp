#include "Shape.h"
#include <iostream>
#include <string>
using namespace std;
// constractor
Shape::Shape(const string & name, const string & type) : _name(name), _type(type){}


/*
func prints basic details of shape : name and type
i: none
o: none
*/
void Shape::printDetails() const
{
	cout << "name: " << this->_name << " type: " << this->_type << endl;
}


/*
func returns type of shape
i: none
o: none
*/
string Shape::getType() const
{
	return this->_type;
}


/*
func returns name of shape
i: none
o: none
*/
string Shape::getName() const
{
	return this->_name;
}
