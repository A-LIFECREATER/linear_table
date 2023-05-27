/*
* SquentialList.h
* 顺序表的定义和常用函数声明
*/

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ELEMENT_TYPE int	// 顺序表的元素类型
#define MAX_SIZE 20			// 顺序表的最大长度

// 顺序表结构定义
typedef struct Sqlist
{
	ELEMENT_TYPE *arrBase;	// 顺序表的基地址
	int arrSize;			// 顺序表当前长度
}sqList, *sqPtr;

//-------------------------基本操作函数-----------------------------------------

// 初始化
void initSqList(sqPtr const listPtr);

// 判断元素是否为空
bool isEmpty(sqPtr const listPtr);

// 增加元素
void insertElem(sqPtr const listPtr, ELEMENT_TYPE val, int pos);

// 删除元素
void deleteElem(sqPtr const listPtr, int pos);

// 查找元素
bool searchElem(sqPtr const listPtr, ELEMENT_TYPE val);

// 修改元素
void modifyElem(sqPtr const listPtr, int pos, ELEMENT_TYPE val);

// 打印整个顺序表
void showInfo(sqPtr const listPtr);

// 销毁顺序表
void destoryList(sqPtr const listPtr);
