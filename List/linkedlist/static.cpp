#include <iostream>

// 静态链表类型定义
const int maxsize = 100; // 存储池（备用结点空间）大小
typedef int datatype; // 结点数据类型
typedef int cursor; // 游标类型
const cursor NIL = -1; // 静态链表空指针
typedef struct 
{
    datatype data; // 数据域
    cursor next; // 指针域
} snode; // 结点类型
snode nodepool[maxsize]; // 存储池
cursor sp; //游标变量

// 初始化
void initialize()
{
    for (int i = 0; i < maxsize - 1; i++) // 依次链接存储池中各结点
        nodepool[i].next = i + 1;
    nodepool[maxsize-1].next = NIL; // 最后一个指针指向 NIL
    sp = 0;
}

// 分配结点空间
cursor newnode()
{
    cursor p;
    if (sp == NIL) return NIL; // 存储池已满 分配结点失败
    p = sp; // p指向分配到的结点
    sp = nodepool[sp].next; // 从存储池中删除一个结点
    return p; //返回分配到的结点空间
}

void deletenode(cursor p)
{
    nodepool[p].next = p; //将p所指的结点归还到存储池
    sp = p; // 将释放的结点插入存储池的第一个结点之前
}

int main ()
{
    
}