/*
 * test_cplus_cplus.cpp
 *
 *  Created on: 2014-5-5
 *      Author: Administrator
 */
#include <set>
#include <iostream>
#include <fstream>

#include "../header/Item_base.h"
#include "../header/Disc_item.h"
#include "../header/Bulk_item.h"
#include "../header/Lds_item.h"
#include "../header/Basket.h"
#include "../header/TextQuery.h"
using namespace std;

int test_text_query(int argc, char *argv[]);

void test_cplus_cplus(int argc, char *argv[]){
	std::multiset<Item_base> basket;

	Item_base base;
	Bulk_item bulk;
	basket.insert(base);
	basket.insert(bulk);

	std::cout << basket.size() << std::endl;

	//////////////////////////////////////////////////////////////
	Basket basket1;
	Sales_item item1(Bulk_item("7-115-14554-7", 99, 20, 0.2));
	Sales_item item2(Item_base("7-115-14554-8", 39));
	Sales_item item3(Lds_item("7-115-14554-9", 50, 200, 0.2));
	Sales_item item4(Bulk_item("7-115-14554-7", 99, 20, 0.2));

	basket1.add_item(item1);
	basket1.add_item(item2);
	basket1.add_item(item3);
	basket1.add_item(item4);

	std::cout << basket1.total() << std::endl;
}

int test_text_query(int argc, char *argv[]){
	std::ifstream infile;

	if(argc<2 || !open_file(infile, argv[1])){
		std::cerr << "No input file!" << std::endl;
	}
	TextQuery tq;
	tq.read_file(infile);
	while(true){
		cout << "enter word to look for, or q to quit:";
		string s;
		cin >> s;
		if(!cin || s=="q") break;
		set<TextQuery::line_no> locs = tq.run_query(s);
		print_results(locs, s, tq);
	}
	return 0;
}

