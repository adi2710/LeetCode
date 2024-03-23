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
    
    ListNode* reverse(ListNode *cur)
    {
        ListNode *prev = nullptr;
        while(cur != nullptr)
        {
            ListNode *next = cur -> next;
            cur -> next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
    
    void reorderList(ListNode* head) {
        if(head == nullptr || head -> next == nullptr)
            return;
        ListNode *slow = head, *fast = head -> next;
        while(fast != nullptr && fast -> next != nullptr)
        {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        for(ListNode *l1 = head, *l2 = reverse(slow -> next); l1 != nullptr;)
        {
            auto temp = l1 -> next;
            l1 = l1 -> next = l2;
            l2 = temp;
        }
    }
};