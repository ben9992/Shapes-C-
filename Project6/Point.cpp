#include "Point.h"

// constractor
Point::Point(double x, double y) : x(x), y(y){}

// copy constractor
Point::Point(const Point & other) : Point(other.getX(), other.getY()){}

//distractor
Point::~Point(){}

/*
overloading + operator
i: const Point & : other
o: Point 
*/
Point Point::operator+(const Point & other) const
{
	return Point((this->getX() + other.getX()), (this->getY() + other.getY()));
}


/*
overloading += operator
i: const Point & : other
o: Point & this
*/
Point & Point::operator+=(const Point & other)
{
	this->x += other.getX();
	this->y += other.getY();
	return *this;
}

/*
func returns X of point
i: none
o: double : x
*/
double Point::getX() const
{
	return this->x;
}

/*
func returns y of point
i: none
o: double : y
*/
double Point::getY() const
{
	return this->y;
}


/*
func calculate distance between two pionts
i: const Point & : other
o: double : distance
*/
double Point::distance(const Point & other) const
{
	return sqrt(pow(other.getX() - this->getX(),2) + pow(other.getY() - this->getY(),2)); // distance formula
}
