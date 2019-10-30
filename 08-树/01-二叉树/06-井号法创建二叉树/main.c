#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkstack.h"

#define MY_FALSE 0
#define MY_TRUE  1

// 二叉树节点
typedef struct BINARYNODE{
    char ch;
    struct BINARYNODE *lchild;
    struct BINARYNODE *rchild;
}BinaryNode;

// 先序遍历
void Recursion(BinaryNode *node)
{
    if(node == NULL)
        return;

    printf("%c", node->ch);
    Recursion(node->lchild);
    Recursion(node->rchild);
}

// 创建二叉树
BinaryNode *CreateBinaryTree()
{
    fflush(stdin);
    char ch;
    scanf("%c", &ch);

    BinaryNode *node;

    if(ch == '#')
    {
        node = NULL;
    }
    else 
    {
        node = (BinaryNode *)malloc(sizeof(BinaryNode));
        node->ch = ch;
        node->lchild = CreateBinaryTree();
        node->rchild = CreateBinaryTree();
    }

    return node;
}

int main()
{
    // 创建树
    BinaryNode *root = CreateBinaryTree();    
    // 打印树
    Recursion(root);
    return 0;
}

