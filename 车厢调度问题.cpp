#include<stdio.h>   
#define   MaxLen   100   
struct   snode{   
	int   data[MaxLen];   
	int   top;   
}s;//定义一个栈指针   
int   n;//定义输入序列总个数   
void   Initstack()   
{   
	s.top=-1;   
}   
void   push(int   q)//元素n进栈   
{   
	s.top++;   
	s.data[s.top]=q;   
}   
int   pop()//出栈   
{   
	int   temp;   
	temp=s.data[s.top];   
	s.top--;   
	return   temp;   
}   
int   Emptys()//判断栈空   
{   
	if(s.top==-1)   
		return   1;   
	else   
		return   0;   
}   
/*
每次调用求值阶段包含两重递归，只有全部返回，才表示本pos 处理完，可以对上一个元素求值，process 就是找出当前元素进栈后所有可能的操作，即在当前元素进栈后各种情况下，
包括不出栈，立即出栈，出栈后继续出栈情况(出栈递归)下，继续处理下一个元素(入栈递归)
*/
void   process(int   pos,int   path[],int   curp)//当前处理位置pos的元素   
{   
	int   m,i;   
	if(pos<n)//编号进栈递归 
	{   
		push(pos+1);//当前元素进栈后下一个元素继续进栈   
		process(pos+1,path,curp);   //处理下一个元素，返回表明下一个元素进栈的情况处理完了
		pop(); //下一个元素处理完后，pop 掉，准备处理直接出栈
	}   

	if(!Emptys())//递归处理出栈	
	{   
		m=pop();   
		path[curp]=m;   
		curp++;   
		process(pos,path,curp);//出栈后处理下一个素继续进栈
		push(m);   
	}   
	if(pos==n&&Emptys())//输出一种可能的方案   
	{   
		for(i=0;i<curp;i++)   
			printf("%2d",path[i]);   
		printf("\n");   
	}   
}   
int   main()   
{   
	int   path[MaxLen];   
	printf("输入要调度车厢总数:");   
	scanf("%d",&n);   
	Initstack();   
	push(1);   
	printf("所有输出序列:\n");   
	process(1,path,0); //从1 开始，递归处理所有元素  
	return 0;

}   
