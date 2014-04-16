/*
 * test.cpp
 *
 *  Created on: 2014-4-13
 *      Author: Administrator
 */
#include "stdio.h"
#include "stdlib.h"//���ڲ��������
#include "time.h"//���ڲ��������
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
#define SCAN(N,String) scanf("%"#N"s",String);  //N�ǽ�ȡ�ĸ���  String�Ǵ洢���ַ���

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
	printf("��ǰ�кţ�%d\n", __LINE__);
	printf("��ǰԴ�ļ���%s\n", __FILE__);
	printf("�������ڣ�%s\n", __DATE__);
	printf("����ʱ�䣺%s\n", __TIME__);
	printf("�Ƿ����STD��׼��%d\n", __STDC__);
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
	//int **aa;//����int** ָ�������int*
	int (*b)[2];//����int (*)[2] ָ�������int a[2]
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
	char b = 65; //1�ֽ�
	cout << "char b sizeof:" << sizeof(b) << "�ֽ�" << endl;
	signed char l = 11; //1�ֽ� Ĭ��
	cout << "signed char l sizeof:" << sizeof(l) << "�ֽ�" << endl;
	unsigned char j = 9; //1�ֽ�
	cout << "unsigned char j sizeof:" << sizeof(j) << "�ֽ�" << endl;

	int a = 1; //4�ֽ�
	cout << "int a sizeof:" << sizeof(a) << "�ֽ�" << endl;
	unsigned int f = 5; //4�ֽ� �޷�����
	cout << "unsigned int f sizeof:" << sizeof(f) << "�ֽ�" << endl;
	long int e = 4; //4�ֽ�Ĭ��
	cout << "long int e sizeof:" << sizeof(e) << "�ֽ�" << endl;
	unsigned long int m = 12; //4�ֽ� �޷����� Ĭ��
	cout << "unsigned long int m sizeof:" << sizeof(m) << "�ֽ�" << endl;
	short int d = 3; //2�ֽ�
	cout << "short int d sizeof:" << sizeof(d) << "�ֽ�" << endl;
	unsigned short int g = 6; //2�ֽ�
	cout << "unsigned short int g sizeof:" << sizeof(g) << "�ֽ�" << endl;

	float h = 7; //4�ֽ�
	cout << "float h sizeof:" << sizeof(h) << "�ֽ�" << endl;
	double i = 8; //8�ֽ�
	cout << "double i sizeof:" << sizeof(i) << "�ֽ�" << endl;
	long double c = 11;
	cout << "long double c sizeof:" << sizeof(c) << "�ֽ�" << endl;

	bool k = 10; //1�ֽ�
	cout << "bool k sizeof:" << sizeof(k) << "�ֽ�" << endl;
	cout
			<< "--------------------------------------------printTypeSize---------------------------------"
			<< endl;

	//���
//	cout << a << '\t' << b << '\t' << c << '\t' << d << '\t' << e << '\t' << f << '\t' << g << '\t' << h << '\t' << i << '\t' << j << '\t' << k << '\t' << l << '\t' << m << '\t';
}

void printType() {
	cout
			<< "--------------------------------------------printType---------------------------------"
			<< endl;
	char b = 65; //1�ֽ�
	cout << "char b type:" << typeid(b).name() << endl;
	signed char l = 11; //1�ֽ� Ĭ��
	cout << "signed char l type:" << typeid(l).name() << endl;
	unsigned char j = 9; //1�ֽ�
	cout << "unsigned char j type:" << typeid(j).name() << endl;

	int a = 1; //4�ֽ�
	cout << "int a type:" << typeid(a).name() << endl;
	unsigned int f = 5; //4�ֽ� �޷�����
	cout << "unsigned int f type:" << typeid(f).name() << endl;
	long int e = 4; //4�ֽ�Ĭ��
	cout << "long int e type:" << typeid(e).name() << endl;
	unsigned long int m = 12; //4�ֽ� �޷����� Ĭ��
	cout << "unsigned long int m type:" << typeid(m).name() << endl;
	short int d = 3; //2�ֽ�
	cout << "short int d type:" << typeid(d).name() << endl;
	unsigned short int g = 6; //2�ֽ�
	cout << "unsigned short int g type:" << typeid(g).name() << endl;

	float h = 7; //4�ֽ�
	cout << "float h type:" << typeid(h).name() << endl;
	double i = 8; //8�ֽ�
	cout << "double i type:" << typeid(i).name() << endl;
	long double c = 11;
	cout << "long double c type:" << typeid(c).name() << endl;

	bool k = 10; //1�ֽ�
	cout << "bool k type:" << typeid(k).name() << endl;
	cout
			<< "--------------------------------------------printType---------------------------------"
			<< endl;
}

