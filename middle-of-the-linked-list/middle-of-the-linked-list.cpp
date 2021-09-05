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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow= new ListNode(5), *fast= new ListNode(5);
        slow->next= head, fast->next= head;
        
        while(fast && fast->next && fast->next->next)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        
        return slow->next;
    }
};