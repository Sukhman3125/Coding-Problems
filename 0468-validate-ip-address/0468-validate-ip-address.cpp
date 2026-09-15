class Solution {
private:
    bool ipv4(string& s) {
        int parts = 0;
        int i = 0;
        while (i < s.size()) {
            if (!isdigit(s[i]))
                return false;
            if (s[i] == '0' && i + 1 < s.size() && isdigit(s[i + 1]))
                return false;
            int num = 0;
            int j = i;
            while (j < s.size() && isdigit(s[j])) {
                num = num * 10 + (s[j] - '0');

                if (num > 255)
                    return false;

                j++;
            }
            parts++;
            if (j < s.size() && s[j] != '.')
                return false;
            i = j + 1;
        }

        return parts == 4 && s.back() != '.';
    }

    bool ipv6(string& s) {
        if (s.front() == ':' || s.back() == ':')
            return false;

        stringstream ss(s);
        string part;
        int cnt = 0;

        while (getline(ss, part, ':')) {
            if (part.empty() || part.size() > 4)
                return false;

            for (char c : part) {
                if (!isdigit(c) && !(c >= 'a' && c <= 'f') &&
                    !(c >= 'A' && c <= 'F'))
                    return false;
            }

            cnt++;
        }

        return cnt == 8;
    }

public:
    string validIPAddress(string& s) {
        if(s=="") return "Neither";
        if (ipv4(s))
            return "IPv4";
        if (ipv6(s))
            return "IPv6";
        return "Neither";
    }
};