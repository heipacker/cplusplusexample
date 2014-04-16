/*
 * test.cpp
 *
 *  Created on: 2014-4-13
 *      Author: Administrator
 */
#include "stdio.h"
#include "stdlib.h"//用于产生随机数
#include "time.h"//用于产生随机数
#include <iomanip>
#include <typeinfo>
#include <iostream>
#include "../header/shape.h"
#include "../header/test.h"
using namespace std;
#define TEST

#ifdef TEST

#define Z

#elif 1

#define A

#else

#define B

#endif

#define X 2
#define Y X*2

#undef X

#define X 3
#define PRINTF(x) printf("the "#x"lait %d\n",((x)*(x)));
#define SCAN(N,String) scanf("%"#N"s",String);  //N是截取的个数  String是存储的字符串

#define BL1 bb##ll##1

#define BL(N) bbll##N

#define incr(v, low, high) \
  do{ for ((v) = (low); (v) <= (high); (v)++); }while(0)

#define swap(x,y) do { unsigned long _temp=x; x=y; y=_temp;} while (0)

#ifdef DEBUG
#define my_printf(...) fprintf(stderr, __VA_ARGS__)
#else
#define my_printf(...) printf(__VA_ARGS__)
#endif

#define TEST1(a,b) do{ printf( #a "<" #b "=%d\n", (a)<(b)); }while(0)

void test_pre_xinhao(){
	TEST1(1, 2);
}

void test_pre_line(){
	printf("line: %d, file: %s\n", __LINE__, __FILE__);
	#line 100 "test_pre_line"
	printf("line: %d, file: %s\n", __LINE__, __FILE__);
	printf("line: %d, file: %s\n", __LINE__, __FILE__);
}

void test_pre_inmacor(){
	printf("当前行号：%d\n", __LINE__);
	printf("当前源文件：%s\n", __FILE__);
	printf("编译日期：%s\n", __DATE__);
	printf("编译时间：%s\n", __TIME__);
	printf("是否符合STD标准：%d\n", __STDC__);
}

void test_pre_vaargs(){
	my_printf("111111111");
}

void test_pre_swap(){
	int x = 0, y = 1;
	swap(x, y);
	printf("%d, %d\n", x, y);
	int a = 0;
	incr(a,1, 10);
	printf("%3d\n", a);
}

void test_pre_process(){
	int BL1=10;
	int BL(4)=15;
	printf("%d\n", BL1);
	printf("%d\n", BL(4));
	printf("%d\n", Y);
	PRINTF(3)
	char dd[256] = {'1','2','3','\0'};
	char db[256] = "121212";
	//SCAN(2, dd)
	printf("%s size:%d\n", dd, sizeof(dd));
	printf("%s size:%d\n", db, sizeof(db));
}

void testArrayPointer(){
	int a[2][2] = {{1,2},{3,4}};
	char c[3] = {'1','2','\0'};
	//int **aa;//类型int** 指向的类型int*
	int (*b)[2];//类型int (*)[2] 指向的类型int a[2]
	char (*bc)[3];
	b = a;
	bc = &c;
	/*aa = &(&a);
	printf("aa:%d\n", **aa);*/
	printf("b:%d\n", *(*b+1));
	printf("bc:%s\n", *bc);
	printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
}

void testClass() {
	Rectangle rect;
	rect.set_values(3, 4);
	cout << "area: " << rect.area() << endl;
}

void printTypeSize() {
	cout
			<< "--------------------------------------------printTypeSize---------------------------------"
			<< endl;
	char b = 65; //1字节
	cout << "char b sizeof:" << sizeof(b) << "字节" << endl;
	signed char l = 11; //1字节 默认
	cout << "signed char l sizeof:" << sizeof(l) << "字节" << endl;
	unsigned char j = 9; //1字节
	cout << "unsigned char j sizeof:" << sizeof(j) << "字节" << endl;

	int a = 1; //4字节
	cout << "int a sizeof:" << sizeof(a) << "字节" << endl;
	unsigned int f = 5; //4字节 无符号型
	cout << "unsigned int f sizeof:" << sizeof(f) << "字节" << endl;
	long int e = 4; //4字节默认
	cout << "long int e sizeof:" << sizeof(e) << "字节" << endl;
	unsigned long int m = 12; //4字节 无符号型 默认
	cout << "unsigned long int m sizeof:" << sizeof(m) << "字节" << endl;
	short int d = 3; //2字节
	cout << "short int d sizeof:" << sizeof(d) << "字节" << endl;
	unsigned short int g = 6; //2字节
	cout << "unsigned short int g sizeof:" << sizeof(g) << "字节" << endl;

	float h = 7; //4字节
	cout << "float h sizeof:" << sizeof(h) << "字节" << endl;
	double i = 8; //8字节
	cout << "double i sizeof:" << sizeof(i) << "字节" << endl;
	long double c = 11;
	cout << "long double c sizeof:" << sizeof(c) << "字节" << endl;

	bool k = 10; //1字节
	cout << "bool k sizeof:" << sizeof(k) << "字节" << endl;
	cout
			<< "--------------------------------------------printTypeSize---------------------------------"
			<< endl;

	//输出
//	cout << a << '\t' << b << '\t' << c << '\t' << d << '\t' << e << '\t' << f << '\t' << g << '\t' << h << '\t' << i << '\t' << j << '\t' << k << '\t' << l << '\t' << m << '\t';
}

