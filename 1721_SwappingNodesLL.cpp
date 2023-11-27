"""
You are given the head of a linked list, and an integer k.

Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).
Input: head = [1,2,3,4,5], k = 2
Output: [1,4,3,2,5]
"""
// Approach 1
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
    ListNode* swapNodes(ListNode* head, int k) {
        vector<int> arr;
        ListNode *temp = head;
        while(temp!=NULL)
        {
            arr.push_back(temp->val);
            temp=temp->next;
        }
        int n =arr.size();
        ListNode *newHead= head;
        //head=newHead;
        swap(arr[k-1],arr[n-k]);
        for(auto it= arr.begin(); it!= arr.end(); it++)
        {
            head->val = *it;
            head = head->next;
        }
        return newHead;
    }
};

// Approach 2
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
    ListNode* swapNodes(ListNode* head, int k) {
       ListNode* l = head, *r= head, *curr =head;
        int pos=1;
        while(curr!=NULL)
        {
            if(pos<k)
            {
                l=l->next;
            }
            if(pos>k)
            {
                r=r->next;
            }
            curr=curr->next;
            pos++;
        }
        //swap vals
        int temp = l->val;
        l->val = r->val;
        r->val = temp;
        return head;
    }
};