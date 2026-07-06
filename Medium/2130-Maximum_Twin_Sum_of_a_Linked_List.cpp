class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode *onestep = head, *twostep = head;

        while (twostep && twostep->next) {
            onestep = onestep->next;
            twostep = twostep->next->next;
        }

        ListNode *prev = NULL;

        while (onestep) {
            ListNode *next = onestep->next;
            onestep->next = prev;
            prev = onestep;
            onestep = next;
        }

        int ans = 0;

        while (prev) {
            ans = max(ans, head->val + prev->val);
            head = head->next;
            prev = prev->next;
        }
        return ans;
    }
};
