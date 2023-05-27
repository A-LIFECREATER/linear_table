/*
* SquentialList.c
* 
* 顺序表常用函数的实现
* 
* author: A_lifeCreator
* 
* date:	2023/5/28
* 
* void initSqList(sqPtr const listPtr);
* bool isEmpty(sqPtr const listPtr);
* void insertElem(sqPtr const listPtr, ELEMENT_TYPE val, int pos);
* void deleteElem(sqPtr const listPtr, int pos);
* bool searchElem(sqPtr const listPtr, ELEMENT_TYPE val);
* void modifyElem(sqPtr const listPtr, int pos, ELEMENT_TYPE val);
* void showInfo(sqPtr const listPtr);
* void destoryList(sqPtr const listPtr);
* 
*/

#include "SquentialList.h"

/*
* 功能：	将顺序表初始化
* 参数：	顺序表地址
* 返回值：无
*/
void initSqList(sqPtr const listPtr)
{
	listPtr->arrBase = (ELEMENT_TYPE*) malloc(sizeof(ELEMENT_TYPE) * MAX_SIZE);
	listPtr->arrSize = 0;	// 没有元素
}

/*
* 功能：	判断顺序表是否为空
* 参数：	顺序表地址
* 返回值：为空--true		不空--false
*/
bool isEmpty(sqPtr listPtr)
{
	if (listPtr->arrSize == 0)	// 逻辑上为空
		return true;
	else
		return false;
}

/*
* 功能：	在顺序表的指定位置添加元素
* 参数：	顺序表地址	插入的元素	指定的位置
* 返回值:	无
*/
void insertElem(sqPtr const listPtr, ELEMENT_TYPE val, int pos)
{
	// 判断顺序表是否为满
	if (listPtr->arrSize == MAX_SIZE)
	{
		return;
	}
	
	// 判断插入位置是否合法
	if (pos < 1 || pos > listPtr->arrSize + 1)
	{
		return;
	}

	// 移动元素，将 pos-1 位置空出来
	for (int i = listPtr->arrSize - 1; i >= pos - 1; i--)
	{
		listPtr->arrBase[i + 1] = listPtr->arrBase[i];
	}

	// 插入指定元素
	listPtr->arrBase[pos - 1] = val;
	listPtr->arrSize++;		// 顺序表当前大小+1
}

/*
* 功能：	删除指定位置的元素
* 参数：	顺序表地址	要删除的位置
* 返回值：	无
*/
void deleteElem(sqPtr const listPtr, int pos)
{
	// 判断顺序表是否为空
	if (isEmpty(listPtr) == true)
	{
		return;
	}

	// 判断删除位置是否合法
	if (pos < 1 || pos > listPtr->arrSize)
	{
		return;
	}

	// 移动元素，将 pos-1 位置用其他位置挤掉	逻辑上删除
	for (int i = pos - 1; i < listPtr->arrSize - 1; i++)
	{
		listPtr->arrBase[i] = listPtr->arrBase[i + 1];
	}
	listPtr->arrSize--;
}

/*
* 功能：	查找指定元素是否在顺序表中
* 参数：	顺序表地址	要查找的元素
* 返回值：	存在--true	不存在--false
*/
bool searchElem(sqPtr const listPtr, ELEMENT_TYPE val)
{
	// 直接遍历查找
	for (int i = 0; i < listPtr->arrSize; i++)
	{
		if (listPtr->arrBase[i] == val)
		{
			return true;
		}
	}

	return false;
}

/*
* 功能：	修改指定元素
* 参数：	顺序表地址	指定位置		修改后的值
* 返回值：	无
*/
void modifyElem(sqPtr const listPtr, int pos, ELEMENT_TYPE val)
{
	// 判断修改位置是否合法
	if (pos < 1 || pos > listPtr->arrSize)
	{
		return;
	}

	// 修改指定元素
	listPtr->arrBase[pos - 1] = val;
}

/*
* 功能：	打印整个顺序表
* 参数：	顺序表地址
* 返回值：	无
*/
void showInfo(sqPtr const listPtr)
{
	if (listPtr->arrSize == 0)
	{
		printf("顺序表为空");
		return;
	}
	else
	{
		for (int i = 0; i < listPtr->arrSize; i++)
		{
			printf("%d ", listPtr->arrBase[i]);
		}
		printf("\n");
	}
}

/*
* 功能：	销毁顺序表	释放堆区内存
* 参数：	顺序表地址
* 返回值：	无
*/
void destoryList(sqPtr const listPtr)
{
	if (listPtr->arrBase != NULL)
	{
		free(listPtr->arrBase);
		listPtr->arrBase = NULL;
		listPtr->arrSize = 0;
	}
}
