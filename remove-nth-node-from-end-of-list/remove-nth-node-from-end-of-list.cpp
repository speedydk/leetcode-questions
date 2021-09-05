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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode *ptr= new ListNode(5);
        ptr->next= head;
        ListNode* s= ptr, *f=ptr;
        
        while(ptr->next)
        {
            ptr=ptr->next;
            n--;
            
            if(n<0)
                s= s->next;
        }
        
        s->next= s->next->next;
        return f->next;
    }
};