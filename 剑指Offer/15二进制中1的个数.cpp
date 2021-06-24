#include <iostream>
using namespace std;

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int count = 0;
        while (n)
        {
            count += (n & 1);
            n = n >> 1;
        }
        return count;
    }
};

int main()
{
    Solution solution;
    uint32_t a = 00011111;
    int out = solution.hammingWeight(a);
    cout << out << endl;
}