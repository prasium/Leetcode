"""
Given an integer num, return the number of steps to reduce it to zero.

In one step, if the current number is even, you have to divide it by 2, otherwise, you have to subtract 1 from it.

 

Example 1:

Input: num = 14
Output: 6
"""
class Solution {
public:
    int numberOfSteps(int num) {
        int steps = 0;
        while(num!=0)
        {
            num%2==0?num/=2 : num-=1;
        steps++;
        }
        return steps;
    }
};