void testDefaultValue() {
	int c;
	cout << c << endl; //δֵ֪
	cin >> c;
	cout << c << endl;

	double a;
	cout << a << endl; //δֵ֪
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
	//L/l��ʾ˫���ȵĳ���
	//F/f��ʾ�����ȵĳ���

	const float fa = 1.12L;
	//fa = 12;
	cout << fa << endl;
	const double da = 1.121;
	cout << da << endl;

	int aa = 7;
	int ab = -2;
	int ac = -7;
	int ad = 2;
	//�����������
	cout << "7/-2=" << aa / ab << endl;
	cout << "-7/2=" << ac / ad << endl;
	//��������������һ����������ͬ
	cout << "7%-2=" << aa % ab << endl;
	cout << "-7%2=" << ac % ad << endl;
	//����������Ϊ������
	//cout << 1.1%2 << endl;
	//cout << 1%2.1 << endl;

	int aab, aac;
	aab = aac = 1;
	cout << aab << '\t' << aac << endl;
}

void testGlobalVar() {
	srand(time(NULL));	//���ڲ�����������������
	for (int i = 0; i < 4; i++) {
		makenum();	//������������뻺����
		cal();	//�Ի������������д���
		output();	//�������������ֵ
	}
}

void localVarIncrement() {
	static int currentNum;	//δ��ʼ��  �������Զ���ʼ��Ϊ0
	cout << ++currentNum << endl;
}

void testStaticLocalVar() {
	for (int i = 0; i < 4; ++i) {
		localVarIncrement();
	}
}

void testCondition() {
	int a, b;
	cout << "��������������";
	cin >> a >> b;
	if (a > b) {	//���a��b��������������
		int temp;	//����һ����ʱ����
		temp = a;
		a = b;
		b = temp;
	}
	cout << a << " " << b << endl;	//����������С�������
}

void testSwitch() {
	float a, b;
	char oper;
	cout << "������һ�����ʽ��eg.1+2����" << endl;
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
			cout << "��������" << endl;
		break;
	}
	default:
		cout << "��������" << endl;
	}
	//����
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
	cout << "a=" << abs(a) << endl << "b=" << abs(b) << endl;	//����������صĽ��
	cout << "c=" << abs(c) << endl << "d=" << abs(d) << endl;
	cout << "e=" << abs(e) << endl << "f=" << abs(f) << endl;
}

void testPointer() {
	int i = 3;
	int *iptr = &i;
	int **iptrptr = &iptr;	//iptrҲ�Ǳ�����Ҳ�ܹ���ȡ���ĵ�ַ
	cout << "Address of Var i=" << iptr << endl;	//���iptr�洢�����ݣ���i���ڴ��еĵ�ַ
	cout << "Data of Var i=" << *iptr << endl;	//���iptr��ָ��ı���
	cout << "Address of Pointer iptr=" << iptrptr << endl;	//���iptr���ڴ��еĵ�ַ
	cout << "Address of Var i=" << *iptrptr << endl;	//���iptrptr��ָ��ı�������iptr
	*iptr = 2 + *iptr;	//*iptr��������ֵ
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
	student s1, s2;	//�״�ʹ��student�������������������֮ǰ��
	cout << "����ѧ�ţ�";
	cin >> s1.idNumber;	//��Ա���ݿ��Ա�д��
	cout << "����������";
	cin >> s1.name;
	cout << "�������䣺";
	cin >> s1.age;
	cout << "����Ժϵ��";
	cin >> s1.department;
	cout << "����ɼ���";
	cin >> s1.gpa;
	cout << "ѧ��s1��Ϣ��" << endl << "ѧ�ţ�" << s1.idNumber << "������" << s1.name
			<< "���䣺" << s1.age << endl << "Ժϵ��" << s1.department << "�ɼ���"
			<< s1.gpa << endl;	//��Ա����Ҳ�ܹ�������
	s2 = s1;	//��s1�ĸ�������Ա����ֵ�ֱ��Ƶ�s2��
	cout << "ѧ��s2��Ϣ��" << endl << "ѧ�ţ�" << s2.idNumber << "������" << s2.name
			<< "���䣺" << s2.age << endl << "Ժϵ��" << s2.department << "�ɼ���"
			<< s2.gpa << endl;
	//��ʼ��
	student s3 = { 428004, "Tomato", 20, "ComputerScience", 84.5 };
	student *s4 = &s3;
	cout << "ѧ��s4��Ϣ��" << endl << "ѧ�ţ�" << s4->idNumber << "������" << s4->name
			<< "���䣺" << s4->age << endl << "Ժϵ��" << s4->department << "�ɼ���"
			<< s4->gpa << endl;	//��Ա����Ҳ�ܹ�������
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

int buffer;	//����ȫ�ֱ��������º�������ʹ����	Ĭ��Ϊ0

void makenum() {
	cout << "Running make number..." << endl;
	buffer = rand();	//�Ѳ�������������뻺����
}
void cal() {
	cout << "Running calculate..." << endl;
	buffer = buffer % 100;
}
void output() {
	cout << "Running output..." << endl;
	cout << buffer << endl;
}
//��������
int abs(int a) {
	cout << "int abs" << endl;	//��ʾ�������ĸ�����
	return (a >= 0 ? a : -a);	//���a���ڵ������򷵻�a�����򷵻�-a��
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
