// 整型溢出.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	 
 

	unsigned  a = 0;
	cout << a - 1 << endl;

	 unsigned   u = 10;
	 int b = -42;
	 cout << u+b << endl;
		
	 unsigned char c = -1;
	 cout << "signed char" << int(c)<< endl;

  
	 unsigned i = 11;

	 while (i>0){
		 --i;
		 cout << "wwwwwwwwww" << i << endl;
		
	 }
	return 0;
}

