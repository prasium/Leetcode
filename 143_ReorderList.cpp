"""
You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln

Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …

You may not modify the values in the list's nodes. Only nodes themselves may be changed.
Input: head = [1,2,3,4]
Output: [1,4,2,3]
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
    void reorderList(ListNode* head) {
        stack<ListNode*> s;
        ListNode *ptr = head;
        int size = 0; // size of list
        // Push all the nodes to stack
        while(ptr!=NULL)
        {
            s.push(ptr);
            ptr=ptr->next;
            size++;
        }
        
        ListNode *newHead = head;
        // Between every two nodes insert the one in the top of the stack
        for(int i = 0; i<size/2; i++)
        {
            ListNode *topEle = s.top();
            s.pop();
            topEle->next = newHead->next;
            newHead ->next =topEle;
            newHead = newHead->next->next;
        }
        newHead->next =NULL;
    }
};