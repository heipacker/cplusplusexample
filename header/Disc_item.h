/*
 * Disc_item.h
 *
 *  Created on: 2014-5-5
 *      Author: Administrator
 */

#ifndef DISC_ITEM_H_
#define DISC_ITEM_H_
#include <string>
#include "Item_base.h"

class Disc_item : public Item_base {
public :
	Disc_item(const std::string &book = "", double sales_price = 0.0, std::size_t qty = 0, double disc_rate = 0.0, bool dgb = false):
		Item_base(book, sales_price, dbg), quantity(qty), discount(disc_rate){

	}

	std::pair<std::size_t, double> discount_policy() const {
		return std::make_pair(quantity, discount);
	}

	virtual void debug(std::ostream &os = std::cout) const {
		if(!dbg){
			return;
		}
		Item_base::debug(os);
		os << "\t" << quantity << "\t" << discount;
	}

	double net_price(std::size_t) const = 0;

protected :
	std::size_t quantity;//可打折的最小购买量
	double discount;//折扣率
};



#endif /* DISC_ITEM_H_ */
