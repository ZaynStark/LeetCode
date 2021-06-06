#include <vector>
using namespace std;

class Solution
{
public:
    vector<bool> canEat(vector<int> &candiesCount, vector<vector<int>> &queries)
    {
        // 初始化需要带上长度
        vector<long long> pre_sum(candiesCount.size());
        pre_sum[0] = candiesCount[0];
        for (int i = 1; i < candiesCount.size(); i++)
        {
            pre_sum[i] = pre_sum[i - 1] + candiesCount[i];
        }
        vector<bool> answer;
        // 记录一下const auto&x:range
        for (const auto &q : queries)
        {
            long long min = q[1] + 1;
            long long max = min * q[2];
            long long lowersum = (q[0] == 0 ? 1 : pre_sum[q[0] - 1] + 1);
            answer.push_back(!(lowersum > max || pre_sum[q[0]] < min));
        }
        for (int k = 0; k < queries.size(); k++)
        {
            long long min = queries[k][1] + 1;
            long long max = min * queries[k][2];
            long long lowersum = (queries[k][0] == 0 ? 1 : pre_sum[queries[k][0] - 1] + 1);
            answer.push_back(!(lowersum > max || pre_sum[queries[k][0]] < min));
        }
        return answer;
    }
};