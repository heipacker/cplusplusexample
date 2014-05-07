/*
 * Bulk_item.h
 *
 *  Created on: 2014-5-5
 *      Author: Administrator
 */

#ifndef BULK_ITEM_H_
#define BULK_ITEM_H_
#include <string>
#include "Disc_item.h"

class Bulk_item : public Disc_item {
public :
	Bulk_item(const std::string& book="", double sales_price=0.0, std::size_t qty=0, double disc_rate=0.0):
		Disc_item(book, sales_price, qty, disc_rate) {

	}

	virtual Bulk_item* clone() const {
		return new Bulk_item(*this);
	}

	double net_price(std::size_t cnt) const{
		if(cnt>=quantity){
			return cnt * (1 - discount) * price;
		} else{
			return cnt * price;
		}
	}

};

#endif /* BULK_ITEM_H_ */
