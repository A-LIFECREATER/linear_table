/*
* LinkList.c
* 
* ��������ͷ�ڵ㣩����ػ���������ʵ��
* 
* author:	A-LifeCreator
* 
* date:	2023/5/28
* 
* void initLink(LinkHead* const head);		// ��ʼ������
* void insertNode(LinkHead* const head, const int pos, const ELEMENT_TYPE val);		// ��Ԫ�ز��뵽ָ��λ��
* void deleteNode(LinkHead* const head, const int pos);	// ɾ��ָ��λ�õ�Ԫ��
* ELEMENT_TYPE searchNode(LinkHead* const head, const int pos);	// ����ָ��λ�õ�Ԫ��
* void modifyNode(LinkHead* const head, const int pos, const ELEMENT_TYPE val);		// �޸�ָ��λ�õ�Ԫ�ص�ֵ
* void destoryLink(LinkHead* const head)	��������
*/

#include "LinkList.h"

/*
* ���ܣ�	��ʼ������
* ������	Ҫ��ʼ��������
* ����ֵ��	��
*/
void initLink(LinkHead* const head)
{
	head->base = NULL;	// ͷ�ڵ��û�����ݽ��
	head->size = 0;		// ���ݽڵ����Ϊ0
}

/*
* ���ܣ�	��Ԫ�ز���ָ��λ��
* ������	����ͷ�ڵ�	ָ��λ��		�����Ԫ��
* ����ֵ��	��
*/
void insertNode(LinkHead* const head, const int pos, const ELEMENT_TYPE val)
{
	// ���λ�úϷ���
	if (pos > head->size + 1 || pos < 1)
	{
		return;
	}

	// �����µ����ݽڵ�
	Node* newNode = (Node*) malloc(sizeof(Node));
	if (newNode == NULL)
	{
		return;
	}
	newNode->data = val;
	newNode->next = NULL;
	
	// ����û�Ҫ���뵽��һ��λ��
	if (pos == 1)
	{
		// ֱ����ͷ�ڵ������Ӿͺ�
		Node* nextNode = head->base;
		head->base = newNode;
		newNode->next = nextNode;
	}
	else
	{
		Node* preMove = head->base;		// ��¼�ƶ�ָ���ǰһ���ڵ�
		Node* move = preMove->next;		// �ƶ�ָ�룬����������������
		int nowPos = 2;					// ��¼��ǰ�ڱ������ĸ�λ��

		// ��λ����λ��
		while (nowPos != pos)
		{
			preMove = move;
			move = move->next;
			nowPos++;
		}

		// ���½ڵ����ӽ�����
		preMove->next = newNode;
		newNode->next = move;
	}

	// ������Ԫ�ظ���+1
	head->size++;
}

/*
* ���ܣ�	ɾ��ָ��λ�õ�Ԫ��
* ������	Ҫɾ��Ԫ�ص�����	Ҫɾ����λ��
* ����ֵ��	��
*/
void deleteNode(LinkHead* const head, const int pos)
{
	// ���λ�õĺϷ���
	if (pos < 1 || pos > head->size)
	{
		return;
	}

	// ���Ҫɾ���ľ��ǵ�һ������Ԫ��
	if (pos == 1)
	{
		Node* deleteNode = head->base;
		head->base = deleteNode->next;
		free(deleteNode);
		deleteNode = NULL;
	}
	else
	{
		int nowPos = 2;					// ��¼��ǰλ��
		Node* preMove = head->base;		// ��¼����ָ��ǰһ���ڵ�
		Node* move = preMove->next;		// ����ָ��

		// Ѱ��ָ��λ��
		while (nowPos != pos)
		{
			preMove = move;
			move = move->next;
			nowPos++;
		}

		// ɾ��Ԫ��
		preMove->next = move->next;
		if (move != NULL)
		{
			free(move);
			move = NULL;
		}
	}

	head->size--;
}

/*
* ���ܣ�	����ָ��λ�õ�Ԫ��
* ������	Ҫ���ҵ�Ԫ��		Ҫ���ҵ�λ��
* ����ֵ��	���ڣ���λ�õ�Ԫ��	�����ڣ�	��
*/
ELEMENT_TYPE searchNode(LinkHead* const head, const int pos)
{
	if (pos < 1 || pos > head->size)
	{
		return;
	}

	int nowPos = 1;
	Node* move = head->base;
	
	while (nowPos != pos)
	{
		move = move->next;
		nowPos++;
	}

	return move->data;
}

/*
* ���ܣ� �޸�ָ��Ԫ��ֵ
* ������	Ҫ�޸ĵ�����		Ҫ�޸ĵ�λ��		�޸ĺ��ֵ
* ����ֵ��	��
*/
void modifyNode(LinkHead* const head, const int pos, const ELEMENT_TYPE val)
{
	// λ�úϷ��Լ��
	if (pos < 1 || pos > head->size)
	{
		return;
	}

	// ��ʼ����ָ��λ��
	int nowPos = 1;
	Node* move = head->base;

	while (nowPos != pos)
	{
		move = move->next;
		nowPos++;
	}

	// ��ʼ�޸�
	move->data = val;
}

/*
* ���ܣ�	���ٳ�ʼ��������	�ͷŶ����ڴ�
* ������	Ҫ���ٵ�����
* ����ֵ�� ��
*/
void destoryLink(LinkHead* const head)
{
	Node* move = head->base;

	while (move != NULL)
	{
		Node* deleteNode = move;
		move = move->next;
		free(deleteNode);
		deleteNode = NULL;
	}

	head->base = NULL;
	head->size = 0;
}



int main(void)
{
	LinkHead head;
	LinkHead* pHead = &head;

	initLink(pHead);

	for (int i = 0; i < 20; i++)
	{
		insertNode(pHead, i + 1, i + 1);
	}

	printf("����Ԫ�غ������Ϊ��\n");
	for (Node* move = pHead->base; move != NULL; move = move->next)
	{
		printf("%d ", move->data);
	}
	printf("\n");

	deleteNode(pHead, 10);
	printf("ɾ����10��Ԫ�غ������Ϊ��\n");
	for (Node* move = pHead->base; move != NULL; move = move->next)
	{
		printf("%d ", move->data);
	}
	printf("\n");

	modifyNode(pHead, 5, 1000);
	printf("�޸ĵ����Ԫ��Ϊ1000�������Ϊ��\n");
	for (Node* move = pHead->base; move != NULL; move = move->next)
	{
		printf("%d ", move->data);
	}
	printf("\n");

	printf("�����е�9��Ԫ��Ϊ: %d\n", searchNode(pHead, 9));

	destoryLink(pHead);

	system("pause");

	return 0;
}