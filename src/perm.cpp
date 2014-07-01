/*
 * perm.cpp
 *
 *  Created on: 2014-6-30
 *      Author: Administrator
 */

#include <stdio.h>

void swap(char &l, char &r){
	char t = l;
	l = r;
	r = t;
}

void perm(char *pstr, int s, int e){
	if(s==e){
		printf("%s\n", pstr);
	} else{
		for(int i=s; i<e; ++i){
			swap(pstr[s], pstr[i]);
			perm(pstr, s+1, e);
			swap(pstr[s], pstr[i]);
		}
	}
}

