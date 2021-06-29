/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* A) {
        if(!A)
    return A;
    
    queue<Node*>que;
    que.push(A);
    Node* temp;
    
        while(!que.empty())
        {
            int len= que.size();

            for(int i=1; i<=len; i++)
            {
                temp= que.front();
                que.pop();

                if(i==len)
                temp->next= NULL;

                else
                temp->next= que.front();

                if(temp->left)
                que.push(temp->left);

                if(temp->right)
                que.push(temp->right);
            }
        }
        
        return A;

    }
};