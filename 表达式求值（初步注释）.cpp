#include<malloc.h>
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef int boll;
#define true 1
#define false 0
typedef int elemtype;
char ch[7] = {'+','-','*','/','(',')','#'};  //把符号转换成一个字符数组
int f1[7] = {3,3,5,5,1,6,0};  //栈内元素优先级
int f2[7] = {2,2,4,4,6,1,0};  //栈外元素优先级
int n = 0;
typedef struct sqstack
{//顺序栈结构
	elemtype stack[MAXSIZE];
	int top;
}sqstack;

elemtype cton(char c);
char Compare(char c1, char c2);
int Operate(elemtype a, elemtype t, elemtype b);
int EvaluateExpression();
elemtype Gettop(sqstack s);
void Initstack(sqstack* s);
void Pop(sqstack* s, elemtype* x);
void Push(sqstack* s, elemtype x);
boll StackEmpty(sqstack s);

//1.把操作符转换成相应的数字
elemtype cton(char c)
{
	switch (c)
	{
		case '+': return 0;
		case '-': return 1;
		case '*': return 2;
		case '/': return 3;
		case '(': return 4;
		case ')': return 5;
		default: return 6;
	}
}
//2.按设定比较两个字符的优先级
char Compare(char c1, char c2)
{
	int i1 = cton (c1);
	int i2 = cton (c2);
	if (f1[i1] > f2[i2])  return '>';
	else if (f1[i1] < f2[i2])  return '<';
	else  return '=';
}
//3.进行四则运算，并返回计算结果
int Operate(elemtype a, elemtype t, elemtype b)
{
	int sum;
	switch (t)
	{
		case 0: sum = a + b; break;
		case 1: sum = a - b; break;
		case 2: sum = a * b; break;
		default: sum = a / b;
	}
	return sum;
}
//4.主要的表达计算函数，返回表达式的计算结果。
int EvaluateExpression()
{
	char c;
	int i = 0, sum = 0;
	int k = 1, j = 1;        //设置开关变量
	elemtype x, t, a, b;
	sqstack OPTR,OPND;
	Initstack(&OPTR);        //初始化操作符栈
	Push(&OPTR,cton('#'));   //#号压入操作符栈
	Initstack(&OPND);        //初始化操作数栈
	c = getchar();
	while (c!='#'||ch[Gettop(OPTR)]!='#')
	{
		if (isdigit(c))
		{
			sum = 0;
			while (isdigit(c)) //判断c是否为数字
			{
				if (!j)        //j用来进行数字串的转换判断，j为0转换  
				{
					sum = sum * 10 - (c - '0');
				}
				else sum = sum * 10 + (c- '0'); //字符c转换成了对应数字
				c = getchar();
			}     //当前c不为数字，则把之前的数字串转化成十进制数字再压栈
			Push(&OPND,sum);
			j = 1;
		}
		else if (k)
		{
			switch (Compare(ch[Gettop(OPTR)], c))
			{
			case'<':Push(&OPTR,cton(c));   //把字符整形化，然后入操作符栈
					c = getchar();
					break;
			case'=':Pop(&OPTR, &x);       //操作符栈顶元素出栈
					c = getchar();
					break;
			case'>':Pop(&OPTR,&t);        //操作数栈栈顶元素出栈
					Pop(&OPND,&b);        //操作数栈栈顶元素出栈
					Pop(&OPND,&a);        //操作数栈栈顶元素出栈
					Push(&OPND,Operate(a,t,b));
					break;
			}
		}
	}//endwhile
	return(Gettop(OPND));
}
//5.取栈顶元素
elemtype Gettop(sqstack s)
{
	if (s.top == 0)
	{
		printf("ERROR,Gettop\n"); return 0;
	}
	else
		return s.stack[s.top];
}
//6.初始化栈
void Initstack(sqstack *s)
{
	s->top = 0;
}
//7.出栈
void Pop(sqstack  *s, elemtype *x)
{
	if (s->top == 0) printf("ERROR,Pop!\n");
	else
	{
		*x = s->stack[s->top];
		s->top--;
	}
}
//8.入栈
void Push(sqstack* s, elemtype x)
{
	if (s->top == MAXSIZE - 1) printf("ERROR,Push!\n");
	else
	{
		s->top++;
		s->stack[s->top] = x;
	}
}
//9.若s为空栈，则返回TURE，否则返回FALSE
boll StackEmpty(sqstack s)
{
	if (s.top == 0)
		return true;
	else
		return false;
}
//10.主函数，设定界面颜色大小，调用计算模块函数
int main()
{
	int result;
	system("color f4");
	system("mode con:cols=80 lines=35");  //屏幕颜色设定
	printf("**********欢迎使用表达式求值小程序***********\n\n");
	printf("请输入您的算术表达式（以#结束）：");
	result=EvaluateExpression();
	printf("表达式的计算结果是：%d \n",result);
	printf("****************感谢使用本程序***************\n\n");
	return 0;
}
