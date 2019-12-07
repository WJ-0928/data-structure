struct ListNode* reverseList(struct ListNode* head){
	struct ListNode *resultHead = NULL;
	struct ListNode *cur = head;
	while (cur != NULL) {
		struct ListNode *next = cur->next;

		// ͷ��
		cur->next = resultHead; // ���� cur->next
		resultHead = cur;

		// ��ѭ��������
		cur = next;
	}

	return resultHead;
}