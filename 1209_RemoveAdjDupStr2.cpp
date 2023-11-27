"""
1209. Remove All Adjacent Duplicates in String II
Medium

You are given a string s and an integer k, a k duplicate removal consists of choosing k adjacent and equal letters from s and removing them, causing the left and the right side of the deleted substring to concatenate together.

We repeatedly make k duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made. It is guaranteed that the answer is unique.

 

Example 1:

Input: s = "abcd", k = 2
Output: "abcd"
Explanation: There's nothing to delete.
"""
class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        for(int i=0; i<s.length(); i++)
        {
            if(st.empty()|| st.top().first!=s[i]){
            st.push({s[i],1});
            }
            else{
                st.push({s[i], st.top().second+1});
                if(st.top().second>=k)
                {
                    int i = st.top().second;
                    while(i--)
                    {
                        st.pop();
                    }
                }
            }
        }
        string res = "";
        while(!st.empty())
        {
            res+= st.top().first;
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};