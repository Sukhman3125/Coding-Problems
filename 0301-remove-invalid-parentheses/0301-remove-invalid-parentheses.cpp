class Solution {
private:
    unordered_set<string> st;

    void recur(string& s, int i, string curr,
               int leftRemove, int rightRemove, int balance) {
        if (balance < 0 || leftRemove < 0 || rightRemove < 0)
            return;

        if (i == s.size()) {
            if (leftRemove == 0 && rightRemove == 0 && balance == 0)
                st.insert(curr);
            return;
        }

        char c = s[i];

        if (c == '(') {
            recur(s, i + 1, curr + c,
                  leftRemove, rightRemove, balance + 1);

            if (leftRemove > 0)
                recur(s, i + 1, curr,
                      leftRemove - 1, rightRemove, balance);
        }
        else if (c == ')') {
            recur(s, i + 1, curr + c,
                  leftRemove, rightRemove, balance - 1);

            if (rightRemove > 0)
                recur(s, i + 1, curr,
                      leftRemove, rightRemove - 1, balance);
        }
        else {
            recur(s, i + 1, curr + c,
                  leftRemove, rightRemove, balance);
        }
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        int leftRemove = 0;
        int rightRemove = 0;

        for (char c : s) {
            if (c == '(') {
                leftRemove++;
            }
            else if (c == ')') {
                if (leftRemove > 0)
                    leftRemove--;
                else
                    rightRemove++;
            }
        }

        recur(s, 0, "", leftRemove, rightRemove, 0);

        return vector<string>(st.begin(), st.end());
    }
};