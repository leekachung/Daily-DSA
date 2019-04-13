#include <iostream>

// 单链表类型定义
typedef char datatype;
typedef struct node * pointer; // 结点指针类型
struct node //结点结构
{
   datatype data;
   pointer next;
};
typedef pointer lklist; // 单链表类型 即头指针类型


// 尾插法创建单链表 顺序
// 有头结点 返回表头指针
lklist tailCreate()
{
    lklist head; // 语义化的pointer类型 更好说明head是头指针
    pointer rear, s; // 普通指针类型
    char ch;
    head = new node; // 生成头结点
    rear = head; // 尾指针初值指向头结点
    while (std::cin>>ch, ch != '$') { // 读入结点值 并检测是否为结束符
        s = new node; // 生成新结点
        s->data = ch;
        rear->next = s; // 新结点插入表尾
        rear = s; // 尾指针指向新的表尾
    }
    rear->next = NULL; // 尾结点的后继指针为空
    return head;
}

// 头插法创建单链表 逆序
// 有头结点 返回表头指针
lklist headCreate ()
{
    lklist head;
    pointer s;
    char ch;
    head = new node;
    head->next = NULL;
    while (std::cin>>ch, ch != '$') {
        s = new node;
        s->data = ch;
        s->next = head->next;
        head->next = s;
    }
    return head;
}

// 计算单链表的长度
int linkLength (lklist L)
{
    int j = 0; // 计数器
    pointer p = L->next; // 赋值首结点
    while(p != NULL){
        j++;
        p = p->next;
    }
     return j;
}

// 定位 按序号查找 返回结点地址
pointer getData (lklist L, int i)
{
    int j = 0;
    pointer p = L->next;
    if (i == 0) return L; // 返回头结点
    if (i < 0) return NULL; // 非法位置
    while(p != NULL){
        j++;
        if (j == i) break;
        p = p->next;
    }
    return p; // 未找到时 p为NULL
}

// 定位 按值查找 返回结点地址
pointer locDataToAddr (lklist L, datatype x)
{
    pointer p = L->next;
    while(p != NULL){
        if (p->data == x) break;
        p = p->next; 
    }
    return p; // 未找到时 p为NULL
}

// 定位 按值查找 返回结点序号
int locDataToNum(lklist L, datatype x)
{
    int j = 0;
    pointer p = L->next;
    while (p != NULL)
    {
        j++;
        if (p->data == x) break;
        p = p->next;
    }
    if (p != NULL) return j;
    return -1;
}

// 单链表插入数据 已知结点序号
// 前插 T(n) = O(n) 后插 T(n) = O(1) 
// 对前插 进行类后插等效处理 即先后插再交换前后结点
/*
*   @param int forb front of back 选择前插或后插 0为前 1为后
*   @param int i 插入位置
*/
int insData(lklist head, datatype x, int i, int forb)
{
    pointer p = getData(head, i-1); // 找待插入的位置的直接前趋
    if (p == NULL) { // 无第i-1个结点 即 i<1 || i>n+1
        std::cout << "非法插入位置！\n";
        return 0;
    }
    pointer s = new node;
    if (forb == 1) {
        s->data = x;
        s->next = p->next;
        p->next = s;
        return 1;
    }
    if (forb == 0) {
        s->data = p->data;
        s->next = p->next;
        p->data = x;
        p->next = s;
        return 1;
    }
    return -1; // 非法forb参数
}

// 单链表删除数据
// 删除结点直接前趋 进行删除结点直接后继等效处理
/*
*   @param int iorb i of back 选择删除本结点或删除结点直接后继 0为删除结点直接前趋 1为删除结点直接后继
*   @param int i 删除位置
*/
int delData(lklist L, int i, int iorb)
{
    pointer q = getData(L, i-1); // 找待删除的结点的直接前趋
    if (q != NULL && q->next == NULL) {
        std::cout << "非法删除位置！\n";
        return -1;
    }
    pointer p;
    if (iorb == 1)
    {
        // p 充当 q 结点的直接后继
        p = q->next;       // 保存需删除的结点地址 用于释放空间
        q->next = p->next; // 若不需要删除原结点 只调整链表结构 p->next->next即可
        delete p;          // 释放已脱离链表的结点 不释放已导致内存泄露
        return 1;
    }
    if (iorb == 0)
    {
        // p 充当 q 结点的直接前趋
        q = p->next;
        p->data = q->data;
        p->next = q->next;
        delete q;
        return 1;
    }
    return -1;   // 非法iorb参数
}

// 输出单链表
void outputList(lklist L, char *name)
{
    std::cout << name << "数据如下";
    while (L)
    {
        std::cout << L->data << "\n";
        L = L->next;
    }
}

int main ()
{
    // 尾插法
    lklist head1;
    char tail[] = "尾插法";
    std::cout << "请输出" << tail << "数据：\n";
    head1 = tailCreate();
    outputList(head1, tail);
    std::cout << "单链表长度为：" << linkLength(head1) << "\n";

    // 定位 按序号查找 返回结点地址
    // int n = 3;
    // std::cout << "第" << n << "个结点是：" << getData(head1, n) << "\n";

    // 定位 按值查找 返回结点地址
    // std::cout << "结点地址为：" << locDataToAddr(head1, '3') << "\n";

    // 定位 按值查找 返回结点序号
    // std::cout << "结点序号为：" << locDataToNum(head1, '3') << "\n";

    // 插入数据在结点前
    // insData(head1, '6', 3, 0);
    // 插入数据在结点后
    // insData(head1, '6', 3, 1);
    // outputList(head1, tail);

    // 通过修改i参数 控制删除结点的位置
    // 删除结点位置的直接前趋结点
    // delData(head1, 2, 0);
    // outputList(head1, tail);
    // 删除结点位置的结点
    // delData(head1, 2, 1);
    // outputList(head1, tail);
    // 删除结点位置的直接后继结点
    // delData(head1, 3, 1);
    // outputList(head1, tail);

    // std::cout << "-------------- \n";

    // 头插法
    // lklist head2;
    // char head[] = "头插法";
    // std::cout << "请输出" << head << "数据：\n";
    // head2 = headCreate();
    // outputList(head2, head);
    // std::cout << "单链表长度为：" << linkLength(head2) << "\n";
}