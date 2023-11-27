"""
You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.
"""
class Solution {
public:
    int characterReplacement(string s, int k) {
        int len = s.length();
        int count[26] = {0};
        int start = 0, maxCount = 0, maxLength = 0;
        for (int end = 0; end < len; end++) {
            maxCount = max(maxCount, ++count[s[end] - 'A']);
            while (end - start + 1 - maxCount > k) {
                count[s[start] - 'A']--;
                start++;
            }
            maxLength = max(maxLength, end - start + 1);
        }
        return maxLength;
    }
};