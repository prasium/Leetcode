"""
Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.
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
    ListNode* partition(ListNode* head, int x) {
        ListNode *beforeHead = new ListNode();
        ListNode *before = beforeHead;
        ListNode *afterHead = new ListNode();
        ListNode *after = afterHead;
        
        while(head!=NULL)
        {
            if(head->val< x){
                before->next = head;
                before = before->next;
            }else{
                after->next =head;
                after = after->next;
            }
            head = head->next;
        }
        after->next = NULL;
        before->next = afterHead ->next;
        return beforeHead->next;
    }
};