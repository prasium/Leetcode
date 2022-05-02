"""
Given an integer array nums, move all the even integers at the beginning of the array followed by all the odd integers.

Return any array that satisfies this condition.

 

Example 1:

Input: nums = [3,1,2,4]
Output: [2,4,3,1]
Explanation: The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.

"""
class Solution {
public:
    
   // Using Comparator
    static bool comp(int &a, int &b)
    {
        return a%2==0 && b%2!=0;
    }
    vector<int> sortArrayByParity(vector<int>& nums) {
        sort(nums.begin(), nums.end(), comp);
        return nums;
    }
    
    // Using two ptrs
   vector<int> sortArrayByParity(vector<int>& nums) {
    int l = 0, r= nums.size()-1;
        while(l<r){
            if(nums[l]%2!=0)
            {
                swap(nums[l], nums[r]);
                r--;
            }else{
                l++;
            }
            }
       return nums;
   }
};