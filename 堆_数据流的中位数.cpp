#include <vector>
#include <queue>
using namespace std;

class MedianFinder {
public:
    priority_queue<int, vector<int>, less<int>> minqueue;
    priority_queue<int, vector<int>, greater<int>> maxqueue;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (minqueue.empty() || num <= minqueue.top()) {
            minqueue.emplace(num);
            if (minqueue.size() > maxqueue.size() + 1) {
                maxqueue.emplace(minqueue.top());
                minqueue.pop();
            }
        }
        else {
            maxqueue.emplace(num);
            if (maxqueue.size() > minqueue.size()) {
                minqueue.emplace(maxqueue.top());
                maxqueue.pop();
            }
        }
    }
    
    double findMedian() {
        if (minqueue.size() > maxqueue.size()) return minqueue.top();
        return (minqueue.top() + maxqueue.top()) / 2.0;
    }
};
