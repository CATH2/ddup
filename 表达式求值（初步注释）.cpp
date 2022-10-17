#include<malloc.h>
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef int boll;
#define true 1
#define false 0
typedef int elemtype;
char ch[7] = {'+','-','*','/','(',')','#'};  //�ѷ���ת����һ���ַ�����
int f1[7] = {3,3,5,5,1,6,0};  //ջ��Ԫ�����ȼ�
int f2[7] = {2,2,4,4,6,1,0};  //ջ��Ԫ�����ȼ�
int n = 0;
typedef struct sqstack
{//˳��ջ�ṹ
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

//1.�Ѳ�����ת������Ӧ������
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
//2.���趨�Ƚ������ַ������ȼ�
char Compare(char c1, char c2)
{
	int i1 = cton (c1);
	int i2 = cton (c2);
	if (f1[i1] > f2[i2])  return '>';
	else if (f1[i1] < f2[i2])  return '<';
	else  return '=';
}
//3.�����������㣬�����ؼ�����
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
//4.��Ҫ�ı����㺯�������ر��ʽ�ļ�������
int EvaluateExpression()
{
	char c;
	int i = 0, sum = 0;
	int k = 1, j = 1;        //���ÿ��ر���
	elemtype x, t, a, b;
	sqstack OPTR,OPND;
	Initstack(&OPTR);        //��ʼ��������ջ
	Push(&OPTR,cton('#'));   //#��ѹ�������ջ
	Initstack(&OPND);        //��ʼ��������ջ
	c = getchar();
	while (c!='#'||ch[Gettop(OPTR)]!='#')
	{
		if (isdigit(c))
		{
			sum = 0;
			while (isdigit(c)) //�ж�c�Ƿ�Ϊ����
			{
				if (!j)        //j�����������ִ���ת���жϣ�jΪ0ת��  
				{
					sum = sum * 10 - (c - '0');
				}
				else sum = sum * 10 + (c- '0'); //�ַ�cת�����˶�Ӧ����
				c = getchar();
			}     //��ǰc��Ϊ���֣����֮ǰ�����ִ�ת����ʮ����������ѹջ
			Push(&OPND,sum);
			j = 1;
		}
		else if (k)
		{
			switch (Compare(ch[Gettop(OPTR)], c))
			{
			case'<':Push(&OPTR,cton(c));   //���ַ����λ���Ȼ���������ջ
					c = getchar();
					break;
			case'=':Pop(&OPTR, &x);       //������ջ��Ԫ�س�ջ
					c = getchar();
					break;
			case'>':Pop(&OPTR,&t);        //������ջջ��Ԫ�س�ջ
					Pop(&OPND,&b);        //������ջջ��Ԫ�س�ջ
					Pop(&OPND,&a);        //������ջջ��Ԫ�س�ջ
					Push(&OPND,Operate(a,t,b));
					break;
			}
		}
	}//endwhile
	return(Gettop(OPND));
}
//5.ȡջ��Ԫ��
elemtype Gettop(sqstack s)
{
	if (s.top == 0)
	{
		printf("ERROR,Gettop\n"); return 0;
	}
	else
		return s.stack[s.top];
}
//6.��ʼ��ջ
void Initstack(sqstack *s)
{
	s->top = 0;
}
//7.��ջ
void Pop(sqstack  *s, elemtype *x)
{
	if (s->top == 0) printf("ERROR,Pop!\n");
	else
	{
		*x = s->stack[s->top];
		s->top--;
	}
}
//8.��ջ
void Push(sqstack* s, elemtype x)
{
	if (s->top == MAXSIZE - 1) printf("ERROR,Push!\n");
	else
	{
		s->top++;
		s->stack[s->top] = x;
	}
}
//9.��sΪ��ջ���򷵻�TURE�����򷵻�FALSE
boll StackEmpty(sqstack s)
{
	if (s.top == 0)
		return true;
	else
		return false;
}
//10.���������趨������ɫ��С�����ü���ģ�麯��
int main()
{
	int result;
	system("color f4");
	system("mode con:cols=80 lines=35");  //��Ļ��ɫ�趨
	printf("**********��ӭʹ�ñ��ʽ��ֵС����***********\n\n");
	printf("�����������������ʽ����#��������");
	result=EvaluateExpression();
	printf("���ʽ�ļ������ǣ�%d \n",result);
	printf("****************��лʹ�ñ�����***************\n\n");
	return 0;
}
