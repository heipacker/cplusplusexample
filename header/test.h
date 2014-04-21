/*
 * test.h
 *
 *  Created on: 2014-4-13
 *      Author: Administrator
 */

#ifndef TEST_H_
#define TEST_H_

#include <iostream>
using namespace std;

void test_goto();

void test_not_operation();

void test_read_line();

void test_print_eof();

void test_get_put_char();

void test_pre_print_array();

void test_pre_printf();

void test_pre_xinhao();

void test_pre_line();

void test_pre_inmacor();

void test_pre_vaargs();

void test_pre_swap();

void test_pre_process();

void testArrayPointer();

struct student {
	int idNumber;
	char name[15];
	int age;
	char department[20];
	float gpa;
};

class Shape {

public:
	string toString() {
		return NULL;
	}
};
/**
 *����
 */
class Rectangle: Shape {
private:
	int width, height;
public:
	Rectangle();

	void set_values(int, int);

	int area() {
		return width * height;
	}

	int getWidth() {
		return width;
	}

	int getHeight() {
		return height;
	}

	void setWidth(int width) {
		this->width = width;
	}

	void setHeight(int height) {
		this->height = height;
	}
};

enum Day {
	Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday
};

void nextday(Day &d) ;

void display(Day d) ;

void makenum() ;

void cal() ;

void output() ;
//��������
int abs(int a) ;

float abs(float a) ;

double abs(double a) ;

void testClass() ;

void printTypeSize() ;

void printType() ;

void testDefaultValue() ;

void testBeep() ;

void testOperation() ;

void testGlobalVar() ;

void localVarIncrement() ;

void testStaticLocalVar() ;

void testCondition() ;

void testSwitch() ;

void testOverride() ;

void testPointer() ;

void testEnum() ;

void testStruct() ;

void testHeader() ;

#endif /* TEST_H_ */
