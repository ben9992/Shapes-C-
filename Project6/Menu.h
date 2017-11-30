#pragma once
#include "Circle.h"
#include "Arrow.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "CImg.h"
#include <vector>
#include <iostream>
#include <sstream>


class Menu
{
public:

	Menu();
	~Menu();

	void display_menu();
	Shape * createShape(int ch);
	myShapes::Rectangle * createRect();
	Circle * createCircle();
	Triangle * createTriangle();
	Arrow * createArrow();
	void deleteAndDraw(vector<Shape*> &shapes, int index, int mode);

private: 

	vector<Shape*> _shapes; // contains all the created shapes

	cimg_library::CImg<unsigned char>* _board;
	cimg_library::CImgDisplay* _disp;
};

