#include <iostream>

// 顺序栈的类型定义
typedef int datatype;
const int maxsize = 100;
typedef struct
{
    datatype data[maxsize];
    int top; // 栈顶指针
} sqstack;

// 初始化顺序栈
void init_sqstack (sqstack *sq)
{
    sq->top = -1; // 将栈顶指针设置为-1 顺序栈有序范围为0-maxsize-1 可调整
}

// 判断顺序栈空
int emptySqstack (sqstack *sq)
{
    if (sq->top == -1) return 1;
    else return 0;
}

// 顺序栈进栈
int pushSqstack (sqstack *sq, datatype x)
{
    if (sq->top == maxsize-1) {std::cout << "栈满， 不能进栈！\n"; return 0;} // 上溢
    sq->data[++sq->top] = x;
    return 1;
}

// 顺序表出栈
int popSqstack (sqstack *sq, datatype *x) // 栈顶元素由参数返回
{
    if (sq->top == -1) {std::cout << "栈空， 不能出栈\n"; return 0;} // 下溢
    *x = sq->data[--sq->top]; // 取出栈顶元素赋值给x 栈顶指针-1
    return 1;
}

// 顺序表取栈顶
int getTopSqstack (sqstack *sq, datatype *x) // 栈顶元素由参数返回
{
    if (sq->top == -1) {std::cout << "栈空，无栈顶可取\n"; return 0;} // 栈空
    *x = sq->data[sq->top];
    return 1;
}

int main ()
{

}