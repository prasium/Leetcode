"""
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

 

Example 1:

Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".

"""
class Solution {
public:
    int longestValidParentheses(string s) {
    int longest = 0;  	
    stack<int> st;
	st.push(-1); // bottom of stack will always hold index preceding to potential start of valid parentheses
	
        for(int i = 0; i < s.length(); i++)
		if(s[i] == '(')
            st.push(i);            
		else{                
			st.pop();
			if(st.empty())
                st.push(i);
			else 
                longest = max(longest, i - st.top());
		}        
	    return longest;
    }
};