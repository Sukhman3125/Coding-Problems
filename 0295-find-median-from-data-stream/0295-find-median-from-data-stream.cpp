class MedianFinder {
private:
    priority_queue<int> smallHalf;
    priority_queue<int, vector<int>, greater<int>> largeHalf;

    void handleFirstTwoInsertions(int& num) {
        if (smallHalf.empty()) { // first insertion in small
            smallHalf.push(num);
            return;
        }
        // 2nd insertion
        int prev = smallHalf.top();
        smallHalf.pop();
        smallHalf.push(min(num, prev));
        largeHalf.push(max(num, prev));
    }

    void handleEqualSized(int& num) {
        int lowerBound = smallHalf.top();
        int upperBound = largeHalf.top();
        if (num <= lowerBound)
            smallHalf.push(num);
        else if (num >= upperBound)
            largeHalf.push(num);
        else
            smallHalf.push(num); // either is fine in this case
    }

    void handleSmallMore(int& num) {
        int lowerBound = smallHalf.top();
        if (num >= lowerBound) {
            largeHalf.push(num);
            return;
        }
        smallHalf.pop();
        smallHalf.push(num);
        largeHalf.push(lowerBound);
    }
    void handleLargeMore(int& num) {
        int upperBound = largeHalf.top();
        if (num <= upperBound) {
            smallHalf.push(num);
            return;
        }
        largeHalf.pop();
        largeHalf.push(num);
        smallHalf.push(upperBound);
    }

public:
    void addNum(int num) {
        int m = smallHalf.size(), n = largeHalf.size();
        if (m + n < 2) {
            handleFirstTwoInsertions(num);
        } else if (m == n) {
            handleEqualSized(num);
        } else if (m < n) {
            handleLargeMore(num);
        } else {
            handleSmallMore(num);
        }
    }

    double findMedian() {
        int m = smallHalf.size(), n = largeHalf.size();
        if (m + n == 0)
            return 0;
        if (m > n)
            return smallHalf.top();
        if (n > m)
            return largeHalf.top();
        return (smallHalf.top() + largeHalf.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */