# 栈的实现 https://blog.csdn.net/xlengji/article/details/82143396
"""
#1.定义一个栈
#2.栈初始化
#3.判栈空
#4.新元素推进栈
#5.输出栈中元素
#6.定义一个主函数，用来输出栈内信息
"""
#1.定义一个栈
class Stack(object):
    def __init__(self):
        self.stack = []
        self.result = []

#2.栈初始化
    def InitStack(self):
        return self.stack[::-1]


#3.判栈空
    def IsEmpty(self,item):
        if len(self.stack) == 0:
            return self.stack==[]

#4.新元素推进栈
    def Push(self, item):
        """加入元素"""
        return self.stack.append(item)

#5.输出栈中元素
    def Pop(self,number):
        """弹出元素"""
        #此行进行对数据的统计
        rec_number=number
        i=0
        while number:
            self.result.append(self.stack[i])#此行进行result输出
            i+=1
            number-=1
        #此行对数据进行删除，其中j的值可以不用采用递增的办法，因为在删的过程中，所有元素的序列会自动前移
        j=0
        while rec_number:
            self.stack.pop(j)
            rec_number-=1
        return self.stack


def main():
    information = Stack()
    print("****************************************************************")
    print("*                 欢迎来到商品管理系统                         *")
    print("*         下面请按照我们的提示来实现您要的服务                 *")
    print("****************************************************************")
    goods_name=input("请输入您要存放商品的名字：")
    nums=int(input("请输入您要输入的信息数量："))
    rem_num=nums
    i=0
    while nums:
        date=int(input("请输入第%d个商品录入的日期，<日期按照20190101的格式输入>："%(i+1)))
        information.Push(date)
        nums-=1
        i+=1
    print("商品录入完毕！")
    print("*"*30)
    print("现在货架上的商品日期为：")
    print(information.InitStack())
    print("*" * 30)
    fetch_num=int(input("请输入要取商品的数量："))
    while True:
        if fetch_num<=len(information.stack):
            information.Pop(fetch_num)
            break
        else:
            print("要取的商品超过了货架有的数量，请重新输入")
        fetch_num=int(input("请重新输入要取商品的数量："))

    print("******************************************")
    print("取出的商品日期有：")
    print(information.result)
    print("******************************************")
    print("取出商品后剩下%d件商品的日期为："%(rem_num-fetch_num))
    print(information.InitStack())
    print("******************************************")
    print("现在货架还能放下%d件商品"%(fetch_num))

    #这里是强制性把栈放满
    while fetch_num:
        add_inf=int(input("请输入要放入新商品的日期<日期按照20190101的格式输入>："))
        information.Push(add_inf)
        fetch_num-=1
    print("商品上货完毕！")
    print("******************************************")
    print("从货架靠里端到外端的商品的日期为:")
    print(information.InitStack())
    print("******************************************")


if __name__=="__main__":
    main()

