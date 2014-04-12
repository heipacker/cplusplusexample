//============================================================================
// Name        : cplusplusexample.cpp
// Author      : heipacker
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
class Shape{

public:
	string toString(){
		return NULL;
	}
};
/**
 *¾ØÐÎ
 */
class Rectangle:Shape{
private:
	int width, height;
public:
	Rectangle();

	void set_values(int, int);

	int area() {
		return width * height;
	}

	int getWidth(){
		return width;
	}

	int getHeight(){
		return height;
	}

	void setWidth(int width){
		this->width = width;
	}

	void setHeight(int height){
		this->height = height;
	}
};

Rectangle::Rectangle() {
	width = 5;
	height = 5;
}

void Rectangle::set_values(int x, int y) {
	width = x;
	height = y;
}

int main() {
	Rectangle rect;
	rect.set_values(3, 4);
	cout << "area: " << rect.area() << endl;
	return 0;
}
