/*
 * shap.h
 *
 *  Created on: 2014-4-13
 *      Author: Administrator
 */

#ifndef SHAP_H_
#define SHAP_H_

const double pi = 3.14159265358; //常量定义
//类型声明
struct circle {
	double r;
};
struct square {
	double a;
};
struct rectangle {
	double a, b;
};
struct triangle {
	double a, b, c, alpha, beta, gamma;
};
//函数定义
double perimeter_of_circle(double r) ;
double area_of_circle(double r) ;
double perimeter_of_square(double a) ;
double area_of_square(double a) ;
double perimeter_of_rectangle(double a, double b) ;
double area_of_rectangle(double a, double b) ;
double perimeter_of_triangle(double a, double b, double c) ;
double area_of_triangle(double a, double b, double gamma) ;

#endif /* SHAP_H_ */
