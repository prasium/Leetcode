"""
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

 

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

"""
class Solution {
public:
    unordered_map<int,string> mp;
    
    vector<string> letterCombinations(string digits) {
        mp[2]="abc";
        mp[3]="def";
        mp[4]="ghi";
        mp[5]="jkl";
        mp[6]="mno";
        mp[7]="pqrs";
        mp[8]="tuv";
        mp[9]="wxyz";
        vector<string> res;
        if(digits.empty())
            return res;
    
        res.push_back(""); // intial state 
       
        for(int i=0; i<digits.length(); i++)
        {
            vector<string> t;
            for(auto c : mp[digits[i]-'0'])  // iterate each char
            {
                for(auto ele: res)
                {
                    t.push_back(ele+c);
                }
            }
            res.swap(t);
        }
        return res;
    }
};