void printType() {
	cout
			<< "--------------------------------------------printType---------------------------------"
			<< endl;
	char b = 65; //1字节
	cout << "char b type:" << typeid(b).name() << endl;
	signed char l = 11; //1字节 默认
	cout << "signed char l type:" << typeid(l).name() << endl;
	unsigned char j = 9; //1字节
	cout << "unsigned char j type:" << typeid(j).name() << endl;

	int a = 1; //4字节
	cout << "int a type:" << typeid(a).name() << endl;
	unsigned int f = 5; //4字节 无符号型
	cout << "unsigned int f type:" << typeid(f).name() << endl;
	long int e = 4; //4字节默认
	cout << "long int e type:" << typeid(e).name() << endl;
	unsigned long int m = 12; //4字节 无符号型 默认
	cout << "unsigned long int m type:" << typeid(m).name() << endl;
	short int d = 3; //2字节
	cout << "short int d type:" << typeid(d).name() << endl;
	unsigned short int g = 6; //2字节
	cout << "unsigned short int g type:" << typeid(g).name() << endl;

	float h = 7; //4字节
	cout << "float h type:" << typeid(h).name() << endl;
	double i = 8; //8字节
	cout << "double i type:" << typeid(i).name() << endl;
	long double c = 11;
	cout << "long double c type:" << typeid(c).name() << endl;

	bool k = 10; //1字节
	cout << "bool k type:" << typeid(k).name() << endl;
	cout
			<< "--------------------------------------------printType---------------------------------"
			<< endl;
}

void testDefaultValue() {
	int c;
	cout << c << endl; //未知值
	cin >> c;
	cout << c << endl;

	double a;
	cout << a << endl; //未知值
	cin >> a;
	cout << a << endl;

	bool b = 21L;
	cout << b << endl;
	cin >> b;
	cout << b << endl;
}

void testBeep() {
	cout << "\t\a" << endl;
	//cout << '\a';
	//printf("\007");
	//printf("\b");
	//printf("%c",'\a');
	//printf("%c",'\007');
}

void testOperation() {
	cout << 3 + 4 << endl;
	//L/l表示双精度的常量
	//F/f表示单精度的常量

	const float fa = 1.12L;
	//fa = 12;
	cout << fa << endl;
	const double da = 1.121;
	cout << da << endl;

	int aa = 7;
	int ab = -2;
	int ac = -7;
	int ad = 2;
	//正常除法结果
	cout << "7/-2=" << aa / ab << endl;
	cout << "-7/2=" << ac / ad << endl;
	//结果的正负号与第一个操作符相同
	cout << "7%-2=" << aa % ab << endl;
	cout << "-7%2=" << ac % ad << endl;
	//操作数不能为非整型
	//cout << 1.1%2 << endl;
	//cout << 1%2.1 << endl;

	int aab, aac;
	aab = aac = 1;
	cout << aab << '\t' << aac << endl;
}

void testGlobalVar() {
	srand(time(NULL));	//用于产生随机数，不必理会
	for (int i = 0; i < 4; i++) {
		makenum();	//产生随机数放入缓冲区
		cal();	//对缓冲区的数进行处理
		output();	//输出缓冲区的数值
	}
}

void localVarIncrement() {
	static int currentNum;	//未初始化  编译器自动初始化为0
	cout << ++currentNum << endl;
}

void testStaticLocalVar() {
	for (int i = 0; i < 4; ++i) {
		localVarIncrement();
	}
}

void testCondition() {
	int a, b;
	cout << "请输入两个数：";
	cin >> a >> b;
	if (a > b) {	//如果a比b大，则将两个数交换
		int temp;	//创建一个临时变量
		temp = a;
		a = b;
		b = temp;
	}
	cout << a << " " << b << endl;	//将两个数从小到大输出
}

void testSwitch() {
	float a, b;
	char oper;
	cout << "请输入一个表达式（eg.1+2）：" << endl;
	cin >> a >> oper >> b;
	switch (oper) {
	case '+': {
		cout << a << oper << b << '=' << a + b << endl;
		break;
	}
	case '-': {
		cout << a << oper << b << '=' << a - b << endl;
		break;
	}
	case '*': {
		cout << a << oper << b << '=' << a * b << endl;
		break;
	}
	case '/': {
		if (b != 0)
			cout << a << oper << b << '=' << a / b << endl;
		else
			cout << "出错啦！" << endl;
		break;
	}
	default:
		cout << "出错啦！" << endl;
	}
	//测试
	char test = 'a';
	switch (test) {
	case 'a': {
		cout << "a";
		break;
	}
	case 'b': {
		cout << "b";
		break;
	}
	default: {
		cout << "default";
	}
	}
}

