/*
 * Sales_item.h
 *
 *  Created on: 2014-5-6
 *      Author: Administrator
 */

#ifndef SALES_ITEM_H_
#define SALES_ITEM_H_
#include "Item_base.h"
#include <stdexcept>

class Sales_item {
public :
	Sales_item():p(0), use(new std::size_t(1)){

	}

	Sales_item(const Item_base&);

	Sales_item(const Sales_item &rhs):p(rhs.p), use(rhs.use){
		++*use;
	}

	~Sales_item(){
		decr_use();
	}

	Sales_item& operator=(const Sales_item&);

	const Item_base *operator->() const {
		if(p){
			return p;
		} else{
			throw std::logic_error("unbound Sales_item.");
		}
	}

	const Item_base& operator*() const {
		if(p){
			return *p;
		} else{
			throw std::logic_error("unbound Sales_item.");
		}
	}
private :
	Item_base *p;
	std::size_t *use;
	void decr_use(){
		if(--*use==0){
			delete p;
			delete use;
		}
	}
};

inline bool compare(const Sales_item &lhs, const Sales_item &rhs){
	return lhs->book() < rhs->book();
}

#endif /* SALES_ITEM_H_ */
