class Solution {
public:
/*
Algorithm
1. Set ans = 0, subCount =0.
2. Iterate over input array, if num is not equal to 0 then set subCount =0.
3. Else increment subCount and add subCount to total Answer. 
*/ 
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0, subCount = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]!=0)
            {
                subCount = 0;
            }else{
                subCount++;
                ans+=subCount;
            }
        }
        return ans;
    }
};