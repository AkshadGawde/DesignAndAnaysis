#include <vector>
#include <unordered_set>

class Solution
{
public:
    std::vector<int> intersection(std::vector<int> &nums1, std::vector<int> &nums2)
    {
        std::unordered_set<int> set(nums1.begin(), nums1.end());
        std::vector<int> result;

        for (int num : nums2)
        {
            if (set.count(num))
            {
                result.push_back(num);
                set.erase(num); // Ensure uniqueness by removing the element from set
            }
        }

        return result;
    }
};
