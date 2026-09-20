class MedianFinder {
private:
    priority_queue<int> smallHalf;
    priority_queue<int, vector<int>, greater<int>> largeHalf;

public:
    void addNum(int num) {
        int m = smallHalf.size(), n = largeHalf.size();
        
        if (m + n == 0) {
            smallHalf.push(num);
            return;
        } 
        else if (m == n) {
            handleEqualSized(num);
        } 
        else if (m < n) {
            handleLargeMore(num);
        } 
        else {
            handleSmallMore(num);
        }

    }

    double findMedian() {
        int m = smallHalf.size(), n = largeHalf.size();
        if (m + n == 0) // no elements, so median 0
            return 0;
        
        // odd number of elements
        if (m > n)
            return smallHalf.top();
        if (n > m)
            return largeHalf.top();
        
        // even number of elements
        return (smallHalf.top() + largeHalf.top()) / 2.0;
    }

private:
    void handleEqualSized(int& num) {
        int lowerBound = smallHalf.top();
        int upperBound = largeHalf.top();
        
        if (num <= lowerBound)
            smallHalf.push(num);
        else if (num >= upperBound)
            largeHalf.push(num);
        else
            smallHalf.push(num);    // either is fine in this case

    }

    void handleSmallMore(int& num) {
        int lowerBound = smallHalf.top();
        if (num >= lowerBound) {    // the lesser size pq can accept the number
            largeHalf.push(num);
            return;
        }
        smallHalf.pop();            // since lesser size pq can't accept, we replace one element from larger
        smallHalf.push(num);
        largeHalf.push(lowerBound);
    }

    void handleLargeMore(int& num) {    // symmetrical to function above
        int upperBound = largeHalf.top();
        if (num <= upperBound) {
            smallHalf.push(num);
            return;
        }
        largeHalf.pop();
        largeHalf.push(num);
        smallHalf.push(upperBound);
    }
};