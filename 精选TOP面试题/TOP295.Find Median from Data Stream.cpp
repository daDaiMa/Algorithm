class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        vector<int>v;     
    }
    
    void addNum(int num) {
       v.insert(upper_bound(v.begin(),v.end(),num),num);
    }
    
    double findMedian() {
       int len = v.size();
       if(len%2){
            return v[len/2];
       }
       return (v[len/2]+v[len/2-1])/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
