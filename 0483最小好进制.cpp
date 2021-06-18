#include <string>
#include <cmath>
using namespace std;
/*
采用数学的方法进行设计
设n在k进制的位数为m+1
首先可以通过等比数列求和公式求得m<logk n
第二是可以由二项式定理求得k = ⌊ n的1/m次方⌋
*/ 
class Solution
{
public:
    string smallestGoodBase(string n)
    {
        long intn = stol(n);
        // 根据n的值求出m的取值上界，m越大，k的取值越小
        int mMax = floor(log(intn) / log(2));
        // 依次从m取值上界进行遍历，求出对应的k值
        for (int m = mMax; m > 1; m--)
        {
            int k = pow(intn, 1.0 / m);
            long mul = 1;
            long sum = 1;
            // 使用对应k值求解n
            for (int i = 0; i < m; i++)
            {
                mul *= k;
                sum += mul;
            }
            if (sum == intn)
            {
                return to_string(k);
            }
        }
        return to_string(intn - 1);
    }
};