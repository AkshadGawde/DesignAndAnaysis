class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;

        int og_num = x;
        long rev = 0;

        while (x > 0)
        {
            int digit = x % 10;
            // Check for overflow
            if (rev > (INT_MAX - digit) / 10)
                return false;
            rev = rev * 10 + digit;
            x /= 10;
        }

        return og_num == rev;
    }
};
