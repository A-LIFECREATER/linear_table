/*
* LinkList.h
* ����Ľṹ����ͳ��ú�������
*/

#pragma once

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>	

#define ELEMENT_TYPE int	// ���������洢��Ԫ����������

// �������ݽ��Ľṹ
typedef struct Node
{
	ELEMENT_TYPE data;	// ��ŵ�����
	struct Node* next;	// ָ����
}Node;

// ����ͷ�ڵ�Ľṹ	(Ҳ����ֱ��ʹ��һ��������Ϊ�յ����ݽڵ�䵱ͷ�ڵ㣬�᷽��ܶ�)
typedef struct Link
{
	struct Node* base;	// ���ݽڵ�Ļ���ַ
	int size;	// ����ĳ���
}LinkHead;


//-----------------------------------����������������--------------------------

void initLink(LinkHead* const head);		// ��ʼ������
void insertNode(LinkHead* const head, const int pos, const ELEMENT_TYPE val);		// ��Ԫ�ز��뵽ָ��λ��
void deleteNode(LinkHead* const head, const int pos);	// ɾ��ָ��λ�õ�Ԫ��
ELEMENT_TYPE searchNode(LinkHead* const head, const int pos);	// ����ָ��λ�õ�Ԫ��
void modifyNode(LinkHead* const head, const int pos, const ELEMENT_TYPE val);		// �޸�ָ��λ�õ�Ԫ�ص�ֵ
void destoryLink(LinkHead* const head);			// ��������
