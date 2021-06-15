#include <vector>
using namespace std;

class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int result = 0;
        int left = 0;
        int right = arr.size() - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (arr[mid] < arr[mid - 1] && arr[mid] > arr[mid + 1])
            {
                right = mid;
            }
            else if (arr[mid] > arr[mid - 1] && arr[mid] < arr[mid + 1])
            {
                left = mid + 1;
            }
            else
            {
                result = mid;
                break;
            }
        }
        return result;
    }
};

int mian()
{
    Solution solution;
}