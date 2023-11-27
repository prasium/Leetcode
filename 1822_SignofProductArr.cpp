"""
1822. Sign of the Product of an Array
There is a function signFunc(x) that returns:

    1 if x is positive.
    -1 if x is negative.
    0 if x is equal to 0.

You are given an integer array nums. Let product be the product of all values in the array nums.

Return signFunc(product).

Example 1:

Input: nums = [-1,-2,-3,-4,3,2,1]
Output: 1
Explanation: The product of all values in the array is 144, and signFunc(144) = 1

"""
class Solution {
public:
    int signFunc(int pro)
    {
        if(pro>0)
            return 1;
        else if(pro<0)
            return -1;
        return 0;
    }
    int arraySign(vector<int>& nums) {
        int pro=1;
        for(int i=0;i<nums.size();i++)
        {
            pro*=signFunc(nums[i]);
        }
        return pro;
    }
};