"""
You are given a nested list of integers nestedList. Each element is either an integer or a list whose elements may also be integers or other lists. Implement an iterator to flatten it.

Implement the NestedIterator class:

    NestedIterator(List<NestedInteger> nestedList) Initializes the iterator with the nested list nestedList.
    int next() Returns the next integer in the nested list.
    boolean hasNext() Returns true if there are still some integers in the nested list and false otherwise.

Input: nestedList = [[1,1],2,[1,1]]
Output: [1,1,2,1,1]
Explanation: By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,1,2,1,1].
"""
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    stack<vector<NestedInteger>::iterator> beg, End;// storing iterators of beginning and end of nested lists

    NestedIterator(vector<NestedInteger> &nestedList) {
        beg.push(begin(nestedList));
        End.push(end(nestedList));
    }
    
    int next() {
        return beg.top()++ -> getInteger();
    }
    
    bool hasNext() {
        while(size(beg))
        {
            auto top = beg.top();
         // If it is end of one of nested list, pop that list, so we can iterate over the next one
            if(beg.top()==End.top()){
                beg.pop();
                End.pop();
                continue;
            }
            if(top->isInteger())
                break;
            	// if top is not integer, then it is a list
		
            beg.top()++;
            beg.push(begin(top->getList()));
            End.push(end(top->getList()));
        }
        // true will only be returned when stack top holds iterator of next integer
    
    return size(beg);
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */