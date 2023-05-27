/*
* SquentialList.c
* 
* ˳����ú�����ʵ��
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
* ���ܣ�	��˳����ʼ��
* ������	˳����ַ
* ����ֵ����
*/
void initSqList(sqPtr const listPtr)
{
	listPtr->arrBase = (ELEMENT_TYPE*) malloc(sizeof(ELEMENT_TYPE) * MAX_SIZE);
	listPtr->arrSize = 0;	// û��Ԫ��
}

/*
* ���ܣ�	�ж�˳����Ƿ�Ϊ��
* ������	˳����ַ
* ����ֵ��Ϊ��--true		����--false
*/
bool isEmpty(sqPtr listPtr)
{
	if (listPtr->arrSize == 0)	// �߼���Ϊ��
		return true;
	else
		return false;
}

/*
* ���ܣ�	��˳����ָ��λ�����Ԫ��
* ������	˳����ַ	�����Ԫ��	ָ����λ��
* ����ֵ:	��
*/
void insertElem(sqPtr const listPtr, ELEMENT_TYPE val, int pos)
{
	// �ж�˳����Ƿ�Ϊ��
	if (listPtr->arrSize == MAX_SIZE)
	{
		return;
	}
	
	// �жϲ���λ���Ƿ�Ϸ�
	if (pos < 1 || pos > listPtr->arrSize + 1)
	{
		return;
	}

	// �ƶ�Ԫ�أ��� pos-1 λ�ÿճ���
	for (int i = listPtr->arrSize - 1; i >= pos - 1; i--)
	{
		listPtr->arrBase[i + 1] = listPtr->arrBase[i];
	}

	// ����ָ��Ԫ��
	listPtr->arrBase[pos - 1] = val;
	listPtr->arrSize++;		// ˳���ǰ��С+1
}

/*
* ���ܣ�	ɾ��ָ��λ�õ�Ԫ��
* ������	˳����ַ	Ҫɾ����λ��
* ����ֵ��	��
*/
void deleteElem(sqPtr const listPtr, int pos)
{
	// �ж�˳����Ƿ�Ϊ��
	if (isEmpty(listPtr) == true)
	{
		return;
	}

	// �ж�ɾ��λ���Ƿ�Ϸ�
	if (pos < 1 || pos > listPtr->arrSize)
	{
		return;
	}

	// �ƶ�Ԫ�أ��� pos-1 λ��������λ�ü���	�߼���ɾ��
	for (int i = pos - 1; i < listPtr->arrSize - 1; i++)
	{
		listPtr->arrBase[i] = listPtr->arrBase[i + 1];
	}
	listPtr->arrSize--;
}

/*
* ���ܣ�	����ָ��Ԫ���Ƿ���˳�����
* ������	˳����ַ	Ҫ���ҵ�Ԫ��
* ����ֵ��	����--true	������--false
*/
bool searchElem(sqPtr const listPtr, ELEMENT_TYPE val)
{
	// ֱ�ӱ�������
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
* ���ܣ�	�޸�ָ��Ԫ��
* ������	˳����ַ	ָ��λ��		�޸ĺ��ֵ
* ����ֵ��	��
*/
void modifyElem(sqPtr const listPtr, int pos, ELEMENT_TYPE val)
{
	// �ж��޸�λ���Ƿ�Ϸ�
	if (pos < 1 || pos > listPtr->arrSize)
	{
		return;
	}

	// �޸�ָ��Ԫ��
	listPtr->arrBase[pos - 1] = val;
}

/*
* ���ܣ�	��ӡ����˳���
* ������	˳����ַ
* ����ֵ��	��
*/
void showInfo(sqPtr const listPtr)
{
	if (listPtr->arrSize == 0)
	{
		printf("˳���Ϊ��");
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
* ���ܣ�	����˳���	�ͷŶ����ڴ�
* ������	˳����ַ
* ����ֵ��	��
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
