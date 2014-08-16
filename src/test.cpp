/*
 * test.cpp
 *
 *  Created on: 2014-4-13
 *      Author: Administrator
 */
#include <stdio.h>
#include <stdlib.h>#include <time.h>#include <stdarg.h>
#include <iomanip>
#include <typeinfo>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <algorithm>
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
#define SCAN(N,String) scanf("%"#N"s",String);  //N�ǽ�ȡ�ĸ���  String�Ǵ洢���ַ�#define BL1 bb##ll##1
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

enum {BITSPERWORD, SHIFT=5, MASK=0x1F};

void set1(int *x, int i){
	x[i>>SHIFT] |= (1 << (i & MASK));
}

void clr(int *x, int i){
	x[i>>SHIFT] &= ~(1 << (1 & MASK));
}

int test(int *x, int i){
	return x[i>>SHIFT] & (1 << (i & MASK));
}

void test_kmp(){
	int arrays[] = {1,2,4,1,2,1,2,4,2,8};
	int p[] = {2,1,2,4};
	int alen = 8, plen = 4;
	int *next = new int[plen];

	get_kmp(p, next, plen);

	for(int i=0; i<plen; ++i){
		cout << next[i] << "\t";
	}
	cout << endl;

	delete []next;

	cout << "index:" << get_index(arrays, alen, 0, p, plen);
}

void test_traveserBTree(){
	BTree *root = BTree::createBTreePreOrder();
	if(root){
		cout << "前序遍历(递归):" << endl;
		root->preOrderTraverseTreeRecursive();
		cout << endl;

		cout << "中序遍历(递归):" << endl;
		root->inOrderTraverseTreeRecursive();
		cout << endl;

		cout << "后序遍历(递归):" << endl;
		root->postOrderTraveseTreeRecursive();

		cout << endl;
		cout << "前序遍历(非递归):" << endl;
		root->preOrderTraverseTree();
		cout << endl;

		cout << "中序遍历(非递归):" << endl;
		root->inOrderTraverseTree();
		cout << endl;

		cout << "后序遍历(非递归):" << endl;
		root->postOrderTraveseTreeRecursive();
	}
}

void test_vector_bit(){
	int *x = new int[1000];
	for(int i=0; i<1000*32; ++i){
		clr(x, i);
	}
	set1(x, 1000*32-1);
	if(test(x, 1000*32-1)){
		cout << 1000*32-1;
	} else{
		cout << "not in x";
	}

	delete []x;
}

struct node{
	int val;
	node *left, *right;

	node(int val){
		this->val = val;
		left = NULL;
		right = NULL;
	}
};

node *rinsert(node *p, int target){
	if(!p){
		p = new node(target);
	}
	if(p->val>target){
		p->left = rinsert(p->left, target);
	} else if(p->val<target){
		p->right = rinsert(p->right, target);
	}
	return p;
}

void traverse(node *p){
	if(!p){
		return;
	}
	traverse(p->left);
	cout << p->val << '\t';
	traverse(p->right);
}

void test_bst_search(){
	int a[] = {12,1,5,6,9,7};
	node *root = NULL;
	for(int i=0; i<6; ++i){
		root = rinsert(root, a[i]);
	}
	traverse(root);
}

void test_algorithm(){
	int search_value;
	vector<int> vec;
	for(int i=0; i<100; ++i){
		vec.push_back(i);
	}

	vector<int>::const_iterator result = find(vec.begin(), vec.end(), search_value);
	cout << "The value " << search_value
		 << (result==vec.end()?" is not present":" is present")
		 << endl;

	int ia[6] = {27, 210, 12, 47, 109, 83};
	search_value = 83;
	int *result1 = find(ia, ia+6, search_value);
	cout << "The value " << search_value
			 << (result1==ia+6?" is not present":" is present")
			 << endl;
}

void genknuth(int m, int n){
	srand((unsigned) time(NULL)); /*随机种子*/
	for(int i=0; i<n; ++i){
		if(rand()%(n-i)<m){
			cout << i << endl;
			--m;
		}
	}
}

void test_genknuth(){
	int a , *pa=&a;
	cout<<pa;
	genknuth(3, 10);
}

class A{
public:
	A(){

	}

	A(int a):m_a(a){

	}

private:
	int m_a;
};

