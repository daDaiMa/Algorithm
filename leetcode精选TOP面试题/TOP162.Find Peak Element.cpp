
class Solution {
public:
    int findPeakElement(vector<int> &nums) {
        int b = 0;
        int e = nums.size() - 1;
        while (true) {
            if (b == e) {
                break;
            }
            int mid = (b + e) / 2;
            if (nums[mid] > nums[mid + 1])
                e = mid;
            else
                b = mid + 1;
        }
        return e;
    }
};
