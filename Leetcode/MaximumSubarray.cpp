#include <vector>
#include <algorithm>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        return maxSubArrayHelper(nums, 0, nums.size() - 1);
    }
    
private:
    int maxSubArrayHelper(std::vector<int>& nums, int left, int right) {
        if (left == right) {
            return nums[left];
        }
        
        int mid = left + (right - left) / 2;
        int left_sum = maxSubArrayHelper(nums, left, mid);
        int right_sum = maxSubArrayHelper(nums, mid + 1, right);
        int cross_sum = maxCrossingSum(nums, left, mid, right);
        
        return std::max({left_sum, right_sum, cross_sum});
    }
    
    int maxCrossingSum(std::vector<int>& nums, int left, int mid, int right) {
        int left_sum = INT_MIN;
        int sum = 0;
        for (int i = mid; i >= left; --i) {
            sum += nums[i];
            left_sum = std::max(left_sum, sum);
        }
        
        int right_sum = INT_MIN;
        sum = 0;
        for (int i = mid + 1; i <= right; ++i) {
            sum += nums[i];
            right_sum = std::max(right_sum, sum);
        }
        
        return left_sum + right_sum;
    }
};
