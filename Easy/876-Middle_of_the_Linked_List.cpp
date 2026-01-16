class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* onestep = head;
        ListNode* twostep = head;

        while (twostep != NULL && twostep->next != NULL) {
            onestep = onestep->next;
            twostep = twostep->next->next;
        }

        return onestep;
    }
};
