#include "Polygon.h"

//constractor
Polygon::Polygon(const string & type, const string & name) : Shape(name, type){}
 // distractor
Polygon::~Polygon(){}

/*
virtual func that adds value to X and Y of all shape pionts and move it
i: const Point & : other
o: none
*/
void Polygon::move(const Point & other)
{
	for (int i = 0; i < _points.size(); i++)
	{
		_points[i] += other; // for every point add the distance to the new position
	}
}

