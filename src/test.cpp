/*
 * test.cpp
 *
 *  Created on: 2014-4-13
 *      Author: Administrator
 */
#include "stdio.h"
#include "stdlib.h"//用于产生随机数#include "time.h"//用于产生随机数#include <stdarg.h>
#include <iomanip>
#include <typeinfo>
#include <iostream>
#include <vector>
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
#define SCAN(N,String) scanf("%"#N"s",String);  //N是截取的个数  String是存储的字符串#define BL1 bb##ll##1
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

#define print(tem, ...) fprintf(stdout, tem, ## __VA_ARGS__)

#define MAXLINE 1000

#define DOUBLE(x) x+x // x*2

void func(char (&p)[10]){
    printf("%d\n",sizeof(p));        // 10
}

void test_sizeof(){
	//Day mon = Monday;
	int a = 10;
	int *p = &a;
	printf("%d\n", *p);
	unsigned int app = 0;
	//app = sizeof (int) * p; 这里先执行sizeof(int) 然后执行乘法操作		编译不通过 改为app = sizeof (int) * (int)p
	//app = sizeof (int) * p;

	printf("sizeof (int) * p result:%d\n", app);
}

void test_hsort(){
	int a[] = {1, 3, 2, 6, 4, 7, 4, 5, 3};
	hsort(a, 8);
	for(int i = 8; i>=0; --i){
		printf("%d\t", a[i]);
	}
}

void test_qsort(){
	int a[] = {1, 3, 2, 6, 4, 7, 4, 5, 3};
	qsort(a, 8);
	for(int i = 0; i<9; ++i){
		printf("%d\t", a[i]);
	}
}

bool is_shorter(const string &v1, const string &v2){
	return v1.size()<v2.size();
}

void print_values(int *array){

}
/*
void print_values(int array[]){

}

void print_values(int array[10]){

}*/

void print_values(int (&array)[10]){
	for(int i = 0; i<10; ++i){
		printf("%d\t", array[i]);
	}
}

void print_values(int (*matrix)[10]){

}

void print_vector(vector<int>::const_iterator beg, vector<int>::iterator end){
	while(beg!=end){
		printf("%d\t", *beg++);
	}
}

void test_vector(){
	vector<int> test;
	for(int i = 0; i<10; ++i){
		test.push_back(i);
	}

	print_vector(test.begin(), test.end());
}

void test_is_shorter(){
	printf("%d\n", is_shorter(string("1111"), string("12")));
}

int *p = new int[10];//未初始化

void test_cstyle_char(){
	char ca1[] = {'C', '+', '+',};
	char ca2[] = {'C', '+', '+', '\0'};
	char ca3[] = "C++";

	const char *cp = "C++";
	char *cp1 = ca1;
	char *cp2 = ca2;

	for(int i = 0; i<10; ++i){
		printf("%d\t", p[i]);
	}
	delete []p;
	delete[] p;
	//cp[1] = '-';
	printf("%s\n", ca1);
	printf("%s\n", ca2);
	printf("%s\n", ca3);
	printf("%s\n", cp);
	printf("%s\n", cp1);
	printf("%s\n", cp2);

	printf("%d\n", 3&12);
}

void test_permaution(){
	char pstr[4] = "123";
	perm(pstr, 0, strlen(pstr));
}

void test_declare(){
	string s("hello, world.");

	string *sp = &s;

	cout<<*sp;
}

void* test_void_pointer_internal(void *p){
	int *pp = static_cast<int *>(p);
	*pp = 12;

	int i = 10;
	float f = i;

	//float ff = 2^24 + 1;
	float ff = 2 + 1;
	printf("%f\n", f);
	printf("%f\n", ff);

	return pp;
}

void test_void_pointer(){
	int *pp = new int(11);

	int *pt = static_cast<int *>(test_void_pointer_internal(pp));

	printf("%d\n", *pt);
}

void testDeclareArray(){
	int *p = new int[10];
	int *pp = new int[10]();
	for(int i=0; i<10; ++i){
		printf("%d\t", p[i]);
	}

	printf("\n");

	for(int i=0; i<10; ++i){
		printf("%d\t", pp[i]);
	}
}

void test_mcoro(){
	int i = DOUBLE(5)*5;
	cout<<i<<endl;
}

const char *c[] = {"ENTER","NEW","POINT","FIRST"};
const char **cp[] = { c + 3 , c + 2 , c + 1 , c};
const char ***cpp = cp;

void test_arrays_3p(void)
{
	printf("%s",**++cpp);
	printf("%s",*--*++cpp+3);
	printf("%s",*cpp[-2]+3);
	printf("%s\n",cpp[-1][-1]+1);
}

void test_print_metric(){
	int a[4][4] = {
			{1, 2, 3, 4},
			{5, 6, 7, 8},
			{9, 10,11,12},
			{13,14,15,16}
	};
	int c = 3;
	for(int j=c; j>=-c;--j){
		int m, n;
		if(j>0){
			m = 0;
			n = j;
		} else{
			m = -j;
			n = 0;
		}
		for(; m<=c&&n<=c; ++n,++m){
			printf("%d\t", a[m][n]);
		}
		printf("\n");
	}
}

/* filecopy: copy file ifp to file ofp */
void filecopy(FILE *ifp, FILE *ofp) {
	int c;
	while ((c = getc(ifp)) != EOF) {
		putc(c, ofp);
	}
}

