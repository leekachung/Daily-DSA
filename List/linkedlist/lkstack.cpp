#include <iostream>

// 链栈类型定义
typedef struct node *pointer; // 结点指针类型
typedef char datatype;
struct node // 链栈结点类型
{
    datatype data;
    pointer next;
};
typedef struct
{
    pointer top;
} lkstack;

// 初始化链栈
void initLkstack (lkstack *ls)
{
    ls->top = NULL;
}

// 判断链栈为空
int emptyLkstack (lkstack *ls)
{
    if (ls->top == NULL) return 1;
    else return 0;
}

// 链栈进栈
void pushLkstack (lkstack *ls, datatype x)
{
    pointer p;
    p = new node;
    p->data = x;
    p->next = ls->top;
    ls->top = p;
}

// 链栈退栈
int popLkstack (lkstack *ls, datatype *x)
{
    pointer p;
    if (ls->top == NULL) {std::cout << "栈空，不能退栈\n"; return 0;}
    p = ls->top;
    *x = p->data;
    ls->top = p->next;
    delete p;
    return 1;
}

// 链栈取栈顶
int getTopLkstack (lkstack *ls, datatype *x)
{
    if (ls->top == NULL) {std::cout << "栈空，无栈顶可取\n"; return 0;}
    *x = ls->top->data;
    return 1;
}

// 终端接收字符并进行编辑
// # 删除前一个字符 @ 删除前面所有字符 $ 结束字符
void editString (lkstack *ls)
{
    char ch, x;
    while (std::cin >> ch, ch != '$') {
        switch (ch)
        {
            case '#':
                popLkstack(ls, &x);
                break;
            case '@':
                while(!emptyLkstack(ls)){
                    popLkstack(ls, &x);
                }
                break;
            default:
                pushLkstack(ls, ch);
        }
    }
}

int main ()
{
    
}