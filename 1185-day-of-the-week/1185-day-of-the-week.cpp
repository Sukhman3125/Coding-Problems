class Solution {
private:
    long long leapYearsCnt(long long x, long long y) {
        auto f = [](long long n) {
            return n / 4 - n / 100 + n / 400;
        };

        return f(y - 1) - f(x - 1);
    }

public:
    string dayOfTheWeek(int day, int month, int year) {
        vector<int> days = {
            31, 28, 31, 30, 31, 30,
            31, 31, 30, 31, 30, 31
        };

        long long currDay = 5; // Jan 1, 1971 = Friday

        currDay = (currDay + 365 * (year - 1971)) % 7;
        currDay = (currDay + leapYearsCnt(1971, year)) % 7;

        for (int m = 1; m < month; m++) {
            currDay += days[m - 1];
        }

        if (month > 2 && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))) {
            currDay++;
        }

        currDay += day - 1;

        vector<string> week = {
            "Sunday", "Monday", "Tuesday", "Wednesday",
            "Thursday", "Friday", "Saturday"
        };

        return week[currDay % 7];
    }
};