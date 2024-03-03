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
    
    ListNode* deleteNthNode(ListNode *head, int &n)
    {
        if(head == nullptr)
            return head;
        ListNode *newHead = deleteNthNode(head -> next, n);
        head -> next = newHead;
        n--;
        if(n == 0)
        {
            delete(head);
            return newHead;
        }
        return head;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        return deleteNthNode(head, n);
    }
};