/*
* LinkList.h
* 链表的结构定义和常用函数声明
*/

#pragma once

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>	

#define ELEMENT_TYPE int	// 链表用来存储的元素数据类型

// 定义数据结点的结构
typedef struct Node
{
	ELEMENT_TYPE data;	// 存放的数据
	struct Node* next;	// 指针域
}Node;

// 定义头节点的结构	(也可以直接使用一个数据域为空的数据节点充当头节点，会方便很多)
typedef struct Link
{
	struct Node* base;	// 数据节点的基地址
	int size;	// 链表的长度
}LinkHead;


//-----------------------------------基础操作函数声明--------------------------

void initLink(LinkHead* const head);		// 初始化链表
void insertNode(LinkHead* const head, const int pos, const ELEMENT_TYPE val);		// 将元素插入到指定位置
void deleteNode(LinkHead* const head, const int pos);	// 删除指定位置的元素
ELEMENT_TYPE searchNode(LinkHead* const head, const int pos);	// 查找指定位置的元素
void modifyNode(LinkHead* const head, const int pos, const ELEMENT_TYPE val);		// 修改指定位置的元素的值
void destoryLink(LinkHead* const head);			// 销毁链表
