#pragma once
#include "Polygon.h"

namespace myShapes
{
	// Calling it MyRectangle becuase Rectangle is taken by global namespace.
	class Rectangle : public Polygon
	{
	public:
		// There's a need only for the top left corner 
		Rectangle(const Point& a, double length, double width, const string& type, const string& name);
		virtual ~Rectangle();

		// override functions if need (virtual + pure virtual)
		virtual double getArea() const;
		virtual double getPerimeter() const;
		virtual void draw(cimg_library::CImgDisplay& disp, cimg_library::CImg<unsigned char>& board);
		virtual void clearDraw(cimg_library::CImgDisplay& disp, cimg_library::CImg<unsigned char>& board);

	private:
		double _width;
		double _length;
		

	};
}