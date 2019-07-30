class Solution {
public:
    vector<int>rad;
    vector<int>ori;
    Solution(vector<int>& nums) {
        copy(nums.begin(),nums.end(),rad.begin());
        copy(nums.begin(),nums.end(),ori.begin());
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return ori;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        int p1=rand()%ori.size();
        int p2=rand()%ori.size();
        swap(rad[p1],rad[p2]);
        return rad;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
