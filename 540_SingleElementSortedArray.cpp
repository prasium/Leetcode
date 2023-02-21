class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1)
        return nums[0];

        int left = 0, right = nums.size()-1;
        int mid;

        if(nums[0]!=nums[1])
        return nums[0];

        if(nums[right]!=nums[right-1])
        return nums[right];
        
        while(left<=right)
        {
            mid = left+(right-left)/2;
            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1])
            return nums[mid];
            if((nums[mid]==nums[mid+1] && mid%2==0) || (nums[mid]==nums[mid-1] && mid%2!=0))
            {
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        return nums[left];
    }
};