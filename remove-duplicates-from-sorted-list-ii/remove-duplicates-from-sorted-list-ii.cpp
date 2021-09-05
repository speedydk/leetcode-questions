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
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(!head || !head->next)
            return head;
        
        ListNode* res= new ListNode(5);
        ListNode* ans= res;
        ListNode* slow= NULL;
        
        while(head)
        {
            slow= head;
            int count= 0;
            
            while(head && head->next && head->val == head->next->val)
            {
                head=head->next;
                count++;
            }
            
            if(count==0)
            {
                res->next= head;
                res= res->next;
            }
            
            head=head->next;
        }
        
        res->next= NULL;
        return ans->next;
    }
};