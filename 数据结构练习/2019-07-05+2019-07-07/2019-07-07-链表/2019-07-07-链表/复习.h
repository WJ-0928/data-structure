typedef struct Node {
	int val;
	struct Node *next;
}	Node;


// ��ת������
// 1 -> 2 -> 3 -> 4 -> 5
// 5 -> 4 -> 3 -> 2 -> 1
/*
˼·��
	�½�һ���µ�����(������)
	Node * result = NULL;

	���ϵı���ԭ���������ѽ��ͷ�嵽��������
	Node * cur = head;
	while (cur != NULL) {

		Node * next = cur->next;
		// ͷ��
		// ��ͷ��Ĺ��̣���ı� cur->next ��ֵ
		cur = next;
	}

	�� cur ͷ�嵽 result ��
	cur �Ѿ��Ǹ�����ˣ�����Ҫ malloc ������ô��	����Ҫ
	1) Ҫͷ��ı����Ǹ���㣨�Ѿ����ˣ�
	2) �½��(cur)����һ����ԭ���ĵ�һ�����(result)
		cur->next = result;
	3) ��������ĵ�һ����㣬��Ϊ cur ָ��Ľ��
	   �� result �� cur ָ��ͬһ�����
	   result = cur;
*/

Node * reverseList(Node * head) {
	Node * result = NULL;

	Node * cur = head;
	while (cur != NULL) {
		Node *next = cur->next;

		cur->next = result;
		result = cur;

		cur = next;
	}

	return result;
}


/*
�ϲ�������������

����һ��������������
Node *result = NULL;

ͬʱ������������Ҫ�����������ж����н�㣩
	ѡ��С��һ����β�嵽������(result)��
	
Node *c1 = head1;
Node *c2 = head2;

while (c1 != NULL && c2 != NULL) {
	if (c1->val <= c2->val) {
		// �� c1 β�嵽 result ��
		
		c1 = c1->next;
	} else {
		// �� c2 β�嵽 result ��
		
		c2 = c2->next;
	}
}

�� c1 β�嵽 result ��
1) ����Ϊ��	(result == NULL)
	ԭ������һ����㶼û�У��� c1 β�嵽 result ��
	��ζ�� result ������ֻ�� c1 һ�����
	result ָ�� c1 ���ڵĽ�㣬[c1 ����һ���� NULL �ⲽ�ǿ�ѡ��]
	result = c1;	c1->next = NULL;
2) ����Ϊ�� (result != NULL)
	1) ���� result ��������һ����� last
		��һ��������	�� ��һ����㣨result����ʼ������
		�ڶ���������	��¼
		last = c1;
	2) �� last ����һ������Ϊ c1
		last->next = c1;
	3) ��Ӱ�� result ����ĵ�һ�������˭ô������
	4) [c1 ����һ���� NULL �ⲽ�ǿ�ѡ��]
		c1->next = NULL;

���ѭ����������ζ���и������еĽ�㱻ȡ����
��ʣ�����������ӵ���������
*/
Node * merge(Node *head1, Node *head2) {
	if (head1 == NULL) ...
	if (head2 == NULL) ...
	
	Node * result = NULL;
	Node * last = NULL;
	
	Node *c1 = head1;
	Node *c2 = head2;
	
	while (c1 != NULL && c2 != NULL) {
		if (c1->val <= c2->val) {
			Node * next = c1->next;
			
			c1->next = NULL;
			if (result == NULL) {
				result = c1;
			} else {
				last->next = c1;
			}
			last = c1;
			
			c1 = next;
		} else {
			// ͬ������ c2
		}
	}
	
	if (c1 != NULL) {
		last->next = c1;
	} else {
		last->next = c2;
	}
	
	return result;
}

// ��������м�λ��
Node * findMiddle(Node *head) {
	Node * fast = head;
	Node * slow = head;
	
	while (fast != NULL) {
		fast = fast->next;
		if (fast == NULL) {
			break;
		}
		slow = slow->next;
		fast = fast->next;
	}
	
	return slow;
}
// ��������
Node * reverseList(Node *head) {
	...
}

bool chkPalindrome(Node* A) {
    Node *middle = findMiddle(A);
	Node *result = reverseList(middle);
	
	Node *c1 = A;
	Node *c2 = result;
	
	while (c1 != NULL && c2 != NULL) {
		if (c1->val != c2->val) {
			return false;
		}
		
		c1 = c1->next;
		c2 = c2->next;
	}
	
	return true;
}


/*
˼·��
1��������������ĳ���
2���ó������߼��������Ȳ
3��ͬʱ�����ߣ�ʲôʱ������ָ��ָ��ͬһ������ˣ���ʾ�ҵ��������
*/
int getLength(struct ListNode *head) {
	int length = 0;
	for (struct ListNode *cur = head; cur != NULL; cur = cur->next) {
		length++;
	}
	
	return length;
}

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    int lengthA = getLength(headA);
	int lengthB = getLength(headB);
	
	struct ListNode *longer = headA;
	struct ListNOde *shorter = headB;
	int diff = lengthA - lengthB;
	if (lengthB > lengthA) {
		longer = headB;
		shorter = headA;
		diff = lengthB - lengthA;
	}
	
	for (int i = 0; i < diff; i++) {
		longer = longer->next;
	}
	
	// ��ʹû�н���㣬��� longer �� shorter Ҳ��ͬʱ�ߵ� NULL
	// ����ѭ������������
	while (longer != shorter) {
		longer = longer->next;
		shorter = shorter->next;
	}
	
	return longer;
}











