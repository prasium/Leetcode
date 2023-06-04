class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //points to 1st element
        int ptr1 = 1, ptr2 = 1;
        int counter = 1;
        for(ptr1; ptr1<nums.size(); ptr1++) {
            // if adjacent elements are equal increase counter
            if(nums[ptr1]==nums[ptr1-1]) {
                if(counter<2) {
                    counter++;
                    nums[ptr2++] = nums[ptr1]; 
                }
            } else {
                // For new element reset the counter to 1
                counter = 1;
                nums[ptr2++] = nums[ptr1];
            }
        }
        return ptr2;
    }
};