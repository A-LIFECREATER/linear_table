/*
* SquentialList.h
* ˳���Ķ���ͳ��ú�������
*/

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ELEMENT_TYPE int	// ˳����Ԫ������
#define MAX_SIZE 20			// ˳������󳤶�

// ˳���ṹ����
typedef struct Sqlist
{
	ELEMENT_TYPE *arrBase;	// ˳���Ļ���ַ
	int arrSize;			// ˳���ǰ����
}sqList, *sqPtr;

//-------------------------������������-----------------------------------------

// ��ʼ��
void initSqList(sqPtr const listPtr);

// �ж�Ԫ���Ƿ�Ϊ��
bool isEmpty(sqPtr const listPtr);

// ����Ԫ��
void insertElem(sqPtr const listPtr, ELEMENT_TYPE val, int pos);

// ɾ��Ԫ��
void deleteElem(sqPtr const listPtr, int pos);

// ����Ԫ��
bool searchElem(sqPtr const listPtr, ELEMENT_TYPE val);

// �޸�Ԫ��
void modifyElem(sqPtr const listPtr, int pos, ELEMENT_TYPE val);

// ��ӡ����˳���
void showInfo(sqPtr const listPtr);

// ����˳���
void destoryList(sqPtr const listPtr);
