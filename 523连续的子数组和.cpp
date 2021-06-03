#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        // 判断给定的nums长度是否小于2，若小于2则不满足要求
        int length = nums.size();
        if (length < 2)
        {
            return false;
        }
        unordered_map<int, int> hashmap;
        hashmap[0] = -1;
        int mod = 0;
        // pre_sum可以不用累加求出，因为取余后相加并不影响前缀和的余数
        // 对几个数的和取模，在求和的过程中随便多取几次模都无所谓，只要最后一次取模能够罩住所有的数，结果就依然不变。
        // int pre_sum = 0;
        for (int i = 0; i < length; i++)
        {
            // pre_sum += nums[i];
            mod = (nums[i] + mod) % k;
            if (hashmap.count(mod))
            {
                int index = hashmap[mod];
                if (i - index >= 2)
                {
                    return true;
                }
            }
            else
            {
                hashmap[mod] = i;
            }
        }
        return false;
    }
};

int main()
{
    Solution solution;
    vector<int> nums1 = {23, 2, 4, 6, 7};
    int k1 = 6;
    cout << solution.checkSubarraySum(nums1, k1);
}