/*
 * combination.cpp
 *
 *  Created on: 2014-8-17
 *      Author: Administrator
 */

#include <iostream>

using namespace std;

/**
 * 组合递归算法
 */
void combination(int a[], int n, int m,  int b[], const int M){
  for(int i=n; i>=m; i--){//注意这里的循环范围
    b[m-1] = i - 1;
    if (m > 1){
    	combination(a, i-1, m-1, b, M);
    } else {//m == 1, 输出一个组合
      for(int j=M-1; j>=0; j--){
    	  cout << a[b[j]] << " ";
      }
      cout << endl;
    }
  }
}


