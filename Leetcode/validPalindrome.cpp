#include <cctype>

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int left = 0, right = s.length() - 1;

        while (left < right)
        {
            // Skip non-alphanumeric characters and move left pointer
            while (left < right && !isalnum(s[left]))
                left++;

            // Skip non-alphanumeric characters and move right pointer
            while (left < right && !isalnum(s[right]))
                right--;

            // Convert characters to lowercase and compare
            if (tolower(s[left]) != tolower(s[right]))
                return false;

            // Move pointers towards the center
            left++;
            right--;
        }

        // If the loop completes without returning false, the string is a palindrome
        return true;
    }
};
