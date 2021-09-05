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
    
    ListNode* swap(ListNode* p, ListNode* q)
    {
        ListNode* temp= q->next;
        q->next= p;
        p->next= temp;
        return q;
    }
    
    ListNode* swapPairs(ListNode* head) {
        
        if(!head || !head->next)
            return head;
        
        ListNode* temp=new ListNode(5);
        ListNode* ptr= temp;
        temp->next= head;
        
        while(temp->next && temp->next->next)
        {
            temp->next=swap(temp->next,temp->next->next);
            temp=temp->next->next;
        }
        
        return ptr->next;
    }
};