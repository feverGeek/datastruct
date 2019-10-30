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

// 二叉树的非递归遍历
typedef struct BITREESTACKNODE{
    LinkNode node;
    BinaryNode *TreeNode;
    int flag;
}BiTreeStackNode;

// 创建栈中的节点
BiTreeStackNode *CreateBiTreeStackNode(BinaryNode *node, int flag)
{
    BiTreeStackNode *newnode = (BiTreeStackNode *)malloc(sizeof(BiTreeStackNode));
    newnode->TreeNode = node;
    newnode->flag = flag;
    return newnode;
}

// 非递归先序遍历
void NonRecursion(BinaryNode *node)
{
    // 创建栈
    LinkStack *stack = Init_LinkStack();

    BiTreeStackNode *newnode = CreateBiTreeStackNode(node, MY_FALSE);
    // 把根节点压栈
    Push_LinkStack(stack, (LinkNode *)newnode);

    while(Size_LinkStack(stack) > 0)
    {
        //先弹出栈顶元素
        BiTreeStackNode *tnode = (BiTreeStackNode *)Top_LinkStack(stack);
        Pop_LinkStack(stack);
        
        // 弹出的栈顶元素的树节点为NULL
        if(tnode->TreeNode == NULL)
        {
            continue;
        }

        if(tnode->flag == MY_TRUE)
        {
            printf("%c", tnode->TreeNode->ch);
        }
        else
        {
            // 当前节点的右节点入栈
            Push_LinkStack(stack, (LinkNode *)CreateBiTreeStackNode(tnode->TreeNode->rchild, MY_FALSE));
            // 当前节点的左节点入栈
            Push_LinkStack(stack, (LinkNode *)CreateBiTreeStackNode(tnode->TreeNode->lchild, MY_FALSE));
            // 当前节点入栈
            tnode->flag = MY_TRUE;
            Push_LinkStack(stack, (LinkNode *)tnode);

        }
    }
}

// 非递归的中序遍历
void MidOrderNonRecursion(BinaryNode *node)
{
    // 创建栈
    LinkStack *stack = Init_LinkStack();

    BiTreeStackNode *newnode = CreateBiTreeStackNode(node, MY_FALSE);
    // 把根节点压栈
    Push_LinkStack(stack, (LinkNode *)newnode);

    while(Size_LinkStack(stack) > 0)
    {
        //先弹出栈顶元素
        BiTreeStackNode *tnode = (BiTreeStackNode *)Top_LinkStack(stack);
        Pop_LinkStack(stack);
        
        // 弹出的栈顶元素的树节点为NULL
        if(tnode->TreeNode == NULL)
        {
            continue;
        }

        if(tnode->flag == MY_TRUE)
        {
            printf("%c", tnode->TreeNode->ch);
        }
        else
        {
            // 当前节点的右节点入栈
            Push_LinkStack(stack, (LinkNode *)CreateBiTreeStackNode(tnode->TreeNode->rchild, MY_FALSE));
            // 当前节点入栈
            tnode->flag = MY_TRUE;
            Push_LinkStack(stack, (LinkNode *)tnode);
            // 当前节点的左节点入栈
            Push_LinkStack(stack, (LinkNode *)CreateBiTreeStackNode(tnode->TreeNode->lchild, MY_FALSE));
        }
    }
}

// 非递归的后序遍历
void BackOrderNonRecursion(BinaryNode *node)
{
    // 创建栈
    LinkStack *stack = Init_LinkStack();

    BiTreeStackNode *newnode = CreateBiTreeStackNode(node, MY_FALSE);
    // 把根节点压栈
    Push_LinkStack(stack, (LinkNode *)newnode);

    while(Size_LinkStack(stack) > 0)
    {
        //先弹出栈顶元素
        BiTreeStackNode *tnode = (BiTreeStackNode *)Top_LinkStack(stack);
        Pop_LinkStack(stack);
        
        // 弹出的栈顶元素的树节点为NULL
        if(tnode->TreeNode == NULL)
        {
            continue;
        }

        if(tnode->flag == MY_TRUE)
        {
            printf("%c", tnode->TreeNode->ch);
        }
        else
        {
            // 当前节点入栈
            tnode->flag = MY_TRUE;
            Push_LinkStack(stack, (LinkNode *)tnode);
            // 当前节点的右节点入栈
            Push_LinkStack(stack, (LinkNode *)CreateBiTreeStackNode(tnode->TreeNode->rchild, MY_FALSE));
            // 当前节点的左节点入栈
            Push_LinkStack(stack, (LinkNode *)CreateBiTreeStackNode(tnode->TreeNode->lchild, MY_FALSE));
        }
    }
}



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

// 释放二叉树内存
void FreeSpaceBinaryTree(BinaryNode *node)
{
    if(node == NULL)
        return ;

    // 释放左子树
    FreeSpaceBinaryTree(node->lchild);
    // 释放右子树
    FreeSpaceBinaryTree(node->rchild);

    // 释放当前节点
    free(node);
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

    // 非递归的先序遍历
    NonRecursion(&node1);
    printf("\n");
    
    // 递归中序遍历
    MidOrderRecursion(&node1);
    printf("\n");

    // 非递归的中序遍历
    MidOrderNonRecursion(&node1);
    printf("\n");
    
    // 递归后序遍历
    BackOrderRecursion(&node1);
    printf("\n");
    // 非递归的中序遍历
    BackOrderNonRecursion(&node1);
    printf("\n");
}



int main()
{
    CreateBinaryTree();    
    return 0;
}

