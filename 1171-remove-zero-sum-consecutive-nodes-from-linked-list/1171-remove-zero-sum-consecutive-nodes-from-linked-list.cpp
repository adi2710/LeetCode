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
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int, ListNode*> mp;
        ListNode* x = new ListNode(-1);
        mp[0] = x;
        x->next = head;
        ListNode* h = x->next, *ans = x;
        int s = 0;
        while (h)
        {
            s += h->val;
            if (mp.find(s) != mp.end())
            {
                ListNode* a = mp[s]->next;
                mp[s]->next = h->next;
                int q = s;
                while (a != h)
                {
                    q += a->val;
                    mp.erase(q);
                    ListNode* t = a;
                    a = a->next;
                }
            }
            else
                mp[s] = h;
            h = h->next;
        }
        ListNode *tmp = ans -> next;
        return ans->next;
    }
};