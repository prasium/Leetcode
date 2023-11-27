"""
You are given a string s formed by digits and '#'. We want to map s to English lowercase characters as follows:

    Characters ('a' to 'i') are represented by ('1' to '9') respectively.
    Characters ('j' to 'z') are represented by ('10#' to '26#') respectively.

Return the string formed after mapping.

The test cases are generated so that a unique mapping will always exist.

Example 1:

Input: s = 10#11#12
Output: jkab
Explanation: j -> 10# , k -> 11# , a -> 1 , b -> 2.

"""
class Solution {
public:
    string freqAlphabets(string s) {
        int n = s.length(), i = 0;
        string ans = "";
        while(i < n)
            if(i + 2 < n && s[i + 2] == '#') {
                int sub = (s[i]-'0')*10 + (s[i+1]-'0');
                ans += char(sub+'a'-1);
                i += 3;
            }
            else {
                ans += char(s[i]-'0'-1+'a');
                i++;
            }
        return ans;    
    }
};