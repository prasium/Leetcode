"""
Given an array of strings words and an integer k, return the k most frequent strings.

Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.
"""
class Solution {
private:
struct MyComp {
    bool operator() (const pair<int, string>& a, const pair<int, string>& b) {
        if(a.first != b.first) {
            return a.first > b.first;
        }
        else {
            return a.second < b.second;
        }
    }
};

    public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        unordered_map<string, int> ump;
        for(auto &word : words) {
            ump[word]++;
        }
        
        priority_queue<pair<int, string>, vector<pair<int, string>>, MyComp> pq;
        for(auto i = ump.begin(); i != ump.end(); i++) {
            pq.push(make_pair(i->second, i->first));
            if(pq.size() > k) 
                pq.pop();
        }
        
        vector<string> res;
        while(!pq.empty()) {
            res.insert(res.begin(), pq.top().second);
            pq.pop();
        }
        return res;
    }
};