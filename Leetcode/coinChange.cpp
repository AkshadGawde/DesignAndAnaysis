#include <vector>
#include <algorithm>

class Solution
{
public:
    int coinChange(std::vector<int> &coins, int amount)
    {
        // Initialization: Initialize dp array with all elements set to infinity
        std::vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0; // Base case: 0 coins needed to make up an amount of 0

        // Operation: Iterate over each coin denomination
        for (int coin : coins)
        {
            // Operation: Update dp[j] for each amount j starting from coin up to amount
            for (int j = coin; j <= amount; ++j)
            {
                if (dp[j - coin] != INT_MAX)
                {
                    dp[j] = std::min(dp[j], dp[j - coin] + 1);
                }
            }
        }

        // Result: Return dp[amount] if it's less than infinity, otherwise return -1
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};