void testOverride() {
	int a = -5, b = 3;
	float c = -2.4f, d = 8.4f;
	double e = -3e-9, f = 3e6;
	cout << "a=" << abs(a) << endl << "b=" << abs(b) << endl;	//输出函数返回的结果
	cout << "c=" << abs(c) << endl << "d=" << abs(d) << endl;
	cout << "e=" << abs(e) << endl << "f=" << abs(f) << endl;
}

void testPointer() {
	int i = 3;
	int *iptr = &i;
	int **iptrptr = &iptr;	//iptr也是变量，也能够获取它的地址
	cout << "Address of Var i=" << iptr << endl;	//输出iptr存储的内容，即i在内存中的地址
	cout << "Data of Var i=" << *iptr << endl;	//输出iptr所指向的变量
	cout << "Address of Pointer iptr=" << iptrptr << endl;	//输出iptr在内存中的地址
	cout << "Address of Var i=" << *iptrptr << endl;	//输出iptrptr所指向的变量，即iptr
	*iptr = 2 + *iptr;	//*iptr可以作左值
	cout << "Data of Var i=" << *iptr << endl;
}

void testEnum() {
	Day today = Sunday;
	for (int i = 0; i < 7; i++) {
		cout << "Data in today=" << today << endl;
		display(today);
		nextday(today);
	}
}

void testStruct() {
	student s1, s2;	//首次使用student类型名，定义必须在这之前。
	cout << "输入学号：";
	cin >> s1.idNumber;	//成员数据可以被写入
	cout << "输入姓名：";
	cin >> s1.name;
	cout << "输入年龄：";
	cin >> s1.age;
	cout << "输入院系：";
	cin >> s1.department;
	cout << "输入成绩：";
	cin >> s1.gpa;
	cout << "学生s1信息：" << endl << "学号：" << s1.idNumber << "姓名：" << s1.name
			<< "年龄：" << s1.age << endl << "院系：" << s1.department << "成绩："
			<< s1.gpa << endl;	//成员数据也能够被读出
	s2 = s1;	//把s1的给各个成员数据值分别复制到s2中
	cout << "学生s2信息：" << endl << "学号：" << s2.idNumber << "姓名：" << s2.name
			<< "年龄：" << s2.age << endl << "院系：" << s2.department << "成绩："
			<< s2.gpa << endl;
	//初始化
	student s3 = { 428004, "Tomato", 20, "ComputerScience", 84.5 };
	student *s4 = &s3;
	cout << "学生s4信息：" << endl << "学号：" << s4->idNumber << "姓名：" << s4->name
			<< "年龄：" << s4->age << endl << "院系：" << s4->department << "成绩："
			<< s4->gpa << endl;	//成员数据也能够被读出
}
void nextday(Day &D) {
	switch (D) {
	case Sunday:
		D = Monday;
		break;
	case Monday:
		D = Tuesday;
		break;
	case Tuesday:
		D = Wednesday;
		break;
	case Wednesday:
		D = Thursday;
		break;
	case Thursday:
		D = Friday;
		break;
	case Friday:
		D = Saturday;
		break;
	case Saturday:
		D = Sunday;
		break;
	}
}
void display(Day D) {
	switch (D) {
	case Sunday:
		cout << "Sunday" << endl;
		break;
	case Monday:
		cout << "Monday" << endl;
		break;
	case Tuesday:
		cout << "Tuesday" << endl;
		break;
	case Wednesday:
		cout << "Wednesday" << endl;
		break;
	case Thursday:
		cout << "Thursday" << endl;
		break;
	case Friday:
		cout << "Friday" << endl;
		break;
	case Saturday:
		cout << "Saturday" << endl;
		break;
	}
}

int buffer;	//定义全局变量，以下函数都能使用它	默认为0

void makenum() {
	cout << "Running make number..." << endl;
	buffer = rand();	//把产生的随机数放入缓冲区
}
void cal() {
	cout << "Running calculate..." << endl;
	buffer = buffer % 100;
}
void output() {
	cout << "Running output..." << endl;
	cout << buffer << endl;
}
//函数定义
int abs(int a) {
	cout << "int abs" << endl;	//显示运行了哪个函数
	return (a >= 0 ? a : -a);	//如果a大于等于零则返回a，否则返回-a。
}
float abs(float a) {
	cout << "float abs" << endl;
	return (a >= 0 ? a : -a);
}
double abs(double a) {
	cout << "double abs" << endl;
	return (a >= 0 ? a : -a);
}

Rectangle::Rectangle() {
	width = 5;
	height = 5;
}

void Rectangle::set_values(int x, int y) {
	width = x;
	height = y;
}

void testHeader() {
	circle c = { 2 };
	square s = { 1 };
	rectangle r = { 2, 3 };
	triangle t = { 3, 4, 5, 36.86989, 53.13011, 90 };
	cout << "Perimeter of circle " << perimeter_of_circle(c.r) << endl;
	cout << "Area of square " << area_of_square(s.a) << endl;
	cout << "Perimeter of rectangle " << perimeter_of_rectangle(r.a, r.b) << endl;
	cout << "Area of triangle " << area_of_triangle(t.b, t.c, t.alpha) << endl;
}
