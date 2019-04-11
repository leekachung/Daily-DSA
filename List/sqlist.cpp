#include <iostream>

int main()
{
    // 创建线性表
    typedef int datatype; // 线性表节点的数据类型 假设为int
    const int maxsize = 100; // 线性表可能的最大长度 假设为100
    typedef struct {
        datatype data[maxsize]; // 线性表的存储向量 第一个节点是data[0] 若第一个节点是data[1] 则声明为data[maxsize+1]
        int n; // 线性表的当前长度
    } sqlist; //顺序表类型
    
}