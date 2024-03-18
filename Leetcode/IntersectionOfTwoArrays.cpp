// These lines include necessary header files for using vectors and unordered sets in C++.
#include <vector>
#include <unordered_set>

// This defines a class Solution with a member function intersection that takes two vectors nums1 and nums2 as input and returns a vector of integers.
class Solution
{
public:
    std::vector<int> intersection(std::vector<int> &nums1, std::vector<int> &nums2)
    {
        // This line initializes an unordered set set with the elements of nums1. It uses the range constructor of unordered_set to insert elements from nums1.
        std::unordered_set<int> set(nums1.begin(), nums1.end());

        // This line declares an empty vector result to store the intersection elements.
        std::vector<int> result;

        // This starts a loop that iterates over each element num in nums2.
        for (int num : nums2)
        {
            if (set.count(num))
            {
                // This condition checks if the element num exists in the set set.
                result.push_back(num);

                // If num exists in the set, it means it's an intersection element, so we push it back into the result vector.
                set.erase(num);
            }
        }
        // End of the loop.
        return result;
    }
};
