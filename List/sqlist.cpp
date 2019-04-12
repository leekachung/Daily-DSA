#include <iostream>

const int MAXSIZE = 100; // 线性表可能的最大长度 假设为100
// 创建线性表
typedef int datatype;    // 线性表节点的数据类型 假设为int
const int maxsize = MAXSIZE;
typedef struct sqlist
{
    datatype data[maxsize]; // 线性表的存储向量 第一个节点是data[0] 若第一个节点是data[1] 则声明为data[maxsize+1]
    int n;                  // 线性表的当前长度
} sqlist, *Psqlist;                   //顺序表类型

// 初始化线性表
void initList (sqlist *L)
{
    L->n = 0;
}

// 判断线性表是否为空
bool isEmptyList (sqlist *L)
{
    return (L->n == 0);
}

// 判断线性表是否已满
bool isFullList (sqlist *L)
{
    return (L->n == maxsize);
}

// 线性表插入数据
// 将x插入到顺序表L的第i个位置
int insData (sqlist *L, datatype x,int i) 
{
    if (isFullList(L)) {std::cout<<"表满，不能插入！（上溢）\n"; return -1;}
    if (i<1 || i>L->n+1) {std::cout<<"非法插入位置！\n"; return 0;}
    for(int j = L->n; j >= i;j--)
    {
        L->data[j] = L->data[j-1]; // 结点后移
    }
    L->data[i-1] = x; // 插入x 第i个结点的数组下标是i-1
    L->n++; // 修改表长
    return 1; //插入成功
}

// 线性表删除数据
// 删除第i个位置的元素
int delData (sqlist *L, int i)
{
    if (isEmptyList(L)) {std::cout<<"表空，不能删除！\n"; return -1;}
    if (i<1 || i>L->n+1) {std::cout<<"非法删除位置！\n"; return 0;}
    for(int j = i; j < L->n; j++)
    {
        L->data[j-2] = L->data[j-1]; //第j个节点的下标为j-1
    }
    L->n--; //修改表长
    return 1; // 删除成功
    
}

// 线性表定位元素
int locData (sqlist *L, datatype x)
{
    int i = 1;
    while(i <= L->n && L->data[i-1] != x) i++;
    // if (i <= L->n) return i;
    // else return 0;
    return i % (L->n + 1); //A Mod B = A-(A div B) * B
}

// 输出线性表
void ouputList (sqlist *L)
{
    if (isEmptyList(L)) return; //表空返回
    for (int i = 0; i < L->n; i++)
    {
        std::cout << locData(L, i);
    }
}

// 顺序表中负值位于前面 正值位于后面
void orderNum (sqlist *L)
{
    int x; //中间变量
    int i = 0;
    int j = L->n-1;
    while (i < j) {
        while (i < j && L->data[i] < 0) i++;
        while (i < j && L->data[j] > 0) j--;
        if (i < j) {
            x = L->data[i];
            L->data[i] = L->data[j];
            L->data[j] = x;
            i++;
            j--;
        }
    }
}

// 顺序表中删除零点结点 不改变其他结点的相对位置
void delZero (sqlist *L)
{
    int s = 0; // 累计的零元数
    for (int i = 0; i < L->n; i++)
    {
        if (L->data[i] == 0) s++;
        if (s > 0) L->data[i-s] = L->data[i]; //非零元前移
    }
    L->n = L->n-s; //修改表长
}

// 顺序表各结点逆置
void inversionNode (sqlist *L)
{
    int x; //中间变量
    for(int i = 0, j = L->n; i < j; i++, j--)
    {
        x = L->data[i];
        L->data[i] = L->data[j];
        L->data[j] = x;
    }
}

int main()
{
    // 初始化
    sqlist L;
    initList(&L);
    // 插入数据
    insData(&L, 0, 1);
    ouputList(&L);
    // 删除数据
    delData(&L, 1);
    ouputList(&L);
}