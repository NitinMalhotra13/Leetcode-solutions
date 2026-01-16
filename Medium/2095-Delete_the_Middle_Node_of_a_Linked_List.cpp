class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (head == NULL || head->next == NULL) return NULL;

        ListNode* oneStep = head;
        ListNode* twoStep = head->next->next;

        while (twoStep != NULL && twoStep->next != NULL) {
            oneStep = oneStep->next;
            twoStep = twoStep->next->next;
        }
        oneStep->next = oneStep->next->next;
        return head;
    }
};
