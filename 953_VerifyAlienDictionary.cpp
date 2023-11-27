"""
In an alien language, surprisingly, they also use English lowercase letters, but possibly in a different order. The order of the alphabet is some permutation of lowercase letters.

Given a sequence of words written in the alien language, and the order of the alphabet, return true if and only if the given words are sorted lexicographically in this alien language.

Example 1:

Input: words = [hello,leetcode], order = hlabcdefgijkmnopqrstuvwxyz
Output: true
Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.

"""
class Solution {
public:
    unordered_map<char, int> ump;

       // checking if two words are lexicographically sorted
    bool checkOrder(string& a, string& b){
	int i = -1;
	while(++i < a.length() && i < b.length())
		if(ump[a[i]] != ump[b[i]]) 
            return ump[a[i]] < ump[b[i]];
	return size(a) <= size(b);
}
    
    bool isAlienSorted(vector<string>& words, string order) {        
	for(int i = 0; i <order.length(); i++) 
        ump[order[i]] = i;  // mapping letter to its corresponding index in order
	
    for(int i = 0; i < words.size() - 1; i++)
		if(!checkOrder(words[i], words[i + 1])) 
            return false;
	
    return true;          
        
    }
};