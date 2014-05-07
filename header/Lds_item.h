/*
 * Lds_item.h
 *
 *  Created on: 2014-5-6
 *      Author: Administrator
 */

#ifndef LDS_ITEM_H_
#define LDS_ITEM_H_

#include "Disc_item.h"

class Lds_item : public Disc_item{
public :
	Lds_item(const std::string &book = "", double sales_price = 0.0, std::size_t qty = 0, double disc_rate = 0.0, bool dbg = false):
		Disc_item(book, sales_price, qty, disc_rate, dbg){

	}

	double net_price(std::size_t cnt) const{
		if(cnt>=quantity){
			return cnt * (1 - discount) * price;
		} else{
			return cnt * price - quantity * discount * price;
		}
	}

	virtual Lds_item* clone() const {
		return new Lds_item(*this);
	}
};



#endif /* LDS_ITEM_H_ */
