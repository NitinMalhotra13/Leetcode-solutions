class Solution {
public:
    ListNode* findNthNode(ListNode* temp, int k) {
        int cnt = 1;
        while (temp != NULL) {
            if (cnt == k) return temp;
            cnt++;
            temp = temp->next;
        }
        return temp;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || k == 0) return head;

        ListNode* tail = head;
        int len = 1;

        while (tail->next != NULL) {
            tail = tail->next;
            len++;
        }

        k = k % len;
        if (k == 0) return head;

        tail->next = head;

        ListNode* newLastNode = findNthNode(head, len - k);
        head = newLastNode->next;
        newLastNode->next = NULL;

        return head;
    }
};
