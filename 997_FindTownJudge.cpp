"""
In a town, there are n people labeled from 1 to n. There is a rumor that one of these people is secretly the town judge.

If the town judge exists, then:

    The town judge trusts nobody.
    Everybody (except for the town judge) trusts the town judge.
    There is exactly one person that satisfies properties 1 and 2.

You are given an array trust where trust[i] = [ai, bi] representing that the person labeled ai trusts the person labeled bi.

Return the label of the town judge if the town judge exists and can be identified, or return -1 otherwise.

 

Example 1:

Input: n = 2, trust = [[1,2]]
Output: 2

"""

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        //Represents the total number of peoples in a town
        vector<int> trusted(n+1);
        
        //Whenever a person trust someone else than himself, the trusted value
        //of that person should be decreased since that person is not satisfying
        //the two conditions that were mentioned in the question.
        for(int i=0;i<trust.size();i++)
        {
            trusted[trust[i][0]]--;
            trusted[trust[i][1]]++;
        }
        
        //If a person is found with N-1 trusts than this person should be the judge
        for(int i=1; i<=n;i++)
        {
            if(trusted[i]==n-1)
                return i;
        }
        return -1;
    }
};