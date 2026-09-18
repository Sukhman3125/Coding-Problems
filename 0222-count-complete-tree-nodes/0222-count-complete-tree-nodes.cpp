class Solution {
    bool exists(TreeNode* root, int idx, int h) {
        TreeNode* node = root;

        int bit = 1 << (h - 2);

        while (bit > 0) {
            if (idx & bit)
                node = node->right;
            else
                node = node->left;

            if (!node)
                return false;

            bit >>= 1;
        }

        return true;
    }

public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;

        int leftLvl = 0;
        TreeNode* node = root;

        while (node) {
            node = node->left;
            leftLvl++;
        }

        int rightLvl = 0;
        node = root;

        while (node) {
            node = node->right;
            rightLvl++;
        }

        if (leftLvl == rightLvl)
            return (1 << leftLvl) - 1;

        int h = leftLvl;

        int l = 0;
        int r = (1 << (h - 1)) - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (exists(root, mid, h))
                l = mid + 1;
            else
                r = mid - 1;
        }

        int lastLevelNodes = l;

        return (1 << (h - 1)) - 1 + lastLevelNodes;
    }
};