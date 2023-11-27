"""
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
"""
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        // Two ptrs left and right to keep track of length
        int left = 0, right = n-1;
        int area = 0;
        
        while(left<right)
        {
            // breadth would be minimum of height to form a container
            int breadth = min(height[left], height[right]);
            // length is diff b/w right and left ptr
            int length = right - left;
            // Area is evaluated
            int ar = breadth * length;
            // We need max area
            area = max(ar, area);
            // If height left ptr is less than right increase left ptr
            if(height[left]<height[right])
                left++;
            else 
            // If height right ptr is less than left decrease right ptr
            if(height[right]<height[left])
                right--;
            else
            {
                left++;
                right--;
            }
        }
        return area;
    }
};