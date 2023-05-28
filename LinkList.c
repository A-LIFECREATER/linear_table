/*
* LinkList.c
* 
* 单链表（带头节点）的相关基本函数的实现
* 
* author:	A-LifeCreator
* 
* date:	2023/5/28
* 
* void initLink(LinkHead* const head);		// 初始化链表
* void insertNode(LinkHead* const head, const int pos, const ELEMENT_TYPE val);		// 将元素插入到指定位置
* void deleteNode(LinkHead* const head, const int pos);	// 删除指定位置的元素
* ELEMENT_TYPE searchNode(LinkHead* const head, const int pos);	// 查找指定位置的元素
* void modifyNode(LinkHead* const head, const int pos, const ELEMENT_TYPE val);		// 修改指定位置的元素的值
* void destoryLink(LinkHead* const head)	销毁链表
*/

#include "LinkList.h"

/*
* 功能：	初始化链表
* 参数：	要初始化的链表
* 返回值：	无
*/
void initLink(LinkHead* const head)
{
	head->base = NULL;	// 头节点后没有数据结点
	head->size = 0;		// 数据节点个数为0
}

/*
* 功能：	将元素插入指定位置
* 参数：	链表头节点	指定位置		插入的元素
* 返回值：	无
*/
void insertNode(LinkHead* const head, const int pos, const ELEMENT_TYPE val)
{
	// 检查位置合法性
	if (pos > head->size + 1 || pos < 1)
	{
		return;
	}

	// 创建新的数据节点
	Node* newNode = (Node*) malloc(sizeof(Node));
	if (newNode == NULL)
	{
		return;
	}
	newNode->data = val;
	newNode->next = NULL;
	
	// 如果用户要插入到第一个位置
	if (pos == 1)
	{
		// 直接在头节点后面添加就好
		Node* nextNode = head->base;
		head->base = newNode;
		newNode->next = nextNode;
	}
	else
	{
		Node* preMove = head->base;		// 记录移动指针的前一个节点
		Node* move = preMove->next;		// 移动指针，用来遍历整个链表
		int nowPos = 2;					// 记录当前在遍历到哪个位置

		// 定位具体位置
		while (nowPos != pos)
		{
			preMove = move;
			move = move->next;
			nowPos++;
		}

		// 将新节点连接进链表
		preMove->next = newNode;
		newNode->next = move;
	}

	// 链表总元素个数+1
	head->size++;
}

/*
* 功能：	删除指定位置的元素
* 参数：	要删除元素的链表	要删除的位置
* 返回值：	无
*/
void deleteNode(LinkHead* const head, const int pos)
{
	// 检查位置的合法性
	if (pos < 1 || pos > head->size)
	{
		return;
	}

	// 如果要删除的就是第一个数据元素
	if (pos == 1)
	{
		Node* deleteNode = head->base;
		head->base = deleteNode->next;
		free(deleteNode);
		deleteNode = NULL;
	}
	else
	{
		int nowPos = 2;					// 记录当前位置
		Node* preMove = head->base;		// 记录遍历指针前一个节点
		Node* move = preMove->next;		// 遍历指针

		// 寻找指定位置
		while (nowPos != pos)
		{
			preMove = move;
			move = move->next;
			nowPos++;
		}

		// 删除元素
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
* 功能：	查找指定位置的元素
* 参数：	要查找的元素		要查找的位置
* 返回值：	存在：该位置的元素	不存在：	无
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
* 功能： 修改指定元素值
* 参数：	要修改的链表		要修改的位置		修改后的值
* 返回值：	无
*/
void modifyNode(LinkHead* const head, const int pos, const ELEMENT_TYPE val)
{
	// 位置合法性检查
	if (pos < 1 || pos > head->size)
	{
		return;
	}

	// 开始搜索指定位置
	int nowPos = 1;
	Node* move = head->base;

	while (nowPos != pos)
	{
		move = move->next;
		nowPos++;
	}

	// 开始修改
	move->data = val;
}

/*
* 功能：	销毁初始化的链表	释放堆区内存
* 参数：	要销毁的链表
* 返回值： 无
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

	printf("加入元素后的链表为：\n");
	for (Node* move = pHead->base; move != NULL; move = move->next)
	{
		printf("%d ", move->data);
	}
	printf("\n");

	deleteNode(pHead, 10);
	printf("删除第10个元素后的链表为：\n");
	for (Node* move = pHead->base; move != NULL; move = move->next)
	{
		printf("%d ", move->data);
	}
	printf("\n");

	modifyNode(pHead, 5, 1000);
	printf("修改第五个元素为1000后的链表为：\n");
	for (Node* move = pHead->base; move != NULL; move = move->next)
	{
		printf("%d ", move->data);
	}
	printf("\n");

	printf("链表中第9个元素为: %d\n", searchNode(pHead, 9));

	destoryLink(pHead);

	system("pause");

	return 0;
}