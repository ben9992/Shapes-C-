#include "Arrow.h"


// constractor
Arrow::Arrow(const Point & a, const Point & b, const string & type, const string & name) : Shape(name, type), _p1(a), _p2(b){}

//distractor
Arrow::~Arrow() {}


/*
func draw an arrow
i: cimg_library::CImgDisplay& disp, cimg_library::CImg<unsigned char>& board
o: none
*/
void Arrow::draw(cimg_library::CImgDisplay& disp, cimg_library::CImg<unsigned char>& board)
{
	unsigned char RED[] = { 255, 0, 0 };

	board.draw_arrow(_p1.getX(), _p1.getY(),
		_p2.getX(), _p2.getY(), RED, 100.0f).display(disp);
}


/*
func paint an arrow in black
i: cimg_library::CImgDisplay& disp, cimg_library::CImg<unsigned char>& board
o: none
*/
void Arrow::clearDraw(cimg_library::CImgDisplay& disp, cimg_library::CImg<unsigned char>& board)
{
	unsigned char BLACK[] = { 0, 0, 0 };

	board.draw_arrow(_p1.getX(), _p1.getY(),
		_p2.getX(), _p2.getY(), BLACK, 100.0f).display(disp);
}

/*
func returns area of arrow
i: none
o: double : 0
*/
double Arrow::getArea() const
{
	return 0.0; // area of arrow is allways 0
}


/*
func returns perimeter of arrow
i: none
o: double : length of arrow
*/
double Arrow::getPerimeter() const
{
	return _p1.distance(_p2);
}

/*
func add X and Y values to the arrow points and move it
i: const Point & : other
o: none
*/
void Arrow::move(const Point & other)
{
	_p1 += other;
	_p2 += other;
}