int test_file_operation(int argc, const char *argv[]) {
	FILE *fp;
	void filecopy(FILE *, FILE *);

	if (argc == 1) { /* no args; copy standard input */
		filecopy(stdin, stdout);
	} else {
		while (--argc > 0) {
			if ((fp = fopen(*++argv, "r")) == NULL) {
				printf("cat: can't open %s\n", *argv);
				return 1;
			} else {
				filecopy(fp, stdout);
				fclose(fp);
			}
		}
	}
	return 0;
}

void test_file_() {
	//char *name[]={"Illegal manth", "Jan", "Feb", "Mar"};
	const char *argv[] = { "11", "22" };
	//char argv1[][5] = { { '1', '1' }, { '2', '2' } };
	printf("%d\n", test_file_operation(2, argv));
}

void minprintf(char *fmt, ...) {
	va_list ap; /* points to each unnamed arg in turn */
	char *p, *sval;
	int ival;
	double dval;
	va_start(ap, fmt); /* make ap point to 1st unnamed arg */
	for (p = fmt; *p; p++) {
		if (*p != '%') {
			putchar(*p);
			continue;
		}
		switch (*++p) {
		case 'd':
			ival = va_arg(ap, int);
			printf("%d", ival);
			break;
		case 'f':
			dval = va_arg(ap, double);
			printf("%f", dval);
			break;
		case 's':
			for (sval = va_arg(ap, char *); *sval; sval++) {
				putchar(*sval);
			}
			break;
		default:
			putchar(*p);
			break;
		}
	}
	va_end(ap); /* clean up when done */
}

void test_goto() {
	if (!2) {
		goto t;
	} else {
		goto f;
	}
	f: printf("ffffffffffff\n");
	t: printf("tttttttttttt\n"); //也是会执行的
}

void test_not_operation() {
	if (!2) {
		printf("true.");
	} else {
		printf("false.");
	}
}

void copy_str(char from[], char to[]) {
	for (int i = 0; (to[i] = from[i]) != '\0'; i++)
		;
}

int getline(char s[], int limit) {
	int c, i = 0;
	while (i < (limit - 1) && (c = getchar()) != EOF && c != '\n') {
		s[i++] = c;
	}
	if (c == '\n') {
		s[i++] = '\n';
	}
	s[i] = '\0';
	return i;
}

void test_read_line() {
	int len = 0, max = 0;
	char line[MAXLINE], longest[MAXLINE];

	while ((len = getline(line, MAXLINE)) != 0) {
		if (len > max) {
			max = len;
			copy_str(line, longest);
		}
	}
	if (max > 0) {
		printf("%s", longest);
	}
}

void test_print_eof() {
	printf("EOF is:%d\n", EOF);
}

void test_get_put_char() {
	int c;
	while ((c = getchar()) != EOF)
		putchar(c);
}

void test_pre_printf() {
	print("hello world----%d\n", 1111);
	print("hello world----\n");
}
//用括号将指针括起来
//void print_array(int (*a)[3]){
void print_array(int a[1][3]) {
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 3; ++j) {
			printf("%d\n", a[i][j]);
		}
	}
}

void test_pre_print_array() {
	int a[2][3] = { { 1, 2, 3 }, { 4, 5, 6 } };
	print_array(a);
}

void test_pre_xinhao() {
	TEST1(1, 2);
}

void test_pre_line() {
	printf("line: %d, file: %s\n", __LINE__, __FILE__);
#line 100 "test_pre_line"
	printf("line: %d, file: %s\n", __LINE__, __FILE__);
	printf("line: %d, file: %s\n", __LINE__, __FILE__);
}

void test_pre_inmacor() {
	printf("当前行号：%d\n", __LINE__);
	printf("当前源文件：%s\n", __FILE__);
	printf("编译日期：%s\n", __DATE__);
	printf("编译时间：%s\n", __TIME__);
	printf("是否符合STD标准：%d\n", __STDC__);
}

void test_pre_vaargs() {
	my_printf("111111111");
}

void test_pre_swap() {
	int x = 0, y = 1;
	swap(x, y);
	printf("%d, %d\n", x, y);
	int a = 0;
	incr(a, 1, 10);
	printf("%3d\n", a);
}

void test_pre_process() {
	int BL1 = 10;
	int BL(4) = 15;
	printf("%d\n", BL1);
	printf("%d\n", BL(4));
	printf("%d\n", Y);
	PRINTF(3)
	char dd[256] = { '1', '2', '3', '\0' };
	char db[256] = "121212";
	//SCAN(2, dd)
	printf("%s size:%d\n", dd, sizeof(dd));
	printf("%s size:%d\n", db, sizeof(db));
}

void testArrayPointer() {
	int a[2][2] = { { 1, 2 }, { 3, 4 } };
	char c[3] = { '1', '2', '\0' };
	//int **aa;//类型int** 指向的类型int*
	int (*b)[2]; //类型int (*)[2] 指向的类型int a[2]
	char (*bc)[3];
	b = a;
	bc = &c;
	/*aa = &(&a);
	 printf("aa:%d\n", **aa);*/
	printf("b:%d\n", *(*b + 1));
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
	cout << "Perimeter of rectangle " << perimeter_of_rectangle(r.a, r.b)
			<< endl;
	cout << "Area of triangle " << area_of_triangle(t.b, t.c, t.alpha) << endl;
}

void generate(int m, int n){
	for(int i = 0; i < n; i++){
		if(rand()%(n-i) < m) { //即以t/(n-i)的概率执行下面的语句
			printf("%d\n",i);
			m--;
		}
	}
}
