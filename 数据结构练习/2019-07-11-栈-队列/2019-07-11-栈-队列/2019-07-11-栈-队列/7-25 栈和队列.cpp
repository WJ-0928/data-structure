#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<queue>
#include<stack>

#if 0
typedef struct Stack
{
	int* _array;
	int _capacity;
	int _top; // ���ջ��λ�� 
}Stack;

// ��ʼ��ջ 
void StackInit(Stack* ps)
{
	ps->_top = 0;
}

// ��ջ 
void StackPush(Stack* ps, int data)
{
	ps->_array[ps->_top++] = data;
}

// ��ջ 
void StackPop(Stack* ps)
{
	assert(ps->_top > 0);
	ps->_array[--ps->_top];
}

// ��ȡջ��Ԫ�� 
int StackTop(Stack* ps)
{
	assert(ps->_top > 0);
	return ps->_array[ps->_top-1];
}

// ��ȡջ����ЧԪ�ظ��� 
int StackSize(Stack* ps)
{
	return ps->_array[ps->_top];
}

// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 
int StackEmpty(Stack* ps)
{
	return ps->_top == 0 ? 1 : 0;
}

// ����ջ 
void StackDestroy(Stack* ps)
{
	assert(ps);

	if (ps->_array == NULL)
	{
		return;
	}
	ps->_capacity = 0;
	ps->_top = 0;
	free(ps->_array);
	ps->_array = NULL;
	ps = NULL;

}


// ��ʽ�ṹ����ʾ���� 
typedef struct QListNode
{
	struct QListNode* _pNext;
	int _data;
}QNode;

// ���еĽṹ 
typedef struct Queue
{
	QNode* _front;
	QNode* _rear;
}Queue;

// ��ʼ������ 
void QueueInit(Queue* q)
{
	q->_rear=q->_front = NULL;
}

// ��β����� 
void QueuePush(Queue* q, int data)
{
	QNode* node = (QNode*)malloc(sizeof(QNode));
	node->_data = data;
	if (q->_front == NULL)
	{
		q->_front =node;
	}
	else
	{
		q->_rear->_pNext = node;
	}
	q->_rear = node;
}

// ��ͷ������ 
void QueuePop(Queue* q)
{

	assert(q);
	if (NULL == q->_front)
	{
		return;
	}
	//һ��Ԫ��
	if (NULL == q->_front->_pNext)
	{
		q->_front = NULL;
		free(q->_front);
		return;
	}
	//���Ԫ��
	else
	{
		q->_front = q->_front->_pNext;
	}
	free(q->_front->_pNext);
	q->_front->_pNext = NULL;
}

// ��ȡ����ͷ��Ԫ�� 
int QueueFront(Queue* q)
{
	assert(q->_front != NULL);
	return q->_front->_data;
}

// ��ȡ���ж�βԪ�� 
int QueueBack(Queue* q)
{
	assert(q->_front != NULL);
	return q->_rear->_data;
}

// ��ȡ��������ЧԪ�ظ��� 
int QueueSize(Queue* q)
{
	assert(q->_front != NULL);
	int count = 0;
	while (q->_front!=NULL)
	{
		count++;
		q->_front = q->_front->_pNext;
	}
	return count;
}

// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q)
{
	return q->_front == NULL ? 1 : 0;
}

// ���ٶ��� 
void QueueDestroy(Queue* q)
{
	while (q->_front != NULL)
	{
		q->_rear = q->_front->_pNext;
		free(q->_front);
		q->_front = q->_rear;
	}
}




//�ö���ʵ��ջ
class MyStack {
	std::queue<int> q;
public:
	/** Initialize your data structure here. */
	MyStack() {

	}

	/** Push element x onto stack. */
	void push(int x) {
		q.push(x);

	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		int n = q.size();
		for (int i = 0; i < n-1; i++)
		{
			int v = q.front();
			q.pop();
			q.push(v);
		}
		int v = q.front();
		q.pop();
		return v;
	}

	/** Get the top element. */
	int top() {
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

	/** Returns whether the stack is empty. */
	bool empty() {
		return q.empty();
	}
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

//��Ч����
class Solution {
public:
	bool isValid(string s) {
		std::stack<char> str;
		int size = s.size();
		for (int i = 0; i < size; i++)
		{
			char ch = s[i];
			switch (ch)
			{
			case '(':case '[':case '{':

				str.push(ch);
				break;
			case ')':case ']':case'}':
			{
				if (str.empty())
				{
					return false;
				}
				char left = str.top();
				str.pop();
				if (!((left == '('&&ch == ')')
					|| (left == '['&&ch == ']')
					|| (left == '{'&&ch == '}')))
				{
					return false;
				}
				break;
			}
			default:
				break;
			}
		}
		if (!str.empty())
	    {
			return false;
	     }
		return true;
	}
	
};
#endif




//ջʵ�ֶ���
class MyQueue {
	std::stack<int> in;
	std::stack<int> out;
public:
	/** Initialize your data structure here. */
	MyQueue() {

	}

	/** Push element x to the back of queue. */
	void push(int x) {
		in.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
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

	/** Get the front element. */
	int peek() {
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

	/** Returns whether the queue is empty. */
	bool empty() {
		return in.empty() && out.empty();
	}
};


//��Сջ
class MinStack {
	
public:
	std::stack<int> normal;
	std::stack<int> min;
	/** initialize your data structure here. */
	MinStack() {

	}

	void push(int x) {
		normal.push(x);
		if (min.empty() || x < min.top())
		{
			min.push(x);
		}
		else
		{
			min.push(min.top());
		}
	}

	void pop() {
		normal.pop();
		min.pop();
	}

	int top() {
		return normal.top();
	}

	int getMin() {
		return min.top();
	}
};
