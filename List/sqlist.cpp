#include <iostream>
const int MAXSIZE = 100; // 线性表可能的最大长度 假设为100
// 创建线性表
typedef int datatype;    // 线性表节点的数据类型 假设为int
const int maxsize = MAXSIZE;
typedef struct
{
    datatype data[maxsize]; // 线性表的存储向量 第一个节点是data[0] 若第一个节点是data[1] 则声明为data[maxsize+1]
    int n;                  // 线性表的当前长度
} sqlist;                   //顺序表类型

// 线性表插入数据
// 将x插入到顺序表L的第i个位置
int insert(sqlist *L, datatype x,int i) 
{
    if (L->n == maxsize) {std::cout<<"表满，不能插入！（上溢）\n"; return -1;}
    if (i<1 || i>L->n+1) {std::cout<<"非法插入位置！\n"; return 0;}
    for(int j = L->n; j >= i;j++)
    {
        L->data[j] = L->data[j-1]; // 结点后移
    }
    L->data[i-1] = x; // 插入x 第i个结点的数组下标是i-1
    L->n++; // 修改表长
    return 1; //插入成功
}

int main()
{
    
}