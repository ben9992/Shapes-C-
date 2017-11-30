#include "Triangle.h"



Triangle::Triangle(const Point & a, const Point & b, const Point & c, const string & type, const string & name) : Polygon(type, name)
{
	if ((a.getX() == b.getX() && a.getX() == c.getX() && b.getX() == c.getX()) || (a.getY() == b.getY() && a.getY() == c.getY() && b.getY() == c.getY())) // it cant be a triangle if all the points on the same axis value
	{
		throw invalid_argument("Error: all 3 corners of the triangle on the same axis"); // throw exception
	}
	else // if all fine - init the triangle
	{
		this->_points.push_back(a);
		this->_points.push_back(b);
		this->_points.push_back(c);
	}
}
 // distractor
Triangle::~Triangle()
{
}

/*
func returns area of triangle
i: none
o: double area
*/
double Triangle::getArea() const
{
	return (_points[2].getY() - _points[0].getY())*(_points[1].getX() - _points[0].getX()) / 2; // delta(X) * delta(Y) / 2
}


/*
func returns perimeter of triangle
i: none
o: double perimeter
*/
double Triangle::getPerimeter() const
{
	return _points[0].distance(_points[1]) + _points[1].distance(_points[2]) + _points[2].distance(_points[0]); // distance between points is the size of the side of the triangle : side1 + side2 + side3
}



/*
func draw triangle
i: cimg_library::CImgDisplay& disp, cimg_library::CImg<unsigned char>& board
o: none
*/
void Triangle::draw(cimg_library::CImgDisplay& disp, cimg_library::CImg<unsigned char>& board)
{
	unsigned char GREEN[] = { 0, 255, 0 };
	board.draw_triangle(_points[0].getX(), _points[0].getY(),
		_points[1].getX(), _points[1].getY(),
		_points[2].getX(), _points[2].getY(), GREEN, 100.0f).display(disp);
}

/*
func paint triangle in black
i: cimg_library::CImgDisplay& disp, cimg_library::CImg<unsigned char>& board
o: none
*/
void Triangle::clearDraw(cimg_library::CImgDisplay& disp, cimg_library::CImg<unsigned char>& board)
{
	unsigned char BLACK[] = { 0, 0, 0 };
	board.draw_triangle(_points[0].getX(), _points[0].getY(),
		_points[1].getX(), _points[1].getY(),
		_points[2].getX(), _points[2].getY(), BLACK, 100.0f).display(disp);
}


