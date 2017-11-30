#include "Circle.h"

// constractor
Circle::Circle(const Point & center, double radius, const string & type, const string & name) : Shape(name, type), _center(center), _radius(radius){}

// distractor
Circle::~Circle(){}

/*
func returns the center point of the circle
i: none
o: Point : center
*/
const Point & Circle::getCenter() const
{
	return _center;
}


/*
func returns radius of the circle
i: none
o: double : radius 
*/
double Circle::getRadius() const
{
	return _radius;
}

/*
func draws a circle
i: cimg_library::CImgDisplay& disp, cimg_library::CImg<unsigned char>& board
o: none
*/
void Circle::draw(cimg_library::CImgDisplay& disp, cimg_library::CImg<unsigned char>& board)
{
	unsigned char BLUE[] = { 0, 0, 255 };
	const Point& c = getCenter();
	board.draw_circle(c.getX(), c.getY(), getRadius(), BLUE, 100.0f).display(disp);	
}


/*
func paint a circle in black
i: cimg_library::CImgDisplay& disp, cimg_library::CImg<unsigned char>& board
o: none
*/
void Circle::clearDraw(cimg_library::CImgDisplay& disp, cimg_library::CImg<unsigned char>& board)
{
	unsigned char BLACK[] = { 0, 0, 0 };
	
	board.draw_circle(_center.getX(), _center.getY(),_radius, BLACK, 100.0f).display(disp);
	
}

/*
func returns area of circle
i: none
o: double : 2*PI*R
*/
double Circle::getArea() const
{
	return PI * pow(_radius,2);
}


/*
func returns perimeter of circle
i: none
o: double : PI*R^2
*/
double Circle::getPerimeter() const
{
	return 2 * PI * _radius;
}

/*
func adds to the center point X and Y values and move the shape acordingly
i: const Point & : other
o: none
*/
void Circle::move(const Point & other)
{
	_center += other;
}




