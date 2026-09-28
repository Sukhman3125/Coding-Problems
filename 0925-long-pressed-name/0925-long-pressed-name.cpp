class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0, j = 0;
        int n = name.size(), m = typed.size();

        while (i < n) {
            if (j >= m) return false;

            if (name[i] == typed[j]) {
                i++;
                j++;
            } 
            else {
                if (j == 0 || typed[j] != typed[j - 1])
                    return false;
                j++;
            }
        }

        while (j < m) {
            if (typed[j] != name[n - 1])
                return false;
            j++;
        }

        return true;
    }
};