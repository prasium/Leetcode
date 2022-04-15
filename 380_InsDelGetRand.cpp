"""
Implement the RandomizedSet class:

    RandomizedSet() Initializes the RandomizedSet object.
    bool insert(int val) Inserts an item val into the set if not present. Returns true if the item was not present, false otherwise.
    bool remove(int val) Removes an item val from the set if present. Returns true if the item was present, false otherwise.
    int getRandom() Returns a random element from the current set of elements (it's guaranteed that at least one element exists when this method is called). Each element must have the same probability of being returned.

You must implement the functions of the class such that each function works in average O(1) time complexity.
Input
["RandomizedSet", "insert", "remove", "insert", "getRandom", "remove", "insert", "getRandom"]
[[], [1], [2], [2], [], [1], [2], []]
Output
[null, true, false, true, 2, true, false, 2]
"""
class RandomizedSet {
public:
    unordered_map<int, int> ump;
    vector<int> v;
    
    RandomizedSet() {
            
    }
    
    bool insert(int val) {
        if(ump.find(val)!=ump.end())
        {
            return false;
            }
        else{
            v.push_back(val);
            ump[val]=v.size()-1;
            return true;
        }
    }
    
    bool remove(int val) {
        if(ump.find(val)==ump.end())
            return false;
        else{
            int last = v.back();
            v[ump[val]] = v.back();
            v.pop_back();
            ump[last] = ump[val];
            ump.erase(val);
            return true;
            
        }
    }
    
    int getRandom() {
        return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */