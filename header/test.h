/*
 * test.h
 *
 *  Created on: 2014-4-13
 *      Author: Administrator
 */

#ifndef TEST_H_
#define TEST_H_

#include <stdio.h>
#include <string>

#include "qsort.h"
#include "hsort.h"
#include "perm.h"

using namespace std;

void test_pair_type();

void test_map();

void test_max_cont_vector();

void test_readdouble_fromfile();

void test_vector_iterator();

void test_readappendfile();

void test_fstream();

void test_sstream();

void test_stream();

void test_lsort();

void test_hsort();

void test_qsort();

void test_folat();

void test_vector();

void test_is_shorter();

void test_cstyle_char();

void test_permaution();

void test_declare();

void test_void_pointer();

void testDeclareArray();

template<class T> int compare(const T& l, const T& r){
	if(l>r){
		return 1;
	} else if(l<r){
		return -1;
	} else{
		return 0;
	}
}
void func(char (&p)[10]);

void test_sizeof();

void test_arrays_3p(void);

void generate(int m,int n);

void test_mcoro();

void test_print_metric();

void test_file_();

void minprintf(char *fmt, ...);

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
//������
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
