#include <vector>
using namespace std;
/*
动态规划入门问题
***sum[i]表示以nums[i-1]元素结尾的连续子序列的最大和***
通过比较nums[i]与前i-1长度的子序列的最大和的大小，来决定nums[i]单独一段还是加入前i-1长度的子序列
*/ 
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        vector<int> sum(nums.size() + 1);
        int res = nums[0];
        for (int i = 1; i <= nums.size(); i++)
        {
            sum[i] = max(sum[i - 1] + nums[i - 1], nums[i - 1]);
            res = res > sum[i] ? res : sum[i];
        }
        return res;
    }
};