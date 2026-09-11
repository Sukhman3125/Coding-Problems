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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* ans = new ListNode(0);
        ListNode* ansCpy = ans;
        head = head->next;
        int sum = 0;
        while(head != NULL){
            if(head->val == 0){
                ans->next = new ListNode(sum);
                ans= ans->next;
                sum = 0;
            }else{
                sum += head->val;
            }
            head= head->next;
        }
        ans = ansCpy->next;
        delete ansCpy;
        return ans;
    }
};