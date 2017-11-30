#include "Rectangle.h"



/*
func returns area of rect
i: none
o: double : width * _length
*/
double myShapes::Rectangle::getArea() const
{
	return _width * _length;
}

/*
func returns perimeter of rect
i: none
o: double : (2*_width) + (2*_length)
*/
double myShapes::Rectangle::getPerimeter() const
{
	return (2*_width) + (2*_length);
}

/*
func draw rect 
i: cimg_library::CImgDisplay& disp, cimg_library::CImg<unsigned char>& board
o: none
*/
void myShapes::Rectangle::draw(cimg_library::CImgDisplay& disp, cimg_library::CImg<unsigned char>& board)
{
	unsigned char WHITE[] = { 255, 255, 255 };
	board.draw_rectangle(_points[0].getX(), _points[0].getY(),
		_points[1].getX(), _points[1].getY(), WHITE, 100.0f).display(disp);
}

/*
func paint drawen rect in black
i: cimg_library::CImgDisplay& disp, cimg_library::CImg<unsigned char>& board
o: none
*/
void myShapes::Rectangle::clearDraw(cimg_library::CImgDisplay& disp, cimg_library::CImg<unsigned char>& board)
{
	unsigned char BLACK[] = { 0, 0, 0};
	board.draw_rectangle(_points[0].getX(), _points[0].getY(),
		_points[1].getX(), _points[1].getY(), BLACK, 100.0f).display(disp);
}

// constractor
myShapes::Rectangle::Rectangle(const Point & a, double length, double width, const string & type, const string & name) : Polygon(type, name)
{
	if (length == 0 || width == 0) // lenght or hight cant be 0 in a rect
	{
		throw invalid_argument("length or width of Rectangle must be a positive value"); // throw exception
	}
	else // if its all fine init the rect
	{
		_length = length;
		_width = width;
		_points.push_back(a);
		_points.push_back(Point(a.getX() + width, a.getY() + length));
	}
}

// distractor
myShapes::Rectangle::~Rectangle()
{
}
