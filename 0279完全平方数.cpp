#include <vector>
#include<iostream>
// const int INT_MAX;
using namespace std;

class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; i++)
        {
            // 使用INT_MAX来表示最大值，快速获取数组中的最小值
            int minn = INT_MAX;
            for (int j = 1; j * j <= i; j++)
            {
                minn = min(minn, dp[i - j * j]);
            }
            dp[i] = minn + 1;
        }
        return dp[n];
    }
};

int main(){
    int input = 0;
    Solution solution;
    cin >> input;
    cout << solution.numSquares(input) << endl;
    return 0;
}