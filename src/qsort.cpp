/*
 * qsort.cpp
 *
 *  Created on: 2014-7-2
 *      Author: Administrator
 */

int partition(int a[], int begin, int end){
	int compare = a[begin];

	while(begin<end){
		while(begin<end&&a[end]>=compare)--end;
		a[begin] = a[end];
		while(begin<end&&a[begin]<=compare)++begin;
		a[end] = a[begin];
	}
	a[begin] = compare;

	return begin;
}

void qsort(int a[], int begin, int end){
	if(begin<end){
		int middle = partition(a, begin, end);
		qsort(a, begin, middle - 1);
		qsort(a, middle + 1, end);
	}
}
/**
 * ¿ìËÙÅÅÐò
 */
void qsort(int a[], int size){
	qsort(a, 0, size);
}


