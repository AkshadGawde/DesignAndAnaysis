// These lines include the necessary header files for using vectors and algorithms in C++.
#include <vector>
#include <algorithm>

// This declares a class Solution with a public member function maxSubArray. It takes a reference to a vector of integers nums as input and returns an integer.
class Solution
{
public:
    int maxSubArray(std::vector<int> &nums)
    {
        // This line calls the private member function maxSubArrayHelper with parameters nums, 0, and nums.size() - 1. It effectively initiates the divide and conquer process by passing the entire array nums and the indices representing the range.
        return maxSubArrayHelper(nums, 0, nums.size() - 1);
    }

    // This line defines a private member function maxSubArrayHelper. It takes a reference to a vector of integers nums and two integer parameters left and right, representing the indices of the subarray being considered.
private:
    int maxSubArrayHelper(std::vector<int> &nums, int left, int right)
    {
        // This checks if the subarray has only one element (left == right). If so, it returns that element.
        if (left == right)
        {
            return nums[left];
        }

        // This calculates the midpoint (mid) of the subarray and recursively calls maxSubArrayHelper for the left and right halves. Additionally, it calculates the maximum subarray sum that crosses the midpoint using the maxCrossingSum function.
        int mid = left + (right - left) / 2;
        int left_sum = maxSubArrayHelper(nums, left, mid);
        int right_sum = maxSubArrayHelper(nums, mid + 1, right);
        int cross_sum = maxCrossingSum(nums, left, mid, right);

        // This line returns the maximum of the left sum, right sum, and cross sum, which effectively gives the maximum subarray sum for the current subarray.
        return std::max({left_sum, right_sum, cross_sum});
    }

    // This defines the private member function maxCrossingSum, which calculates the maximum subarray sum that crosses the midpoint of the array.
    int maxCrossingSum(std::vector<int> &nums, int left, int mid, int right)
    {
        // This loop iterates from the midpoint towards the left, calculating the sum of elements and updating the maximum left sum.
        int left_sum = INT_MIN;
        int sum = 0;
        for (int i = mid; i >= left; --i)
        {
            sum += nums[i];
            left_sum = std::max(left_sum, sum);
        }

        // This loop iterates from the midpoint towards the right, calculating the sum of elements and updating the maximum right sum.
        int right_sum = INT_MIN;
        sum = 0;
        for (int i = mid + 1; i <= right; ++i)
        {
            sum += nums[i];
            right_sum = std::max(right_sum, sum);
        }

        return left_sum + right_sum;
    }
};
