"""
Given the head of a linked list, rotate the list to the right by k places.
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL)
            return head;
        int length = 1;
        ListNode *temp, *newHead;
        temp = newHead = head;
        // Find length
        while(temp->next)
        {
            temp=temp->next;
            length++;
        }
        
        temp->next = head;
          if(k %= length) 
        {
            for(auto i=0; i<length-k; i++) 
                temp = temp->next; // the tail node is the (len-k)-th node (1st node is head)
        }
        newHead = temp->next; 
        temp->next = NULL;
        return newHead;
    }
};