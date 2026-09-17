class Solution {
private:
    vector<bool> split(const string& preorder) {
        vector<bool> res;
        bool isNum = false;
        for (auto it : preorder) {
            if (it == '#')
                res.push_back(false); // false for null
            else if (it == ',') {
                if (isNum)
                    res.push_back(true); // true for node
                isNum = false;
            } else {
                isNum = true;
            }
        }
        if (isNum)
            res.push_back(true);
        return res;
    }

public:
    bool isValidSerialization(const string& preorder) {
        vector<bool> pre = split(preorder);
        stack<bool> st;
        for (bool b : pre) {
            st.push(b);

            while (st.size() >= 3) {
                bool right = st.top(); st.pop();
                bool left = st.top(); st.pop();
                bool node = st.top(); st.pop();
                if(node && !left && !right){        // valid node with 2 null children
                    st.push(false);
                    continue;
                }
                // revert
                st.push(node);
                st.push(left);
                st.push(right);
                break;
            }
        }
        return st.size() == 1 && !st.top();
    }
};