#include<stdio.h>
#import<windows.h>
#include <stdlib.h>
#include <string.h>
#define   MaxLen   100
#define MAXSIZE 26

enum solution {
    OneToTwo,
    ThreeToTwo,
    OneToThree
};
//ö�����ͣ�����������

typedef struct {
    char data[MaxLen];
    int top;
}*stack,stackNode;

stack INITSTACK() {
    stack s = (stack)malloc(sizeof(stackNode));
    s->top = 0;
    return s;
}

void PUSH(stack s,int e) {
    s->data[s->top++] = e;
}

int POP(stack s) {
    char e = s->data[--s->top];
    return e;
}

int   pop(stack s)//��ջ
{
    int e=s->data[s->top]; 
    s->top--;
    return   e;
}


int GETTOP(stack s) {
    return s->data[s->top-1];
}

int ISEMPTY(stack s) {
    if (s->top==0) {
        return 1;
    }
    else {
        return 0;
    }
}

int CACULATE() {
    char str1[MAXSIZE+1];
    char str2[MAXSIZE+1];
    int record[100];
    stack s1 = INITSTACK();
    stack s2 = INITSTACK();
    stack s3 = INITSTACK();

    printf("�����복��ԭʼ����>");
    scanf("%s", str1);
    int len1 = strlen(str1);
    for (int i = len1 - 1; i >= 0; i--) {
        PUSH(s1, str1[i]);
    }
    //����ջ�����ԣ������������������ջ
    printf("��������Ҫ�ĳ�������>");
    scanf("%s", str2);
    int len2 = strlen(str2);
    for (int i = len2 - 1; i >= 0; i--) {
        PUSH(s2, str2[i]);
    }	//����ջ�����ԣ������������������ջ
    int cnt = 0;//��������ļ�����
    int flag = 1;//�Ƿ�����ƥ������Եı�־
    while (!ISEMPTY(s2)) {
        //��s2��Ϊ��ʱ��ѭ��ƥ��
        if (!ISEMPTY(s1) && GETTOP(s1) == GETTOP(s2)) {
            POP(s1);
            POP(s2);
            record[cnt++] = OneToTwo;
        }
            //����һ�����1�͹��2ֱ��ƥ��
        else if (!ISEMPTY(s3) && GETTOP(s3) == GETTOP(s2)) {
            POP(s3);
            POP(s2);
            record[cnt++] = ThreeToTwo;
        }
            //���ζ������2�͹��3ƥ�䣬�����ƥ��
        else if (ISEMPTY(s1)) {
            flag = 0;
            break;
        }
            //����������ѭ���й��1�Ѿ���ȫƥ�䣬�϶���������ѭ��
        else {
            PUSH(s3, POP(s1));
            record[cnt++] = OneToThree;
        }
        //�����ģ���ʱ����ƥ�䣬�����1ջ��������3
    }
    if (flag == 0) {
        printf("FUCK YOU BEACH����\n");
    }
    else {

        for (int i = 0; i < cnt; i++) {
            if (record[i] == OneToTwo) printf("1->2  ��ջ��ֱ�ӳ�ջ\n");
            if (record[i] == ThreeToTwo) printf("3->2  ��ջһ������\n");
            if (record[i] == OneToThree) printf("1->3  ��ջһ������\n");
        }
    }
    //������
    return 0;
}



//����ṹ��




void   push(stack s,int q)//Ԫ��n��ջ
{
    s->top++;
    s->data[s->top]=q;
}

/*
ÿ�ε�����ֵ�׶ΰ������صݹ飬ֻ��ȫ�����أ��ű�ʾ��pos �����꣬���Զ���һ��Ԫ����ֵ��process �����ҳ���ǰԪ�ؽ�ջ�����п��ܵĲ��������ڵ�ǰԪ�ؽ�ջ���������£�
��������ջ��������ջ����ջ�������ջ���(��ջ�ݹ�)�£�����������һ��Ԫ��(��ջ�ݹ�)
*/



void  process(stack s,int pos,int path[],int curp,int n)//��ǰ����λ��pos��Ԫ��
{
	
    int   m,i;
    if(pos<n)//��Ž�ջ�ݹ�
    {
        push(s,pos+1);//��ǰԪ�ؽ�ջ����һ��Ԫ�ؼ�����ջ
        process(s,pos+1,path,curp,n);   //������һ��Ԫ�أ����ر�����һ��Ԫ�ؽ�ջ�������������
        pop(s); //��һ��Ԫ�ش������pop ����׼������ֱ�ӳ�ջ
    }

    if(!ISEMPTY(s))//�ݹ鴦���ջ
    {
        m=pop(s);
        path[curp]=m;
        curp++;
        process(s,pos,path,curp,n);//��ջ������һ���ؼ�����ջ
        push(s,m);
    }
    if(pos==n&&ISEMPTY(s))//���һ�ֿ��ܵķ���
    {
        for(i=0;i<curp;i++)
            printf("%2d",path[i]);
        printf("\n");
    }
}

void COLOR()
{
    printf("***** color change *****\n");
    printf("-----------[1]����ɫ-----------\n");
    printf("-----------[2]ǳ��ɫ-----------\n");
    printf("-----------[3]������-----------\n");
    printf("-----------[4]��ɫ-----------\n");
    printf("-----------[5]���ɫ-----------\n");
    printf("-----------[6]��ɫ-----------\n");
    printf("-----------[7]����ɫ-----------\n");
    printf("-----------[8]ԭ����-----------\n");
    printf("-----------[9]ǳ��ɫ-----------\n");
    printf("-----------[0]�˳�-----------\n");
    int num;
    printf("��ѡ��������ɫ>");
    scanf("%d",&num);
    switch(num){
        case 1:system("color f3");break;
        case 2:system("color f4");break;
        case 3:system("color f5");break;
        case 4:system("color f6");break;
        case 5:system("color f7");break;
        case 6:system("color f8");break;
        case 7:system("color f9");break;
        case 8:system("color fa");break;
        case 9:system("color fb");break;
        case 0:break;
        default:printf("123");
    }


}

int ui()
{
    printf("***** welcome to use it *****\n");
    printf("-----------[1]�������-----------\n");
    printf("-----------[2]������ȹ���-----------\n");
    printf("-----------[3]�жϿ�����-----------\n");
    printf("-----------[4]��ɫ�л�-----------\n");
    printf("-----------[5]�����Ļ-----------\n");
    printf("-----------[0]�˳�-----------\n");
    int num;
    printf("��ѡ��Ĳ���>");
    scanf("%d",&num);
    switch(num)
    {
        case 1:{
			int path[MaxLen];
			int   n;//�������������ܸ���
            printf("����Ҫ���ȳ�������:");
            scanf("%d",&n);
            stackNode *s = INITSTACK();
            push(s,1);
            printf("�����������:\n");
            process(s,1,path,0,n);break;
        }
        case 2:{CACULATE();break;}
        case 4:{COLOR();break;}
        case 5:{system("cls");break;}
        case 0:{exit(0);}
    }
    return 0;
}


int main()
{
    while (1)
        ui();
    //��1 ��ʼ���ݹ鴦������Ԫ��
    return 0;

}
