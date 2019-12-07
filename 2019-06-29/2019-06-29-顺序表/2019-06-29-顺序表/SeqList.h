#pragma once	// ��֤ͷ�ļ�ֻ����һ��

struct SeqList {
	int*	array;			// ��¼���ݴ��λ�ã����ҵĵ�ַ��
	int		capacity;		// ��¼������		�����ҵĴ�С��
	int		size;			// ��¼�������ݸ���	����ͬѧ�����棩
};

// Ϊ������һ������
typedef struct SeqList SeqList;

// ��ʼ��
void SeqListInit(SeqList *seq);
// ����
void SeqListDestroy(SeqList *seq);

// ͷ��
void SeqListPushFront(SeqList *seq, int val);
// β��
void SeqListPushBack(SeqList *seq, int val);
// �����±�������
void SeqListInsert(SeqList *seq, int index, int val);

// ͷɾ
void SeqListPopFront(SeqList *seq);
// βɾ
void SeqListPopBack(SeqList *seq);
// �����±���ɾ��
void SeqListErase(SeqList *seq, int index);

// ����
int SeqListFind(SeqList *seq, int val);

// ��ӡ
void SeqListPrint(SeqList *seq);