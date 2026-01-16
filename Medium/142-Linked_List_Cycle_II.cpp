class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL) return NULL;

        ListNode* oneStep = head;
        ListNode* twoStep = head;

        while (twoStep != NULL && twoStep->next != NULL) {
            oneStep = oneStep->next;
            twoStep = twoStep->next->next;

            if (oneStep == twoStep) {
                twoStep = head;
                while (twoStep != oneStep) {
                    twoStep = twoStep->next;
                    oneStep = oneStep->next;
                }
                return twoStep;
            }
        }
        return NULL;
    }
};
