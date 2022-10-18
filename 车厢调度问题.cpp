#include<stdio.h>   
#define   MaxLen   100   
struct   snode{   
	int   data[MaxLen];   
	int   top;   
}s;//����һ��ջָ��   
int   n;//�������������ܸ���   
void   Initstack()   
{   
	s.top=-1;   
}   
void   push(int   q)//Ԫ��n��ջ   
{   
	s.top++;   
	s.data[s.top]=q;   
}   
int   pop()//��ջ   
{   
	int   temp;   
	temp=s.data[s.top];   
	s.top--;   
	return   temp;   
}   
int   Emptys()//�ж�ջ��   
{   
	if(s.top==-1)   
		return   1;   
	else   
		return   0;   
}   
/*
ÿ�ε�����ֵ�׶ΰ������صݹ飬ֻ��ȫ�����أ��ű�ʾ��pos �����꣬���Զ���һ��Ԫ����ֵ��process �����ҳ���ǰԪ�ؽ�ջ�����п��ܵĲ��������ڵ�ǰԪ�ؽ�ջ���������£�
��������ջ��������ջ����ջ�������ջ���(��ջ�ݹ�)�£�����������һ��Ԫ��(��ջ�ݹ�)
*/
void   process(int   pos,int   path[],int   curp)//��ǰ����λ��pos��Ԫ��   
{   
	int   m,i;   
	if(pos<n)//��Ž�ջ�ݹ� 
	{   
		push(pos+1);//��ǰԪ�ؽ�ջ����һ��Ԫ�ؼ�����ջ   
		process(pos+1,path,curp);   //������һ��Ԫ�أ����ر�����һ��Ԫ�ؽ�ջ�������������
		pop(); //��һ��Ԫ�ش������pop ����׼������ֱ�ӳ�ջ
	}   

	if(!Emptys())//�ݹ鴦���ջ	
	{   
		m=pop();   
		path[curp]=m;   
		curp++;   
		process(pos,path,curp);//��ջ������һ���ؼ�����ջ
		push(m);   
	}   
	if(pos==n&&Emptys())//���һ�ֿ��ܵķ���   
	{   
		for(i=0;i<curp;i++)   
			printf("%2d",path[i]);   
		printf("\n");   
	}   
}   
int   main()   
{   
	int   path[MaxLen];   
	printf("����Ҫ���ȳ�������:");   
	scanf("%d",&n);   
	Initstack();   
	push(1);   
	printf("�����������:\n");   
	process(1,path,0); //��1 ��ʼ���ݹ鴦������Ԫ��  
	return 0;

}   
