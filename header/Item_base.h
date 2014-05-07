/*
 * Item_base.h
 *
 *  Created on: 2014-5-5
 *      Author: Administrator
 */

#ifndef ITEM_BASE_H_
#define ITEM_BASE_H_
#include <string>
#include <iostream>

class Item_base;

bool operator<(const Item_base& lhs, const Item_base& rhs);

class Item_base{
	friend bool operator<(const Item_base& lhs, const Item_base& rhs);
public:
	Item_base(const std::string &book="", double sales_price = 0.0, bool dbg = false):isbn(book), price(sales_price), dbg(dbg){

	}

	/*bool operator<(const Item_base &rhs){

		return false;
	}*/

	std::string book() const{
		return isbn;
	}

	virtual Item_base* clone() const {
		return new Item_base(*this);
	}

	virtual double net_price(size_t n) const{
		return n*price;
	}

	virtual ~Item_base(){

	}

	virtual void debug(std::ostream &os = std::cout) const {
		if(!dbg){
			return;
		}

		os << isbn << "\t" << price;
	}

	void set_debug(bool dbg){
		this->dbg = dbg;
	}

private:
	std::string isbn;
protected:
	double price;
	bool dbg;
};

#endif /* ITEM_BASE_H_ */
