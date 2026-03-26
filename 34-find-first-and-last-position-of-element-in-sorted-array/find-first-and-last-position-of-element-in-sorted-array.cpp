class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findBound(nums, target, true);
        if (first == -1) return {-1, -1};  
        int last  = findBound(nums, target, false);
        return {first, last};
    }
private:
    int findBound(vector<int>& nums, int target, bool findLeft) {
        int lo = 0, hi = (int)nums.size() - 1, bound = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) {
                bound = mid;           
                if (findLeft) hi = mid - 1; 
                else          lo = mid + 1; 
            } else if (nums[mid] < target) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return bound;
    }
};