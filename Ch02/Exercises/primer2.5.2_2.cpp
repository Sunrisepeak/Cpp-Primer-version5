﻿#include<iostream>
using namespace std;
int main()
{
	const int i = 1;
	const int *p1 = &i;		//这里p是指向整型常量的指针:*p是不可变的,但P本身是可变的>>>这是底层const
	*p1 = 2;			//错误
	int k = 2;
	p1 = &k;			//正确
	
/*-----------------------------分割线1----------------------------------*/

	int j = 1;
	int *const p2 = &j;		//这里p2是指向整型的常量指针:*p是可变的,但p本身不可变>>>>>>这是顶层const
	*p2 = 4;			//正确
	p2 = &i;			//错误

/*-----------------------------分割线2------------------------------- --*/

	const int *const p3 = &i;//这里p3是指向整型常量的常量指针:*p和p本身都不可变>>>p3即使顶层const也是底层const
	int *r = p2;		//正确,p2的顶层const可以忽略
	int *r1 = p1;		//错误,p1有底层const属性

/*-----------------------------分割线3------------------------------- --*/
	auto *r2 = p2;		//r2会被认为是int*型
	auto *r3 = p1;		//r3--------是const int
	auto *r4 = p3;		//r4--------是const int(顶层const被忽略了)
	
/*-----------------------------分割线4------------------------------- --*/	
			
	//情况1，i(不可变)是有顶层的const,会被auto忽略,f会被认为是int.加左边的const后f变成顶层const
	const auto f = i;
	auto *const r5 = p3;		//情况2，保存指针的顶层const
	return 0;
}