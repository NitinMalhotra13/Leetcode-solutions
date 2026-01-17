class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* onestep = head;
        ListNode* twostep = head;

        while (twostep != NULL && twostep->next != NULL) {
            onestep = onestep->next;
            twostep = twostep->next->next;
            if (twostep == onestep) return true;
        }
        return false;
    }   
};
