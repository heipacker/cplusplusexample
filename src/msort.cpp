/*
 * msort.cpp
 *
 *  Created on: 2014-8-12
 *      Author: Administrator
 */

/**
 * 归并排序
 */
void merge(int *a, int b, int m, int e){
	int *t = new int[e - b + 1];
	int i = 0;
	int s = b, f = m + 1;
	while(s<=m&&f<=e){
		if(a[s]<a[f]){
			t[i++] = a[s++];
		} else{
			t[i++] = a[f++];
		}
	}
	while(s<=m){
		t[i++] = a[s++];
	}
	while(f<=e){
		t[i++] = a[f++];
	}
	int end = e - b + 1;
	i=0;
	while(i<end){
		a[b++] = t[i++];
	}
	delete[] t;
}

void merge_sort(int *a, int b, int e){
	if(b>=e){
		return;
	}
	int m = (b + e)/2;
	merge_sort(a, b, m);
	merge_sort(a, m + 1, e);
	merge(a, b, m, e);
}
