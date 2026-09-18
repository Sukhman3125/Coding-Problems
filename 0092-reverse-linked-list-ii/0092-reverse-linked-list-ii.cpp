/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* node = head;
        ListNode* prev = nullptr;
        ListNode* pref = nullptr;
        ListNode* suff = nullptr;
        ListNode* start = nullptr;
        ListNode* end = nullptr;
        for (int i = 1; node != nullptr; i++) {
            if (i == left){
                pref = prev;
                start = node;
            }
            if (i == right){
                end = node;
                suff = node->next;
            }

            if (i > left && i <= right) {
                ListNode* temp = node->next;
                node->next = prev;
                prev = node;
                node = temp;
                continue;
            }

            prev = node;
            node = node->next;
        }
        start->next = suff;
        if (!pref)
            return end;
        pref->next = end;
        return head;
    }
};
