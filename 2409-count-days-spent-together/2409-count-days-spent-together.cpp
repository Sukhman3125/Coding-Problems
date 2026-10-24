class Solution {
private:
    // number of days before nth month (1-indexed) (1st element is dummy)
    static inline int prefMonth[13] = {0, 0, 31,  59,  90,  120, 151, 181, 212, 243, 273, 304, 334};
    int parseDate(string s) {
        int month = stoi(s.substr(0, 2));
        int day = stoi(s.substr(3, 2));
        return prefMonth[month] + day;
    }
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int arrA = parseDate(arriveAlice);
        int leaveA = parseDate(leaveAlice);
        int arrB = parseDate(arriveBob);
        int leaveB = parseDate(leaveBob);
        int arr = max(arrA, arrB);
        int leave = min(leaveA, leaveB);
        return max(leave-arr+1, 0);
    }
};