void test_default_construct(){
	A *arrays = new A[1]/*(1)*/;

	cout << "test" << sizeof(arrays) << endl;
}

void test_pair_type(){
	pair<int, int> p = make_pair(1, 10);

	cout << "first:" << p.first << "\tsecond:" << p.second << endl;

	pair<string, string> author("唯我中华", "heipacker");

	cout << "author:\t" << "first:" << author.first << "\tsecond:" << author.second << endl;

	pair<wstring, wstring> author1(wstring(L"heipacker"), wstring(L"唯我中华"));
	wcout << author1.second;
	wcout << L"author1:\t" << L"first:" << author1.first << L"\tsecond:" << author1.second << endl;
}

void test_map(){
	map<int, int> testmap;
	for(int i = 0; i<9; ++i){
		testmap.insert(make_pair(i, i));
	}

	for(map<int, int>::iterator m_it = testmap.begin(); m_it!=testmap.end(); ++m_it){
		cout << "first:" << m_it->first << "\tsecond:" << m_it->second << endl;

	}
}

void test_map_return(){
	//测试insert返回值
	map<string, int> word_count;
	string word;
	while(cin>>word){
		pair<map<string, int>::iterator ,bool> ret = word_count.insert(map<string, int>::value_type(word, 1));
		if(!ret.second){
			++ret.first->second;
		}
	}

	for(map<string, int>::const_iterator it = word_count.begin(); it!=word_count.end(); ++it){
		cout << it->first << "=" << it->second << endl;
	}
	//测试find返回值
	int occurs = 0;
	map<string, int>::iterator it = word_count.find("word");
	if(it!=word_count.end()){
		occurs = it->second;
	}
	cout << "occurs:" << occurs << endl;

}

void test_multimap(){
	multimap<string, string> author;
	author.insert(make_pair("heipacker", "sfasefrwe"));
	author.insert(make_pair("heipacker", "sfoawejrwr"));

	multimap<string, string>::iterator beg = author.lower_bound("heipacker");
	multimap<string, string>::iterator end = author.upper_bound("heipacker");
	while(beg!=end){
		cout << beg->second << endl;
		++beg;
	}
}

void restricted_wc(ifstream &remove_file, map<string, int> &word_count){
	set<string> excluded; //set to hold words we will ignore
	string remove_word;
	while(remove_file >> remove_word){
		string word;
		while(cin >> word){
			if(!excluded.count(word)){
				++word_count[word];
			}
		}
	}
}

void test_set(){
	ifstream ifile("testset.txt", ios::in);
	map<string, int> word_count;
	restricted_wc(ifile, word_count);

	for(map<string, int>::const_iterator it = word_count.begin(); it!=word_count.end(); ++it){
		cout << it->first << "=" << it->second << endl;
	}
}

void test_vector_iterator(){
	vector<int> vec;
	for(int i=0; i<10; ++i){
		vec.push_back(i);
	}

	vector<int>::const_iterator it = vec.begin();

	while(it!=vec.end()){
		cout << *it++;
	}
	//�����������Ͽ� ϣ�������кõ�δ�� ������
	vector<int>::const_reverse_iterator rit = vec.rbegin();
	while(rit!=vec.rend()){
		cout << *rit++;
	}
}

int maxsum1(int vec[], int b, int e){
	if(b==e){
		return vec[b]<0?0:vec[b];
	}
	int m = (b + e)/2;
	int lmax = 0, rmax = 0, sum = 0;
	for(int i = m; i>b; --i){
		sum += vec[i];
		lmax = (lmax<sum)?sum:lmax;
	}
	sum = 0;
	for(int i = m+1; i<=e; ++i){
		sum += vec[i];
		rmax = (rmax<sum)?sum:rmax;
	}

	int max = rmax + lmax;
	rmax = maxsum1(vec, b, m);
	max = (max<rmax)?rmax:max;
	lmax = maxsum1(vec, m+1, e);

	return (max<lmax)?lmax:max;
}

int test_maxsum1(){
	int vec[] = {31, -41, 59, 26, -53, 58, 97, -93, -23, 84};
	return maxsum1(vec, 0, 9);
}

