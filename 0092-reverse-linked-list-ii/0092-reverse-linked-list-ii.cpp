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
private:
    struct nodes{
        ListNode *pref, *suff, *start, *end; 
    };
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* node = head;
        ListNode* prev = nullptr;
        nodes stored;
        for (int i = 1; node != nullptr; i++) {
            if (i == left){
                stored.pref = prev;
                stored.start = node;
            }
            if (i == right){
                stored.end = node;
                stored.suff = node->next;
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
        stored.start->next = stored.suff;
        if (!stored.pref)
            return stored.end;
        stored.pref->next = stored.end;
        return head;
    }
};
