/* Structure of binary tree Node
class Node {
    public:
    int data;
    Node *left, *right;
    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    bool areAnagrams(Node* root1, Node* root2) {
        queue<Node*> q1;
        queue<Node*> q2;
        q1.push(root1);
        q2.push(root2);
        unordered_map<int, int> f;
        while(!q1.empty() || !q2.empty()){
            queue<Node*> next1;
            queue<Node*> next2;
            while(!q1.empty()){
                Node* curr = q1.front();
                q1.pop();
                f[curr->data]++;
                if(curr->left) next1.push(curr->left);
                if(curr->right) next1.push(curr->right);
            }
            while(!q2.empty()){
                Node* curr = q2.front();
                q2.pop();
                f[curr->data]--;
                if(f[curr->data] < 0) return false;
                if(f[curr->data] == 0) f.erase(curr->data);
                if(curr->left) next2.push(curr->left);
                if(curr->right) next2.push(curr->right);
            }
            if(!f.empty()) return false;
            q1 = next1;
            q2 = next2;
        }
        return true;
    }
};
