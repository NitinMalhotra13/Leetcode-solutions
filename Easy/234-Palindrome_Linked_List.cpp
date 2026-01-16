class Solution {
public:
    ListNode* reverseLinkedList(ListNode* head) {
        ListNode* front = NULL;
        ListNode* temp = head;

        while (temp != NULL) {
            ListNode* newHead = temp->next;
            temp->next = front;
            front = temp;
            temp = newHead;
        }
        return front;
    }

    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) return true;

        ListNode* oneStep = head;
        ListNode* twoStep = head;

        while (twoStep->next != NULL && twoStep->next->next != NULL) {
            oneStep = oneStep->next;
            twoStep = twoStep->next->next;
        }
        ListNode* newHead = reverseLinkedList(oneStep->next);
        ListNode* first = head;
        ListNode* second = newHead;

        while (second != NULL) {
            if (first->val != second->val) {
                reverseLinkedList(newHead);
                return false;
            }
            first = first->next;
            second = second->next;
        }
        reverseLinkedList(newHead);
        return true;
    }
};
