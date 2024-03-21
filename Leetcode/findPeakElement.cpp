class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right)
        {
            int mid = left + (right - left) / 2;

            // Check if mid is a peak element
            if (nums[mid] > nums[mid + 1])
            {
                // If mid is greater than its right neighbor, potential peak to the left
                right = mid;
            }
            else
            {
                // If mid is not greater than its right neighbor, potential peak to the right
                left = mid + 1;
            }
        }

        // At the end of the loop, left and right pointers converge to the peak element
        return left;
    }
};
