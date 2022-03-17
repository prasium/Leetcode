"""
Given an array of numbers arr, return true if the array can be rearranged to form an arithmetic progression. Otherwise, return false.

Example 1:
Input: arr = [3,5,1]
Output: true
Explanation: We can reorder the elements as [1,3,5] or [5,3,1] with differences 2 and -2 respectively, between each consecutive elements.

"""
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int d= abs(arr[0]-arr[1]);
        int n = arr.size();
        for(int i=1;i<n-1;i++)
        {
            int diff = abs(arr[i]-arr[i+1]);
            if(diff!=d)
                return false;
        }
        return true;
    }
};