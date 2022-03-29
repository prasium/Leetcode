"""
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, and /. Each operand may be an integer or another expression.

Note that division between two integers should truncate toward zero.

It is guaranteed that the given RPN expression is always valid. That means the expression would always evaluate to a result, and there will not be any division by zero operation.

 

Example 1:

Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9

"""
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if(tokens[0]=="+"||tokens[0]=="-"||tokens[0]=="*"||tokens[0]=="/")
            return -1;
        stack<int> s;
        s.push(stoi(tokens[0]));
        for(int i=0;i<tokens.size();i++)
        {
            string curr = tokens[i];
            if(curr=="+"||curr=="-"||curr=="*"||curr=="/")
            {
                int v1 = s.top();
                s.pop();
                int v2 = s.top();
                s.pop();
                int res;
                if(curr=="+")
                    res = v2+v1;
                else if(curr=="-")
                    res = v2-v1;
                else if(curr=="*")
                    res = v2*v1;
                else if(curr=="/")
                    res = v2/v1;
                s.push(res);
            }
            else{
                s.push(stoi(tokens[i]));
            }
        }
        return s.top();
    }
};