/*
 * kmp.h
 *
 *  Created on: 2014-8-16
 *      Author: Administrator
 */

#ifndef KMP_H_
#define KMP_H_

void get_kmp(int p[], int next[], int len);

int get_index(int arrays[], int alen, int pos, int p[], int plen);

#endif /* KMP_H_ */
