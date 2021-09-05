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
    
    ListNode* reverse(ListNode* head)     //function to reverse LinkList
    {
        ListNode* temp=NULL;
        while(head)
        {
            ListNode* t= head->next;
            head->next=temp;
            temp= head;
            head=t;
        }
        return temp;
    }
    
    bool isPalindrome(ListNode* head) {
        
        ListNode *fast= new ListNode(4), *slow= new ListNode(5);
        slow->next= head, fast->next= head;
        
        ListNode* temp= head;
        
        while(fast->next && fast->next->next)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        
        slow= reverse(slow->next);
        
        while(slow)
        {
            if(slow->val!=temp->val)
                return false;
            
            cout<<slow->val;
            slow=slow->next;
            temp=temp->next;
        }
        return true;
    }
};