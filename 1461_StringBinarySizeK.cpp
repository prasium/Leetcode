"""
Given a binary string s and an integer k, return true if every binary code of length k is a substring of s. Otherwise, return false.

 

Example 1:

Input: s = "00110110", k = 2
Output: true
Explanation: The binary codes of length 2 are "00", "01", "10" and "11". They can be all found as substrings at indices 0, 1, 3 and 2 respectively.

"""
class Solution {
public:
    bool hasAllCodes(string s, int k) {
      int n = s.size(), sizeNeeded = 1 << k, count = 0; 
	bool set[sizeNeeded];
        memset(set, false, sizeof(set)); // initialising set of 'sizeNeeded' elements with false
	for(int i = 0; i <= n - k; i++){
		int hash = 0, shift = k - 1;
		for(int j = i; j < i + k; j++)
			hash += (s[j] - '0') << shift--; // hash will be equal to decimal value of substring
		if(!set[hash])
			set[hash] = true, count++;
	}
	return count == sizeNeeded;
    }
};