void test_max_cont_vector(){
	int vec[] = {31, -41, 59, 26, -53, 58, 97, -93, -23, 84};
	int size = 10;
	int maxsofar = 0;
	//O(N^2)
	for(int i = 0; i<size; ++i){
		int sum = 0;
		for(int j = i; j<size; ++j){
			sum += vec[j];
			maxsofar = (maxsofar<sum)?sum:maxsofar;
		}
	}
	cout << "the maxsofar:" << maxsofar << endl;

	//O(NlogN)
	cout << "the maxsofar:" << test_maxsum1() << endl;

	//O(N)
	int maxendinghere = 0;
	for(int i = 0; i<size; ++i){
		maxendinghere = ((maxendinghere + vec[i])<0)?0:(maxendinghere + vec[i]);
		maxsofar = (maxsofar<maxendinghere)?maxendinghere:maxsofar;
	}
	cout << "the maxsofar:" << maxsofar << endl;
}

void test_readdouble_fromfile(){
	vector<double> vec;
	ifstream infile("double.txt", ios::in);
	string line;

	while(getline(infile, line)){
		vec.push_back(atof(line.c_str()));
	}
	double darray[vec.size()];
	vector<double>::iterator it = vec.begin();
	while(it!=vec.end()){
		darray[it - vec.begin()] = *it++;
	}

	for(vector<double>::size_type i = 0; i<vec.size(); ++i){
		cout << setprecision(2) << setiosflags(ios::fixed) << darray[i] << endl;
	}
}

/**
 * ��ȡ��ǰ�ļ�׷�ӵ���ǰ�ļ���
 */
void test_readappendfile(){
	ifstream infile("test.txt", ifstream::in|ifstream::binary);
	ofstream outfile("test.txt", ifstream::app|ifstream::binary);
	infile.seekg(0, ifstream::end);

	ifstream::streampos end = infile.tellg();
	infile.seekg(0, ifstream::beg);

	char b[512] = {0};
	int c = 0;
	for(int i = 0; i<end; i+=c){
		infile.read(b, sizeof(b)/sizeof(char));
		c = strlen(b);
		outfile.write(b, c/sizeof(char));
	}
	infile.close();
	outfile.close();
	infile.clear();

	infile.open("test.txt", ifstream::in);
	//��ȡ�ļ�����
	char r = 0;
	while(true){
		infile >> r;
		if (infile.eof())
			break;
		cout << r;
	}
	infile.close();
}

void test_fstream(){
	string ifile = string("test_in.txt");
	ifstream infile(ifile.c_str());

	if(!infile){
		cerr << "error: unable to open input file: "
				<< infile << endl;
		return ;
	}

	string ofile = string("test_out.txt");
	ofstream outfile(ofile.c_str());


	//use open fun
	infile.close();//�ȹر�
	infile.open(ifile.c_str());

	outfile.close();
	outfile.open(ofile.c_str());

	//��ȡ�ļ�����Ϣ Ȼ�����
	vector<string> files;
	for(int i =0; i<3; ++i){
		files.push_back("file" + i);
	}
	vector<string>::iterator it = files.begin();
	while(it!=files.end()){
		ifstream input(it->c_str());
		if(!input){
			input.close();
			break;
		}
		string str;
		while(input >> str){
			cout << str;
		}
		input.close();
		++it;
	}

	ofstream outfile1(ofile.c_str(), ofstream::out|ofstream::trunc);
	ofstream appfile(ofile.c_str(), ofstream::app);

	fstream inoutfile("", fstream::in|fstream::out);

}

void test_sstream(){
	string line, word;
	while(getline(cin, line)){
		istringstream stream(line);
		while(stream >> word){
			cout << word;
		}
	}

	//
	int val1 = 512, val2 = 1024;
	ostringstream format_message;
	format_message << "val1" << val1 << "\n" << "val2" << val2 << "\n";

	istringstream input_string(format_message.str());
	string dump;
	input_string >> dump >> val1 >> dump >> val2;

	cout << val1 << "	" << val2 << endl;

}

void test_stream(){
	int ival;
	while(cin>>ival, !cin.eof()){
		if(cin.bad()){
			throw runtime_error("IO stream corrupted.");
		}
		if(cin.fail()){
			cerr<<"bad data, try again";
			cin.clear(istream::failbit);
			continue;
		}
	}

	//ʹ��flush
	cout << "first" << flush << "second" << flush;

	cout << "first" << unitbuf << "second" << nounitbuf;
}

