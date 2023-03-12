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
    struct compare{
        bool operator() (ListNode *l1, ListNode *l2)
        {
            return l1 -> val > l2 -> val;
        }
    };

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        for(ListNode *head : lists)
        {
            if(head != nullptr)
                pq.push(head);
        }
        ListNode *dummy = new ListNode(-1), *prev = dummy;
        while(!pq.empty())
        {
            ListNode *mn = pq.top();
            pq.pop();
            prev -> next = mn;
            prev = mn;
            if(mn -> next != nullptr)
                pq.push(mn -> next);
        }
        prev = dummy -> next;
        delete(dummy);
        return prev;
    }
};