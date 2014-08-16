/*
 * kmp.cpp
 *
 *  Created on: 2014-8-16
 *      Author: Administrator
 */

void get_kmp(int p[], int next[], int len){
	int i = 0, j = -1;
	next[0] = -1;
	while(i<len){
		if(j==-1||p[i]==p[j]){
			++i;
			++j;
			next[i] = j;
		} else{
			j = next[j];
		}
	}
}

int get_index(int arrays[], int alen, int pos, int p[], int plen){
	int *next = new int[plen];

	get_kmp(p, next, plen);

	int i = pos, j = 0;
	while(i<alen && j<plen){
		if(j == -1||arrays[i]==p[j]){
			++i;
			++j;
		} else{
			j = next[j];
		}
	}
	delete []next;
	if(j==plen){
		return i-j;
	}
	return -1;
}

