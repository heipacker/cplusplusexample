/*
 * isort.cpp
 *
 *  Created on: 2014-8-12
 *      Author: Administrator
 */

/**
 * 插入排序 升序
 */
void isort(int a[], int size){
	if(!a||size<0){
		return;
	}
	//时间复杂度O(N^2)
	for(int i=1; i<=size; ++i){
		int c=a[i];
		int j = i-1;
		for(; j>-1; --j){
			if(a[j]>c){
				a[j+1]=a[j];
			} else{
				a[j+1]=c;
				break;
			}
		}
		if(j==-1){
			a[0] = c;
		}
	}
}

/**
 * 二分查找插入排序
 */
void bisort(int a[], int size){
	if(!a||size<0){
		return;
	}

	for(int i=1; i<=size; ++i){
		int c=a[i];
		int b=0, e=i-1, m=(b+e)/2;
		while(b<=e){
			if(a[m]>c){
				e = m-1;
			} else{
				b = m+1;
			}
			m = (b+e)/2;
		}
		for(int j=i-1; j>m; --j){
			a[j+1]=a[j];
		}
		a[m+1]=c;
	}
}



