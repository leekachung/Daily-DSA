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

// 回收结点空间
void deletenode(cursor p)
{
    nodepool[p].next = p; //将p所指的结点归还到存储池
    sp = p; // 将释放的结点插入存储池的第一个结点之前
}

// 定位 按序号查找 返回结点地址
cursor getData(cursor L, int i)
{
    
}

// 静态链表插入结点
int insert(cursor L, datatype x, int i)
{
    cursor s, q;
    q = getData(L, i-1); // 找a[i]的前趋结点
    if (q == NIL) {std::cout << "插入位置非法！\n"; return 0;}
    s = newnode();
    if (s == NIL) {std::cout << "空间已满，不得插入！\n"; return -1;}
    nodepool[s].data = x;
    nodepool[s].next = nodepool[q].next;
    nodepool[q].next = s;
    return 1;
}

int main ()
{
    
}