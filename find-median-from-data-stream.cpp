class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }

    void addNum(int num) {
        if (small.size() == 0) {
            small.insert(num);
        } else if (*small.rbegin() >= num) {
            small.insert(num);
        } else {
            large.insert(num);
        }
        balance();
    }
    
    double findMedian() {
        if (small.size() == large.size()) {
            return (*small.rbegin() + *large.begin()) / 2.0;
        } else {
            return *small.rbegin();
        }
    }
    
    void balance() {
        if (small.size() > large.size() + 1) {
            auto num = *small.rbegin();
            small.erase(--small.rbegin().base());
            large.insert(num);
        } else if (large.size() > small.size()) {
            auto num = *large.begin();
            large.erase(large.begin());
            small.insert(num);
        }
    }

    multiset<int> small;
    multiset<int> large;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
