/*
 * Basket.h
 *
 *  Created on: 2014-5-6
 *      Author: Administrator
 */

#ifndef BASKET_H_
#define BASKET_H_

#include <set>
#include "Sales_item.h"

class Basket{

	typedef bool (*Comp)(const Sales_item &lhs, const Sales_item &rhs) ;
public :
	typedef std::multiset<Sales_item, Comp> set_type;
	typedef set_type::size_type size_type;
	typedef set_type::const_iterator const_iter;

	Basket():items(compare) {

	}

	void add_item(const Sales_item& item){
		items.insert(item);
	}

	size_type size(const Sales_item &item) const {
		return items.count(item);
	}

	double total() const;
private :
	std::multiset<Sales_item, Comp> items;
};



#endif /* BASKET_H_ */
