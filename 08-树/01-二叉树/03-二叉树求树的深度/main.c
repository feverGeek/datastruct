#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 二叉树节点
typedef struct BINARYNODE{
    char ch;
    struct BINARYNODE *lchild;
    struct BINARYNODE *rchild;
}BinaryNode;

// 递归遍历
void Recursion(BinaryNode *node)
{
    if(node == NULL)
        return;

    // 先访问根
    printf("%c", node->ch);
    // 再遍历左子树
    Recursion(node->lchild);
    // 再遍历右子树
    Recursion(node->rchild);
}

// 中序遍历
void MidOrderRecursion(BinaryNode *node)
{
    if(node == NULL)
        return;

    // 先访问左子树
    MidOrderRecursion(node->lchild);
    // 再访问根
    printf("%c", node->ch);
    // 再访问右子树
    MidOrderRecursion(node->rchild);
}

// 后序遍历
void BackOrderRecursion(BinaryNode *node)
{
    if(node == NULL)
        return;

    // 先访问左子树
    BackOrderRecursion(node->lchild);
    // 再访问右子树
    BackOrderRecursion(node->rchild);
    // 再访问根
    printf("%c", node->ch);
}

int CalcLeafNum(BinaryNode *node, int *num)
{
    if(node == NULL)
        return -1;

    if(node->lchild == NULL && node->rchild == NULL)
        (*num)++;
    
    // 左子树叶子节点数
    CalcLeafNum(node->lchild, num);
    // 右子树叶子节点数
    CalcLeafNum(node->rchild, num);
}

// 求二叉树的深度
int CalcTreeDepth(BinaryNode *node)
{
    if(node == NULL)
        return -1;

    int depth = 0;
    // 求左子树的高度
    int leftDepth = CalcTreeDepth(node->lchild);
    // 求右子树的高度
    int rightDepth = CalcTreeDepth(node->lchild);
    depth = leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;

    return depth;
}

void CreateBinaryTree()
{
    // 创建节点
    BinaryNode node1 = {'A', NULL, NULL};
    BinaryNode node2 = {'B', NULL, NULL};
    BinaryNode node3 = {'C', NULL, NULL};
    BinaryNode node4 = {'D', NULL, NULL};
    BinaryNode node5 = {'E', NULL, NULL};
    BinaryNode node6 = {'F', NULL, NULL};
    BinaryNode node7 = {'G', NULL, NULL};
    BinaryNode node8 = {'H', NULL, NULL};

    // 建立节点关系
    node1.lchild = &node2;
    node1.rchild = &node6;
    node2.rchild = &node3;
    node3.lchild = &node4;
    node3.rchild = &node5;
    node6.rchild = &node7;
    node7.lchild = &node8;

    // 先序遍历
    Recursion(&node1);
    printf("\n");

    // 中序遍历
    MidOrderRecursion(&node1);
    printf("\n");

    // 后序遍历
    BackOrderRecursion(&node1);
    printf("\n");

    int leafnum = 0;
    CalcLeafNum(&node1, &leafnum);
    printf("leaf num: %d", leafnum);
    printf("\n");

    int depth = 0;
    depth = CalcTreeDepth(&node1);
    printf("depth: %d" , depth);
}



int main()
{
    CreateBinaryTree();    
    return 0;
}

