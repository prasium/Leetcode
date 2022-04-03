"""
he next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

    For example, the next permutation of arr = [1,2,3] is [1,3,2].
    Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
    While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.

Given an array of integers nums, find the next permutation of nums.

The replacement must be in place and use only constant extra memory.

 

Example 1:

Input: nums = [1,2,3]
Output: [1,3,2]

"""
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int partInd=-1,chngInd=-1;
        // find ind of partition number where the increasing trend breaks
        int n=nums.size();
        for(int i=n-1;i>0;i--)
        {
            if(nums[i-1]<nums[i])
            {
                partInd=i-1;
                break;
            }
        }
        // find ind of number greater than the part ind again right to left
        if(partInd!=-1)
        {
            
            for(int i=n-1;i>partInd;i--)
            {
                if(nums[i]>nums[partInd])
                {
                    chngInd = i;
                    break;
                }
            }
            //Swap nums at part and change index
            int temp = nums[partInd];
            nums[partInd]=nums[chngInd];
            nums[chngInd]=temp;
        }
        
        // Now reverse all the digit from next ind of partition index till end;
        int start = partInd+1, end =n-1;
        while(start<end){
            int temp = nums[start];
            nums[start]=nums[end];
            nums[end]=temp;
            start++;
            end--;
        }
    }
};