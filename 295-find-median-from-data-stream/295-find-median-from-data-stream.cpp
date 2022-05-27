class MedianFinder {
public:
    
    priority_queue<int> lows;
    priority_queue<int, vector<int>, greater<int>> highs;
    
    MedianFinder() {
        
    }
    
    void addNum(int val) {
        
      // deciding in which half val goes:
        if (lows.empty() || val < lows.top())
            lows.push(val);
        else 
            highs.push(val);
        
        // rebalancing to avoid higher becoming bigger
        if (lows.size() < highs.size())
        {
            lows.push(highs.top());
            highs.pop();
        }
        // or lows growing more than 1 element from the size of highs
        else if (lows.size() > highs.size() + 1)
        {
            highs.push(lows.top());
            lows.pop();
        }
    }
    
    double findMedian() {
        
        // computing the result depengn if we have seen odd amount of elements or not
        return lows.size() > highs.size() ? lows.top() : (lows.top() + highs.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */