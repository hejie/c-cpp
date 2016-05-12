###一.Linux学习--gdb调试：

命令
* backtrace（或bt）	查看各级函数调用及参数
* finish                连续运行到当前函数返回为止，然后停下来等待命令
* frame（或f）帧编号	选择栈帧
* info（或i） locals	查看当前栈帧局部变量的值
* list（或l）	        列出源代码，接着上次的位置往下列，每次列10行
* list 行号	        列出从第几行开始的源代码
* list 函数名	        列出某个函数的源代码
* next（或n）	        执行下一行语句
* print（或p）	        打印表达式的值，通过表达式可以修改变量的值或者调用函数
* quit（或q）	        退出gdb调试环境
* set var	        修改变量的值
* start	                开始执行程序，停在main函数第一行语句前面等待命令
* step（或s）	        执行下一行语句，如果有函数调用则进入到函数中

二.gdb 小例：
```c++
#include<iostream>
void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}
int main(void)
{
    int a=1,b=2;
    swap(a,b);
    std::cout << a<<" "<<b << std::endl;
    return 0;
} 
``` 


在编译时要加上-g选项，生成的可执行文件才能用gdb进行源码级调试：
```c++
$ gcc -g main.c -o main
```

-g选项的作用是在可执行文件中加入源代码的信息，并不是把源代码嵌入到可执行文件中的，在调试时也需要源文件。
如果没有-g，你将看不见程序的函数名、变量名，所代替的全是运行时的内存地址

 
现在试试用list命令从第一行开始列出源代码：
```c++
(gdb) l
1	#include<iostream>
2	
3	void swap(int &a,int &b){
4	    int temp=a;
5	    a=b;
6	    b=temp;
7	}
8	int main(void)
9	{
10	    int a=1,b=2;
(gdb) 
```
一次只列10行，如果要从第11行开始继续列源代码可以输入l或者回车
也可以什么都不输直接敲回车，gdb提供了一个很方便的功能，在提示符下直接敲回车表示重复上一条命令。

 gdb的很多常用命令有简写形式，例如list命令可以写成l，要列一个函数的源代码也可以用函数名做参数：
```c++
(gdb) l swap
1	#include<iostream>
2	
3	void swap(int &a,int &b){
4	    int temp=a;
5	    a=b;
6	    b=temp;
7	}
8	int main(void)
9	{
10	    int a=1,b=2;
(gdb)  
```
现在退出gdb的环境： 
```c++ 
(gdb) q 
```
start命令开始执行程序：
```c++
(gdb) start
Temporary breakpoint 1 at 0x40094c: file gdb.cc, line 9.
Starting program: /tmp/a.out 

Temporary breakpoint 1, main () at gdb.cc:9
9	{
```
gdb停在main函数中变量定义之后的第一条语句处等待我们发命令，gdb列出的这条语句是即将执行的下一条语句。我们可以用next命令（简写为n）控制这些语句一条一条地执行：
```c++
(gdb) n
10	    int a=1,b=2;
(gdb) （回车）
11	    swap(a,b);
(gdb) （回车）
12	    std::cout << a<<" "<<b << std::endl;
(gdb) （回车）
2 1
13	    return 0;

```
用step命令（简写为s）进swap函数中跟踪执行：
可以先用b 命令后面加上 行号或者函数名  增加断点
```c++
(gdb) b 11
Breakpoint 12 at 0x400969: file gdb.cc, line 11.
```
用 r 命令运行调试模式，自动定位到断点
```c++
(gdb) r
The program being debugged has been started already.
Start it from the beginning? (y or n) y
Starting program: /tmp/a.out 

Breakpoint 12, main () at gdb.cc:11
11	    swap(a,b);
```
用 s 命令进入语句
```c++
(gdb)  s
swap (a=@0x7fffffffdd60: 1, b=@0x7fffffffdd64: 2) at gdb.cc:4
4	    int temp=a;
```
可以查看函数调用的栈帧：
```c++
(gdb) bt
#0  swap (a=@0x7fffffffdd60: 1, b=@0x7fffffffdd64: 2) at gdb.cc:4
#1  0x000000000040097c in main () at gdb.cc:11
```
可见当前的swap函数是被main函数调用的，main传进来的参数是a b都是内存地址。main函数的栈帧编号为1(#1)，swap的栈帧编号为0(#0)。现在可以用info命令（简写为i）查看swap函数局部变量的值：
```c++
(gdb) i locals
temp = 0
```
如果想查看main函数当前局部变量的值，先用frame命令（简写为f）选择1号栈帧然后再查看局部变量：
```c++
(gdb) f 1
#1  0x000000000040097c in main () at gdb.cc:11
11	    swap(a,b);
(gdb) i locals 
a = 1
b = 2
```
注意在函数里面有可能产生局部变量没初始化，所以具有不确定的值。用s或n往下走几步，然后用print命令（简写为p）打印变量的值：
```c++
(gdb) p a
$1 = 1
$1表示gdb保存着这些中间结果，$后面的编号会自动增长，在命令中可以用$1、$2、$3等编号代替相应的值。
```
可以用finish命令让程序一直运行到从当前函数返回为止：
```c++
Run till exit from #0  swap (a=@0x7fffffffdd60: 2, b=@0x7fffffffdd64: 1) at gdb.cc:7
main () at gdb.cc:12
12	    std::cout << a<<" "<<b << std::endl;
```
由于形参是引用类型，可以看到a和b的值已经交换
  
可以修改变量值来进行调试
```c++
(gdb) set var a=0
(gdb) p a
 $10 = 0
```
可以查看断点信息
```c++
Num     Type           Disp Enb Address            What
12      breakpoint     keep y   0x0000000000400969 in main() at gdb.cc:11
	breakpoint already hit 1 time
```
可删除单个断点，也可删除一个断点的集合(Num)，这个集合用连续的断点号来描述
delete 简称(d) 
clear 删除断点是基于行的。
```c++
(gdb) d 11
(gdb) d 1-10
用法:clear 
删除所在行的多有断点。
clear location
clear 删除所选定的环境中所有的断点
clear location location描述具体的断点。
例如：
clear list_insert         //删除函数的所有断点
clear list.c:list_delet   //删除文件：函数的所有断点
clear 12                  //删除行号的所有断点
clear list.c:12           //删除文件：行号的所有断点
```


