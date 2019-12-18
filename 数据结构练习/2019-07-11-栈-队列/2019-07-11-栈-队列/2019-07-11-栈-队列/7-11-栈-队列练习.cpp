#include"7-11My.h"

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<cstring>
#include<stack>
#include<queue>

//������������
CNode * copy(CNode *head)
{
	if (head == NULL)
	{
		return NULL;
	}
	CNode *cur = head;
	while (cur != NULL)
	{
		CNode *node = (CNode *)malloc(sizeof(CNode));
		node->val = cur->val;
		node->next = cur->next;
		cur->next = node;
		cur = node->next;
	}
	cur = head;
	while (cur != NULL)
	{
		if (cur->random != NULL)
		{
			cur->next->random = cur->random->next;
		}
		else
		{
			cur->next->random = NULL;
		}
		cur = cur->next->next;
	}
	cur = head;
	CNode *newHead = head->next;
	while (cur != NULL)
	{
		CNode *node = cur->next;
		cur->next = node->next;
		if (node->next != NULL)
		{
			node->next = node->next->next;
		}
		cur = cur->next;
	}
	return newHead;
}


//������
Node *createNode(int val)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->val = val;
	return node;
}

//ջ��ʼ��
void StackInit(Stack *s)
{
	s->top = 0;
}
//ѹջ
void StackPush(Stack *s, int val)
{
	s->array[s->top++] = val;
}
//��ջ
int StackPop(Stack *s)
{
	assert(s->top > 0);
	return s->array[--s->top];
}
//�鿴ջ��Ԫ��
int StackTop(Stack *s)
{
	return s->array[s->top-1];
}
//�鿴ջ�Ĵ�С
int StackSize(Stack *s)
{
	return s->top;
}
//�ж�ջ�Ƿ�Ϊ��
int StackEmpty(Stack *s)
{
	return s->top == 0 ? 1 : 0;
}


/*
���У��Ƚ��ȳ� FIFO)

1.��ͨ˳���  �����и�O(n)
2.�����к��ƶ�  �ռ�Խ��ԽС
   1��ѭ������   ��ָʾ�±�ѭ������
   2�����뵽���ʱ��ͳһ���ƣ����ٰ���Ƶ��
*/


//���г�ʼ��
void QueueInit(Queue *q)
{
	q->front = q->rear = NULL;
}
//���в���
void QueuePush(Queue *q, int val)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->val = val;
	if (q->front == NULL)
	{
		q->front = node;
	}
	else
	{
		q->rear->next = node;
	}
	q->rear = node;
}
//����ɾ��
int QueuePop(Queue *q)
{
	assert(q->front != NULL);
	Node *second = q->front->next;
	int val = q->front->val;
	free(q->front);
	q->front = second;

	if (q->front == NULL) {
		q->rear = NULL;
	}

	return val;
}
//������Ԫ��
int QueueFront(Queue *q)
{
	assert(q->front != NULL);
	return q->front->val;
}

//����ƥ������
class Solution
{
public:
	bool isValid(string str)
	{
		std::stack<char>  s;
		int size = str.size();//ȡ�ַ�������
		for (int i = 0; i < size; i++)
		{
			char ch = str[i];//ȡi���ַ�
			switch (ch)
			{
			case '(':case '[':case '{':
				s.push(ch);
				break;
			case ')':case ']':case'}':
			{
				if (s.empty())
				{
					return false;
				}
				char left = s.top();
				s.pop();
				if (!((left == '(' && ch == ')')
					|| (left == '[' && ch == ']')
					|| (left == '{' && ch == '}'))) {
					return false;
				}
				break;
			}
			default:
				break;
			}
		}
		if (!s.empty())
	    {
		     return false;
	    }
	    return true;
	}
	
};

