#include <vector>
#include <numeric>
using namespace std;
class Solution
{
public:
    int lastStoneWeightII(vector<int> &stones)
    {
        // accumulate包括在numeric头文件中
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int m = sum / 2;
        vector<int> dp(m + 1);
        dp[0] = true;
        for (int weight : stones)
        {
            for (int j = m; j >= weight; --j)
            {
                dp[j] = dp[j] || dp[j - weight];
            }
        }
        for (int j = m;; --j)
        {
            if (dp[j])
            {
                return sum - 2 * j;
            }
        }
    }
};