void test_folat(){
	float s = 0.12f;
	cout << s << endl;
	cout << s * 100.0f << endl;
	int v = int(s * 100.0f);
	cout << v << endl;
}

void test_sizeof(){
	//Day mon = Monday;
	int a = 10;
	int *p = &a;
	printf("%d\n", *p);
	unsigned int app = 0;
	//app = sizeof (int) * p; ������ִ��sizeof(int) Ȼ��ִ�г˷�����		���벻ͨ�� ��Ϊapp = sizeof (int) * (int)p
	//app = sizeof (int) * p;

	printf("sizeof (int) * p result:%d\n", app);
}

int intcomp(int *x, int *y){
	return *x - *y;
}

void lookup(int &a){
	printf("%s\n", "int &a");
}

void lookup(const int &a){
	printf("%s\n", "int &a");
}

void lookup(int a){
	printf("%s\n", "int a");
}

void test_lookup(){
	const int a = 10;
	const int &b = a;
	//lookup(a);//��ֵ
	//lookup(b);
}

string init = string();
int i = int(0);

void test_lsort(){
	int a[100000];
	int n = 0;
	while(scanf("%d", &a[n])!=EOF)++n;
	//�������ʵ��
	qsort(a, n, sizeof(int), (int (*)(const void*, const void*))intcomp);
	for(int i = 0; i<n; ++i){
		printf("%d\t", a[i]);
	}
}

void test_merge_sort(){
	int a[] = {4,1,5,1,2,6,3,8,12,10};

	merge_sort(a, 0, 8);

	for(int i=0; i<9; ++i){
		cout << a[i] << '\t';
	}
}

void test_hsort(){
	int a[] = {1, 3, 2, 6, 4, 7, 4, 5, 3};
	hsort(a, 8);
	for(int i = 8; i>=0; --i){
		printf("%d\t", a[i]);
	}
}

void test_bisort(){
	int a[] = {1, 3, 2, 6, 4, 7, 4, 5, 3};
	bisort(a, 8);
	for(int i = 0; i<=8; ++i){
		printf("%d\t", a[i]);
	}
}

void test_shellsort(){
	int a[] = {1, 3, 2, 6, 4, 7, 4, 5, 3};
	shellsort(a, 8);
	for(int i = 0; i<=8; ++i){
		printf("%d\t", a[i]);
	}
}

