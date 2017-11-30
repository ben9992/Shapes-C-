#include "Menu.h"
using namespace std;

// constractor
Menu::Menu() 
{
	_board  = new cimg_library::CImg<unsigned char>(700, 700, 1, 3, 1);
	_disp = new cimg_library::CImgDisplay(*_board, "Super Paint");
}

// distractor
Menu::~Menu()
{
	_disp->close();
	delete _board;
	delete _disp;
}


/*
that is the main function that manages the system
i: none
o: none
*/
void Menu::display_menu()
{
	int choice = 0;
	int index = 0;
	do
	{
		do
		{
			cout << "Enter 0 to add a new shape.\nEnter 1 to modify or get information from a current shape.\nEnter 2 to delete all of the shapes.\nEnter 3 to exit." << endl; // first menu
			cin >> choice;
			system("cls");
		} while (choice < 0 && choice > 3); // input check

		switch (choice)
		{
		case 0:  // create new shape
			do
			{
				cout << "Enter 0 to add a circle.\nEnter 1 to add an arrow.\nEnter 2 to add a triangle.\nEnter 3 to add a rectangle." << endl;// choose the shape you want to create
				cin >> choice;
				system("cls");
			} while (choice < 0 && choice > 3);// input check
			_shapes.push_back(createShape(choice)); // add the shape to the vector
			break;
		case 1: // modify
			if (!_shapes.empty()) // if there are shapes
			{
				do
				{
					for (unsigned int i = 0; i < _shapes.size(); i++) // display all shapes with index
					{
						cout << "Enter " << i << " for" << _shapes.at(i)->getName() << "(" << _shapes.at(i)->getType() << ")" << endl;
					}
					cin >> choice;
					system("cls");
				} while (choice < 0 && choice > _shapes.size() - 1);// input check

				index = choice;
				do
				{
					cout << "enter 0 - move the shape" << "\nenter 1 - get details of shape" << "\nenter 2 - remove the shape" << endl; // choose action
					cin >> choice;
					system("cls");
				} while (choice < 0 && choice > 2);// input check
				switch (choice)
				{
				case 0: // move the shape
					double x, y;
					cout << "Please enter the X moving scale: ";
					cin >> x;
					cout << "Please enter the Y moving scale: ";
					cin >> y;

					_shapes.at(index)->move(Point(x, y));
					deleteAndDraw(_shapes,index,2); // moving mode
					break;
				case 1: // print basic details
					_shapes.at(index)->printDetails();
					system("pause");
					break;
				case 2: // delete this shape
					deleteAndDraw(_shapes, index, 0); // delete by index mode
					break;
				system("cls");
				}
				choice = 0; // init the choice
			}
			break;
		case 2:
			// delete all
			deleteAndDraw(_shapes,0,1); //delete all mode
			break;
		}
		
	} while (choice != 3); // input check : if choice == 3 : exit
	
}

/*
func that manage the shapes creation
i: int : ch : shape choice
o: Shape* : ret
*/
Shape* Menu::createShape(int ch)
{
	Shape * ret = NULL;
	switch (ch)
	{
	case 0:
		ret = createCircle(); // create circle
		break;
	case 1:
		ret = createArrow();// create arrow
		break;
	case 2:
		try
		{
			ret = createTriangle();// create triangle
		}
		catch (invalid_argument) //catch exception if there is one
		{
			cout << "all points of triangle can not have the same X or Y value " << endl;
			system("pause");
			system("cls");
		}
		break;
	case 3:
		try
		{
			ret = createRect();  // create rectangle
		}
		catch (invalid_argument) //catch exception if there is one
		{
			cout << "width or length of rectangle must be a positive value "<< endl;
			system("pause");
			system("cls");
		}
		break;
	}
	ret->draw(*_disp, *this->_board);  //  draw the shape
	return ret;
}




/*
func creats a rectangle
i: none
o: Rectangle* ret
*/
myShapes::Rectangle* Menu::createRect()
{
	double _x, _y, _width, _lenght;
	string name;
	cout << "enter X of left conrner" << endl;    // gets all data from user
	cin >> _x;
	cout << "enter y of left conrner" << endl;
	cin >> _y;
	cout << "enter width of rect" << endl;
	cin >> _width;
	cout << "enter lenght of rect" << endl;
	cin >> _lenght;
	cout << "enter shape name" << endl;
	cin >> name;
	Point left(_x, _y); // new point
	myShapes::Rectangle * ret = new myShapes::Rectangle(left, _width, _lenght, "Rectangle", name); // new rect

	return ret; 
}


/*
func creats a rectangle
i: none
o: Rectangle* ret
*/
Circle * Menu::createCircle()
{
	double _x, _y, _radius;
	string name;
	cout << "enter X of center " << endl;     // gets all data from user
	cin >> _x;
	cout << "enter y of center" << endl;
	cin >> _y;
	cout << "enter _radius of circle" << endl;
	cin >> _radius;
	cout << "enter shape name" << endl;
	cin >> name;
	Point center(_x, _y); // new point
	Circle * ret = new Circle(center, _radius, "Circle", name); // new circle

	return ret;
}

Triangle * Menu::createTriangle()
{
	double _x, _y;
	string name;
	cout << "enter X of P1 " << endl; // gets all datafrom user
	cin >> _x;
	cout << "enter y of P1" << endl;
	cin >> _y;
	Point p1(_x, _y);
	cout << "enter X of P2 " << endl;
	cin >> _x;
	cout << "enter y of P2" << endl;
	cin >> _y;
	Point p2(_x, _y);
	cout << "enter X of P3 " << endl;
	cin >> _x;
	cout << "enter y of P3" << endl;
	cin >> _y;
	Point p3(_x, _y);
	cout << "enter shape name" << endl;
	cin >> name;
	Triangle * ret = new Triangle(p1, p2, p3, "Triangle", name); //  new triange

	return ret;
}

Arrow* Menu::createArrow()
{
	double _x, _y;
	string name;
	cout << "enter X of P1 " << endl;
	cin >> _x;
	cout << "enter y of P1" << endl;    // gets all datafrom user
	cin >> _y;
	Point p1(_x, _y);
	cout << "enter X of P2 " << endl;
	cin >> _x;
	cout << "enter y of P2" << endl;
	cin >> _y;
	Point p2(_x, _y);
	cout << "enter shape name" << endl;
	cin >> name;
	Arrow * ret = new Arrow(p1, p2, "Arrow", name);  // new arrow
	return ret;

}

/*
func that clear the display, update the data struture if needed, and draw all back(?)
this func has 3 modes:
	# 0  delete by index
	# 1  delete all
	# 2  refresh

i: vector<Shape*> , int , int  ::  &shapes , index , mode
o: none
*/
void Menu::deleteAndDraw(vector<Shape*> &shapes, int index , int mode)
{
	for (int i = 0; i < shapes.size(); i++)
	{
		shapes.at(i)->clearDraw(*_disp, *_board); //  paint all the display in black
	}
	if (mode == 0)        // # 0
	{
		shapes.erase(_shapes.begin() + index); //erase by index
		for (int i = 0; i < shapes.size(); i++)
		{
			shapes.at(i)->draw(*_disp, *_board); // draw everything in the vector
		}
	}
	else if(mode == 1)   // # 1
	{
		shapes.clear();  // erase all
	}
	else    // # 2
	{
		for (int i = 0; i < shapes.size(); i++)
		{
			shapes.at(i)->draw(*_disp, *_board);  // draw it all back
		}
	}
	
}


