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
    
    ListNode* merge(ListNode* fun, ListNode* l)
    {
        ListNode* mer=new ListNode(5);
        ListNode* temp=mer;
        
        while(fun && l)
        {
            if(fun->val<l->val)
            {
                mer->next=fun;
                fun=fun->next;
            }

            else
            {
                mer->next=l;
                l=l->next;
            }

            mer=mer->next;
        }
        
        if(!l && fun)
            mer->next=fun;
        
        else
            mer->next=l;
        
        return temp->next;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
            int len=lists.size();     
        
            if(len==0)
                return NULL;
           
            ListNode *fun=lists[0];
         
            for(int i=1;i<len;i++)
                fun=merge(fun,lists[i]);
        
            return fun;
        
    }
};