void test_isort(){
	int a[] = {1, 3, 2, 6, 4, 7, 4, 5, 3};
	isort(a, 8);
	for(int i = 0; i<=8; ++i){
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

int *p = new int[10];//δ��ʼ��

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
	t: printf("tttttttttttt\n"); //Ҳ�ǻ�ִ�е�
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
//�����Ž�ָ��������
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
	printf("��ǰ�кţ�%d\n", __LINE__);
	printf("��ǰԴ�ļ���%s\n", __FILE__);
	printf("�������ڣ�%s\n", __DATE__);
	printf("����ʱ�䣺%s\n", __TIME__);
	printf("�Ƿ���STD��׼��%d\n", __STDC__);
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
	//int **aa;//����int** ָ�������int*
	int (*b)[2]; //����int (*)[2] ָ�������int a[2]
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
	char b = 65; //1�ֽ�
	cout << "char b sizeof:" << sizeof(b) << "�ֽ�" << endl;
	signed char l = 11; //1�ֽ� Ĭ��
	cout << "signed char l sizeof:" << sizeof(l) << "�ֽ�" << endl;
	unsigned char j = 9; //1�ֽ�
	cout << "unsigned char j sizeof:" << sizeof(j) << "�ֽ�" << endl;

	int a = 1; //4�ֽ�
	cout << "int a sizeof:" << sizeof(a) << "�ֽ�" << endl;
	unsigned int f = 5; //4�ֽ� �޷����
	cout << "unsigned int f sizeof:" << sizeof(f) << "�ֽ�" << endl;
	long int e = 4; //4�ֽ�Ĭ��
	cout << "long int e sizeof:" << sizeof(e) << "�ֽ�" << endl;
	unsigned long int m = 12; //4�ֽ� �޷���� Ĭ��
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
	unsigned int f = 5; //4�ֽ� �޷����
	cout << "unsigned int f type:" << typeid(f).name() << endl;
	long int e = 4; //4�ֽ�Ĭ��
	cout << "long int e type:" << typeid(e).name() << endl;
	unsigned long int m = 12; //4�ֽ� �޷���� Ĭ��
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
	//�����
	cout << "7/-2=" << aa / ab << endl;
	cout << "-7/2=" << ac / ad << endl;
	//����������һ����������ͬ
	cout << "7%-2=" << aa % ab << endl;
	cout << "-7%2=" << ac % ad << endl;
	//��������Ϊ������
	//cout << 1.1%2 << endl;
	//cout << 1%2.1 << endl;

	int aab, aac;
	aab = aac = 1;
	cout << aab << '\t' << aac << endl;
}

void testGlobalVar() {
	srand(time(NULL));	//���ڲ������������
	for (int i = 0; i < 4; i++) {
		makenum();	//�����������뻺����
		cal();	//�Ի����������д���
		output();	//������������ֵ
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
	cout << "������������";
	cin >> a >> b;
	if (a > b) {	//���a��b����������
		int temp;	//����һ����ʱ����
		temp = a;
		a = b;
		b = temp;
	}
	cout << a << " " << b << endl;	//���������С�������
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
	cout << "a=" << abs(a) << endl << "b=" << abs(b) << endl;	//�������صĽ��
	cout << "c=" << abs(c) << endl << "d=" << abs(d) << endl;
	cout << "e=" << abs(e) << endl << "f=" << abs(f) << endl;
}

void testPointer() {
	int i = 3;
	int *iptr = &i;
	int **iptrptr = &iptr;	//iptrҲ�Ǳ�����Ҳ�ܹ���ȡ��ĵ�ַ
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
	student s1, s2;	//�״�ʹ��student���������������֮ǰ��
	cout << "����ѧ�ţ�";
	cin >> s1.idNumber;	//��Ա��ݿ��Ա�д��
	cout << "��������";
	cin >> s1.name;
	cout << "�������䣺";
	cin >> s1.age;
	cout << "����Ժϵ��";
	cin >> s1.department;
	cout << "����ɼ���";
	cin >> s1.gpa;
	cout << "ѧ��s1��Ϣ��" << endl << "ѧ�ţ�" << s1.idNumber << "����" << s1.name
			<< "���䣺" << s1.age << endl << "Ժϵ��" << s1.department << "�ɼ���"
			<< s1.gpa << endl;	//��Ա���Ҳ�ܹ�������
	s2 = s1;	//��s1�ĸ������Ա���ֵ�ֱ��Ƶ�s2��
	cout << "ѧ��s2��Ϣ��" << endl << "ѧ�ţ�" << s2.idNumber << "����" << s2.name
			<< "���䣺" << s2.age << endl << "Ժϵ��" << s2.department << "�ɼ���"
			<< s2.gpa << endl;
	//��ʼ��
	student s3 = { 428004, "Tomato", 20, "ComputerScience", 84.5 };
	student *s4 = &s3;
	cout << "ѧ��s4��Ϣ��" << endl << "ѧ�ţ�" << s4->idNumber << "����" << s4->name
			<< "���䣺" << s4->age << endl << "Ժϵ��" << s4->department << "�ɼ���"
			<< s4->gpa << endl;	//��Ա���Ҳ�ܹ�������
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

int buffer;	//����ȫ�ֱ��������º�����ʹ����	Ĭ��Ϊ0

void makenum() {
	cout << "Running make number..." << endl;
	buffer = rand();	//�Ѳ�����������뻺����
}
void cal() {
	cout << "Running calculate..." << endl;
	buffer = buffer % 100;
}
void output() {
	cout << "Running output..." << endl;
	cout << buffer << endl;
}
//������
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
	cout << "Perimeter of rectangle " << perimeter_of_rectangle(r.a, r.b)
			<< endl;
	cout << "Area of triangle " << area_of_triangle(t.b, t.c, t.alpha) << endl;
}

void generate(int m, int n){
	for(int i = 0; i < n; i++){
		if(rand()%(n-i) < m) { //����t/(n-i)�ĸ���ִ����������
			printf("%d\n",i);
			m--;
		}
	}
}
