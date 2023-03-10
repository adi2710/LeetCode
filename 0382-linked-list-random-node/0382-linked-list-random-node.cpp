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
    ListNode *head;
    Solution(ListNode* head) {
        this -> head = head;
    }
    
    int getRandom() {
        int chosenValue = -1, i = 0;
        ListNode *tmp = head;
        while(tmp != nullptr)
        {
            i++;
            int random = rand() % i;
            if(random == i - 1)
                chosenValue = tmp -> val;
            tmp = tmp -> next;
        }
        return chosenValue;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */