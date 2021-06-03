#include<vector>
#include<unordered_map>
#include<iostream>

using namespace std;
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int MaxLength = 0;
        int sum = 0;
        unordered_map<int,int> hashmap;
        hashmap[0]=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                sum++;
            }
            else{
                sum--;
            }
            if(hashmap.count(sum)){
                int index = hashmap[sum];
                if(i-index >= 2){
                    MaxLength=max(i-index,MaxLength);
                }
            }
            else{
                hashmap[sum] = i;
            }
        }
        return MaxLength;
    }
};