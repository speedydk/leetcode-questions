class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int>que;
    priority_queue<int, vector<int>, greater<int>>erf;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(que.empty() || que.top()>=num)
            que.push(num);
        
        else
            erf.push(num);
        
        if(que.size()>erf.size()+1)
        {
            erf.push(que.top());
            que.pop();
        }
        
        else if(erf.size()>que.size()+1)
        {
            que.push(erf.top());
            erf.pop();
        }
    }
    
    double findMedian() {
        double ans;
        
        if(que.size() == erf.size())
            return (que.top() + erf.top())/(2*1.0);
        
        else
            return que.size()>erf.size() ? que.top() * 1.0 : erf.top() * 1.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */