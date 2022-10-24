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
//枚举类型，代表解决方法

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

int   pop(stack s)//出栈
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

    printf("请输入车厢原始序列>");
    scanf("%s", str1);
    int len1 = strlen(str1);
    for (int i = len1 - 1; i >= 0; i--) {
        PUSH(s1, str1[i]);
    }
    //根据栈的特性，将读入的序列逆序入栈
    printf("请输入想要的车厢序列>");
    scanf("%s", str2);
    int len2 = strlen(str2);
    for (int i = len2 - 1; i >= 0; i--) {
        PUSH(s2, str2[i]);
    }	//根据栈的特性，将读入的序列逆序入栈
    int cnt = 0;//解决方案的计数器
    int flag = 1;//是否满足匹配合理性的标志
    while (!ISEMPTY(s2)) {
        //当s2不为空时，循环匹配
        if (!ISEMPTY(s1) && GETTOP(s1) == GETTOP(s2)) {
            POP(s1);
            POP(s2);
            record[cnt++] = OneToTwo;
        }
            //情形一：轨道1和轨道2直接匹配
        else if (!ISEMPTY(s3) && GETTOP(s3) == GETTOP(s2)) {
            POP(s3);
            POP(s2);
            record[cnt++] = ThreeToTwo;
        }
            //情形二：轨道2和轨道3匹配，即简介匹配
        else if (ISEMPTY(s1)) {
            flag = 0;
            break;
        }
            //情形三：在循环中轨道1已经完全匹配，肯定出错，跳出循环
        else {
            PUSH(s3, POP(s1));
            record[cnt++] = OneToThree;
        }
        //情形四：暂时不能匹配，将轨道1栈顶存入轨道3
    }
    if (flag == 0) {
        printf("FUCK YOU BEACH！！\n");
    }
    else {

        for (int i = 0; i < cnt; i++) {
            if (record[i] == OneToTwo) printf("1->2  入栈后直接出栈\n");
            if (record[i] == ThreeToTwo) printf("3->2  出栈一个车厢\n");
            if (record[i] == OneToThree) printf("1->3  入栈一个车厢\n");
        }
    }
    //输出结果
    return 0;
}



//定义结构体




void   push(stack s,int q)//元素n进栈
{
    s->top++;
    s->data[s->top]=q;
}

/*
每次调用求值阶段包含两重递归，只有全部返回，才表示本pos 处理完，可以对上一个元素求值，process 就是找出当前元素进栈后所有可能的操作，即在当前元素进栈后各种情况下，
包括不出栈，立即出栈，出栈后继续出栈情况(出栈递归)下，继续处理下一个元素(入栈递归)
*/



void  process(stack s,int pos,int path[],int curp,int n)//当前处理位置pos的元素
{
	
    int   m,i;
    if(pos<n)//编号进栈递归
    {
        push(s,pos+1);//当前元素进栈后下一个元素继续进栈
        process(s,pos+1,path,curp,n);   //处理下一个元素，返回表明下一个元素进栈的情况处理完了
        pop(s); //下一个元素处理完后，pop 掉，准备处理直接出栈
    }

    if(!ISEMPTY(s))//递归处理出栈
    {
        m=pop(s);
        path[curp]=m;
        curp++;
        process(s,pos,path,curp,n);//出栈后处理下一个素继续进栈
        push(s,m);
    }
    if(pos==n&&ISEMPTY(s))//输出一种可能的方案
    {
        for(i=0;i<curp;i++)
            printf("%2d",path[i]);
        printf("\n");
    }
}

void COLOR()
{
    printf("***** color change *****\n");
    printf("-----------[1]湖蓝色-----------\n");
    printf("-----------[2]浅红色-----------\n");
    printf("-----------[3]基佬紫-----------\n");
    printf("-----------[4]黄色-----------\n");
    printf("-----------[5]乳白色-----------\n");
    printf("-----------[6]灰色-----------\n");
    printf("-----------[7]深蓝色-----------\n");
    printf("-----------[8]原谅绿-----------\n");
    printf("-----------[9]浅蓝色-----------\n");
    printf("-----------[0]退出-----------\n");
    int num;
    printf("请选择字体颜色>");
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
    printf("-----------[1]输出序列-----------\n");
    printf("-----------[2]车厢调度过程-----------\n");
    printf("-----------[3]判断可行性-----------\n");
    printf("-----------[4]颜色切换-----------\n");
    printf("-----------[5]清空屏幕-----------\n");
    printf("-----------[0]退出-----------\n");
    int num;
    printf("你选择的操作>");
    scanf("%d",&num);
    switch(num)
    {
        case 1:{
			int path[MaxLen];
			int   n;//定义输入序列总个数
            printf("输入要调度车厢总数:");
            scanf("%d",&n);
            stackNode *s = INITSTACK();
            push(s,1);
            printf("所有输出序列:\n");
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
    //从1 开始，递归处理所有元素
    return 0;

}
