#pragma once
#include <iostream>
#include "Point.h"
#include "CImg.h"
#include <math.h>

using namespace std;
// abstract class for all shapes
class Shape 
{
public:
	Shape(const string& name, const string& type);
	virtual double getArea() const = 0;
	virtual double getPerimeter() const = 0;
	virtual void draw(cimg_library::CImgDisplay& disp, cimg_library::CImg<unsigned char>& board) = 0;
	virtual void move(const Point& other) = 0; 
	void printDetails() const;
	string getType() const;
	string getName() const;

	virtual void clearDraw(cimg_library::CImgDisplay& disp, cimg_library::CImg<unsigned char>& board) = 0;

private:
	string _name;
	string _type;

protected:
	
	std::vector<cimg_library::CImg<unsigned char>> _graphicShape;
};