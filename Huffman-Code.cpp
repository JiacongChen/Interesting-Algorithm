#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>

using namespace std;

#define MAXBIT 100
#define MAXVALUE 10000
#define MAXLEAF 30
#define MAXNODE MAXLEAF*2-1

typedef struct
{
    double weight;
    int parent;
    int lchild;
    int rchild;
    char value;
} HNodeType; /* 节点结构体 */

typedef struct 
{
    int bit[MAXBIT];
    int start;
} HCodeType; /* 编码结构体 */

HNodeType HuffNode[MAXNODE]; /* 定义一个节点结构体数组 */
HCodeType HuffCode[MAXLEAF]; /* 定义一个编码结构体数组 */

/* 构造哈夫曼树 */
void HuffmanTree (HNodeType HuffNode[MAXNODE], int n)
{
    int i, j, x1, x2;
    double m1, m2;
    /**/
    for( i=0 ; i<2*n-1 ; i++ )
    {
        HuffNode[i].weight = 0;
        HuffNode[i].parent = -1;
        HuffNode[i].lchild = -1;
        HuffNode[i].rchild = -1;
    }
    /**/
    for( i=0 ; i<n ; i++ )
    {
        cout << "请输入节点" << i+1 << "的值和权重： " << endl;
        cin >> HuffNode[i].value >> HuffNode[i].weight;
    }
    /**/
    for( i=0 ; i<n-1 ; i++ )
    {
        m1 = m2 = MAXVALUE;
        x1 = x2 = 0;
        for( j=0 ; j<n+i ; j++ )
        {
            if(HuffNode[j].weight < m1 && HuffNode[j].parent == -1)
            {
                m2 = m1;
                x2 = x1;
                m1 = HuffNode[j].weight;
                x1 = j;
            }
            else if(HuffNode[j].weight < m2 && HuffNode[j].parent == -1)
            {
                m2 = HuffNode[j].weight;
                x2 = j;
            }
        }
        /**/
        HuffNode[x1].parent = n+i;
        HuffNode[x2].parent = n+i;
        HuffNode[n+i].weight = m1+m2;
        HuffNode[n+i].lchild = x1;
        HuffNode[n+i].rchild = x2;
        /**/
        cout << "第" << i+1 << "轮的x1与x2的权重：\t" << HuffNode[x1].weight << "\t" << HuffNode[x2].weight << endl;
    }
}

/* 哈夫曼树编码 */
void HuffmanCode(HCodeType HuffCode[MAXLEAF], int n)
{
    HCodeType cd;
    int i, j, c, p;
    for( i=0 ; i<n ; i++ )
    {
        cd.start = n-1;
        c = i;
        p = HuffNode[c].parent;
        while(p != -1)
        {
            if(HuffNode[p].lchild == c)
            {
                cd.bit[cd.start] = 0;
            }
            else
            {
                cd.bit[cd.start] = 1;
            }
            cd.start--;
            c = p;
            p = HuffNode[c].parent;
        }
        for ( j=cd.start+1 ; j<n ; j++)
        {
            HuffCode[i].bit[j] = cd.bit[j];
        }
        HuffCode[i].start == cd.start;
    }
}

int main()
{
    int i, j, n;
    cout << "请输入节点个数n： " << endl;
    cin >> n;
    HuffmanTree(HuffNode, n);
    HuffmanCode(HuffCode, n);
    for( i=0 ; i<n ; i++ )
    {
        cout << HuffNode[i].value << "的哈夫曼编码是： ";
        for( j=HuffCode[i].start+1 ; j<n ; j++ )
        {
            cout << HuffCode[i].bit[j];
        }
        cout << endl;
    }
    return 0;
}



