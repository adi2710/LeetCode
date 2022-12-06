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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr)
            return head;
        ListNode *odd = new ListNode(), *even = new ListNode(), *temp = head, *temp1 = odd, *temp2 = even;
        int cnt = 1;
        while(temp != nullptr)
        {
            if(cnt & 1){
                temp1 -> next = temp;
                temp1 = temp1 -> next;
            }
            else{
                temp2 -> next = temp;
                temp2 = temp2 -> next;
            }
            temp = temp -> next;
            cnt++;
        }
        temp1 -> next = even -> next;
        temp2 -> next = nullptr;
        temp1 = odd, temp2 = even;
        odd = odd -> next;
        delete(temp1);
        delete(temp2);
        return odd;
    }
};