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
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* prev = nullptr;
        int n = 0;
        while (head) {
            ListNode* temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
            n++;
        }
        head = prev;
        vector<int> ans(n);
        stack<int> st;
        int i = 0;
        while (head) {
            while (!st.empty() && st.top() <= head->val)
                st.pop();

            ans[n - 1 - i] = st.empty() ? 0 : st.top();

            st.push(head->val);
            head = head->next;
            i++;
        }
        return ans;
    }
};