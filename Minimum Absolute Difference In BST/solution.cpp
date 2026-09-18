/* Binary Tree Node Structure
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; 
*/

class Solution {
private:
    int mini;
    int prev;
    void recur(Node* node){
        if(!node) return;
        if(node->left) recur(node->left);
        if(prev!=-1){
            mini = min(abs(prev-node->data),mini);
        }
        prev = node->data;
        if(node->right) recur(node->right);
    }
public:
    int absDiff(Node *root) {
        mini = INT_MAX;
        prev = -1;
        recur(root);
        return mini;
    }
};