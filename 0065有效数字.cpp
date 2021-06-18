#include <string>
#include <regex>
#include<iostream>
using namespace std;

class Solution
{
public:
    static const regex pattern;
    bool isNumber(string s)
    {
        return regex_match(s, pattern);
    }
};
const regex Solution::pattern("[+-]?(?:\\d+\\.?\\d*|\\.\\d+)(?:[Ee][+-]?\\d+)?");
int main()
{
    string s = "123456";
    Solution solution;
    cout << solution.isNumber(s);
}