/*
 * hsort.cpp
 *
 *  Created on: 2014-7-2
 *      Author: Administrator
 */

void swap(int &l, int &r){
	int t = l;
	l = r;
	r = t;
}
/**
 * 调整
 */
void heap_adjust(int a[], int start, int end){
	int pos = start;
	int j = pos;
	while(pos<end){
		if(2*pos<end){
			j = 2*pos;
		}
		if((2*pos+1)<end){
			//j = (a[2*pos]>a[2*pos+1])?2*pos:(2*pos+1);//大顶堆
			j = (a[2*pos]<a[2*pos+1])?2*pos:(2*pos+1);//小顶堆
		}
		//if(a[pos]<a[j]){//大顶堆
		if(a[pos]>a[j]){
			swap(a[pos], a[j]);
			pos = j;
		} else{
			break;
		}
	}
}
/**
 * 堆排序
 */
void hsort(int a[], int size){
	//建堆
	for(int i = size/2; i>0; --i){
		heap_adjust(a, i, size);
	}
	//交换 调整
	for(int i = size; i>0; --i){
		swap(a[0], a[i]);

		heap_adjust(a, 0, i);
	}
}

