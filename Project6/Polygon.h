#pragma once

#include "Shape.h"
#include "Point.h"
#include <iostream>
#include <vector>
//#include "Cimg.h"
// abstract class for all polygon based shapes
using namespace std;

class Polygon : public Shape
{
public:
	Polygon(const string& type, const string& name);
	virtual ~Polygon();


	// override functions if need (virtual + pure virtual)
	virtual double getArea() const = 0;
	virtual double getPerimeter() const = 0;
	virtual void move(const Point& other);
	virtual void draw(cimg_library::CImgDisplay& disp, cimg_library::CImg<unsigned char>& board) = 0;
	virtual void clearDraw(cimg_library::CImgDisplay& disp, cimg_library::CImg<unsigned char>& board) = 0;
protected:
	vector<Point> _points; // contains all the points of the polygon type shape
};