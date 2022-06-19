"""
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.

 

Example 1:

Input: s = "()"
Output: true

"""

class Solution {
public:
    bool isValid(string s) {
        // Your code here
        stack<char> st;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='{'||s[i]=='('||s[i]=='[')
            {
                st.push(s[i]);
                continue;
            }
            // If current char is closing bracket then stack must be empty so return false
            if(st.empty())
            return false;
            char c = st.top();
            st.pop();
            if(s[i]==')')
         {
            if(c=='{'||c=='[')
            return false;
          }
        else if(s[i]=='}')
          {
            if(c=='('||c=='[')
            return false;
            
         }
        else if(s[i]==']')
         {
            
            if(c=='{'||c=='(')
            return false;
         }
        }
        return (st.empty());
    }

};
