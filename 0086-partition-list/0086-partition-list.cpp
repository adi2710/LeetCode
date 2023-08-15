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
        ListNode *fast = head;
        head = new ListNode(0, head);
        ListNode *slow = head, *prev = slow;
        while(fast != nullptr)
        {
            // cout << slow -> val << ' ' << fast -> val <<endl;
            ListNode *nxt = fast -> next;
            if(fast -> val < x)
            {
                if(fast != slow -> next){
                    fast -> next = slow -> next;
                    prev -> next = nxt;
                }
                slow -> next = fast;
                slow = slow -> next;
            }
            else
                prev = fast;
            fast = nxt;
        }
        return head -> next;
    }
};