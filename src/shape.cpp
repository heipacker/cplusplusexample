/*
 * shape.cpp
 *
 *  Created on: 2014-4-13
 *      Author: Administrator
 */
#include "math.h"//�ڼ������������ʱҪ�õ����Һ���
#include "../header/shape.h"

extern const double pi;

//��������
double perimeter_of_circle(double r) {
	return 2 * pi * r;
}
double area_of_circle(double r) {
	return pi * r * r;
}
double perimeter_of_square(double a) {
	return 4 * a;
}
double area_of_square(double a) {
	return a * a;
}
double perimeter_of_rectangle(double a, double b) {
	return 2 * (a + b);
}
double area_of_rectangle(double a, double b) {
	return a * b;
}
double perimeter_of_triangle(double a, double b, double c) {
	return a + b + c;
}
double area_of_triangle(double a, double b, double gamma) {
	return sin(gamma / 180 * pi) * a * b / 2;
}
