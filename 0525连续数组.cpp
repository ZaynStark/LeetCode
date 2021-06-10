#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;
/*
仍然考虑前缀和，利用前缀和
当nums[i]=1时加一，当nums[i]=0时减一
利用哈希表保存前缀和信息
若出现了与哈希表中保存的相同值的前缀和，则说明中间是一个0和1数量相等的连续数组
*/ 
class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        int MaxLength = 0;
        int sum = 0;
        unordered_map<int, int> hashmap;
        hashmap[0] = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                sum++;
            }
            else
            {
                sum--;
            }
            if (hashmap.count(sum))
            {
                int index = hashmap[sum];
                if (i - index >= 2)
                {
                    MaxLength = max(i - index, MaxLength);
                }
            }
            else
            {
                hashmap[sum] = i;
            }
        }
        return MaxLength;
    }
};