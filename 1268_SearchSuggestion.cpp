"""
You are given an array of strings products and a string searchWord.

Design a system that suggests at most three product names from products after each character of searchWord is typed. Suggested products should have common prefix with searchWord. If there are more than three products with a common prefix return the three lexicographically minimums products.

Return a list of lists of the suggested products after each character of searchWord is typed.
"""

class Trie{
    
    struct Node{
        bool isWord = false;
        vector<Node *> children{vector<Node *>(26,NULL)};
    } *Root, *curr;
    
    void dfsPrefix(Node *curr, string &word, vector<string> &res)
    {
        if(res.size()==3)
            return;
        if(curr->isWord)
            res.push_back(word);
        
        for(char c='a'; c<='z'; c++)
        {
            if(curr->children[c-'a']){
                word+=c;
                dfsPrefix(curr->children[c-'a'], word, res);
                word.pop_back();
            }
        }
    }
    public: 
    Trie(){
        Root = new Node();
    }
    
    void insert(string &s)
    {
        curr=Root;
        for(char &c: s){
            if(!curr->children[c-'a'])
                curr->children[c-'a']=new Node();
            curr= curr->children[c-'a'];
        }
        curr->isWord=true;
    }
    
    vector<string> getWordsStart(string &prefix){
        curr=Root;
        vector<string> res;
        for(char &c: prefix){
            if(!curr->children[c-'a'])
                return res;
            curr= curr->children[c-'a'];
        }
        dfsPrefix(curr, prefix, res);
        return res;
    }
};

class Solution {
public:
    
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie trie = Trie();
        vector<vector<string>> res;
        for(string &word: products)
            trie.insert(word);
        
        string prefix;
        for(char &c: searchWord){
            prefix+=c;
            res.push_back(trie.getWordsStart(prefix));
        }
        return res;
    }
};