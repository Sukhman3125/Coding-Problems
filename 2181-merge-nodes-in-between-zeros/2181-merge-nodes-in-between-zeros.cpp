class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* prev_zero = head;
        ListNode* curr = head->next;

        while (curr != NULL) {
            if (curr->val == 0) {
                if(curr->next == NULL) {
                    prev_zero->next = NULL;
                    break;
                }
                prev_zero->next = curr;
                prev_zero = curr;
            } else {
                prev_zero->val += curr->val;
            }

            curr = curr->next;
        }
        return head;
    }
};