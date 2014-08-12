/*
 * shellsort.cpp
 *
 *  Created on: 2014-8-12
 *      Author: Administrator
 */

/**
 * 希尔排序
 */
void ssort(int a[], int size, int dd){
	for(int i=dd; i<=size; i+=dd){
		int c= a[i];
		int j=i-dd;
		for(; j>-1; j-=dd){
			if(a[j]>c){
				a[j+dd]=a[j];
			} else{
				a[j+dd]=c;
				break;
			}
		}
		if(j<0){
			a[j+dd]=c;
		}
	}
}

void shellsort(int a[], int size){
	int d[] = {1, 3, 5};

	for(int i=2; i>-1; --i){
		ssort(a, size, d[i]);
	}
}


