"""
You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: l1 = [7,2,4,3], l2 = [5,6,4]
Output: [7,8,0,7]
"""
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1,s2;
        int carry = 0, first, second;
        while(l1)
        {
            s1.push(l1->val);
            l1=l1->next;
        }
         while(l2)
        {
            s2.push(l2->val);
            l2=l2->next;
        }
        ListNode *head = NULL;
        while(!s1.empty()||!s2.empty()||carry)
        {
            if(!s1.empty())
            {
                first = s1.top();
                s1.pop();
            }
            else{
                first = 0;
            }
              if(!s2.empty())
            {
                second = s2.top();
                s2.pop();
            }
            else{
                second = 0;
            }
            int tem = first + second + carry;
            ListNode *temp = new ListNode(tem%10);
            temp->next = head;
            head = temp;
            carry = tem/10;
        }
        return head;
    }
};