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
    ListNode* removeZeroSumSublists(ListNode* head) {
        vector<int> arr;
        while(head){
            arr.push_back(head->val);
            head = head->next;
        }
        int n = arr.size();
        for(int i=0;i<n;i++){
            int sum = 0;
            for(int j=i;j<n;j++){
                sum += arr[j];
                if(sum == 0){
                    for(int k=i; k<=j;k++){
                        arr[k] = 0;
                    }
                    break;
                }
            }
        }
        head = new ListNode(0);
        ListNode* node = head;
        for(int i=0;i<n;i++){
            if(arr[i] != 0){
                node->next = new ListNode(arr[i]);
                node = node->next;
            }
        }
        return head->next;
    }
};