//����ʵ��ջ
class Mystack
{
	std::queue<int> q;//���нṹ��
public:
	Mystack(){}//���췽��
	void push(int x)
	{
		q.push(x);
	}
	int pop()
	{
		int n = q.size();
		for (int i = 0; i < n - 1; i++)
		{
			int v = q.front();
			q.pop();
			q.push(v);
		}
		int v = q.front();
		q.pop();
		return v;
	}
	int top()
	{
		int n = q.size();
		for (int i = 0; i < n - 1; i++)
		{
			int v = q.front();
			q.pop();
			q.push(v);
		}
		int v = q.front();
		q.pop();
		q.push(v);
		return v;
	}
	bool empty()
	{
		return q.empty();
	}
};

//��ջʵ�ֶ���
class MyQueue
{
	std::stack<int> in;
	std::stack<int> out;
public:
	MyQueue() {}
	void push(int x)
	{
		in.push(x);
	}
	int pop()
	{
		if (out.empty())
		{
			int n = in.size();
			for (int i = 0; i < n; i++)
			{
				int v = in.top();
				in.pop();
				out.push(v);
			}
		}
		int v = out.top();
		out.pop();
		return v;
	}
	int peek()
	{
		if (out.empty())
		{
			while (!in.empty())
			{
				int v = in.top();
				in.pop();
				out.push(v);
			}
		}
		int v = out.top();
		return v;
	}
	bool empty()
	{
		return in.empty() && out.empty();
	}

};



//ʵ��һ����Сջ

class MinStack
{
public:
	std::stack<int> normal;
	std::stack<int> min;

	MinStack(){}
	void push(int x)//push(x) -- ��Ԫ�� x ����ջ�С�
	{
		normal.push(x);
		if (min.empty() || x <= min.top())
		{
			min.push(x);
		}
		else
		{
			min.push(min.top());
		}
	}
	void pop()//pop() -- ɾ��ջ����Ԫ�ء�
	{
		normal.pop();
		min.pop();
	}
	int top()//top() -- ��ȡջ��Ԫ�ء�
	{
		return normal.top();
	}
	int getMin()//getMin() -- ����ջ�е���СԪ�ء�
	{
		return min.top();
	}

};



//���ѭ������
class MyCircularQueue {
	int *array;
	int capacity;
	int front;
	int rear;
	int size;

public:
	/** Initialize your data structure here. Set the size of the queue to be k. */
	MyCircularQueue(int k) //�����������ö��г���Ϊ k ��
	{
		array = (int *)malloc(sizeof(int)*k);
		capacity = k;
		front = 0;
		rear = 0;
		size = 0;
	}

	/** Insert an element into the circular queue. Return true if the operation is successful. */
	bool enQueue(int value)//��ѭ�����в���һ��Ԫ�ء�����ɹ������򷵻��档
	{
		if (size >= capacity)
		{
			return false;
		}
		array[rear] = value;
		rear = (rear + 1) % capacity;
		size++;
		return true;
	}

	/** Delete an element from the circular queue. Return true if the operation is successful. */
	bool deQueue()//��ѭ��������ɾ��һ��Ԫ�ء�����ɹ�ɾ���򷵻���
	{
		if (size == 0)
		{
			return false;
		}
		front = (front + 1) % capacity;
		size--;
		return true;
	}

	/** Get the front item from the queue. */
	int Front()//�Ӷ��׻�ȡԪ�ء��������Ϊ�գ����� - 1 ��
	{
		if (size == 0)
		{
			return -1;
		}
		return array[front];
	}

	/** Get the last item from the queue. */
	int Rear() //��ȡ��βԪ�ء��������Ϊ�գ����� -1 ��
	{
		if (size == 0)
		{
			return -1;
		}
		int index = (rear + capacity - 1) % capacity;
		return array[index];
	}

	/** Checks whether the circular queue is empty or not. */
	bool isEmpty() // ���ѭ�������Ƿ�Ϊ�ա�
	{
		return size == 0;
	}

	/** Checks whether the circular queue is full or not. */
	bool isFull() //���ѭ�������Ƿ�������
	{
		return size == capacity;
	}
}