struct node{
    node* next[26];
    bool isWord;
    node()
    {
        for(int i=0;i<26;i++)
        {
            next[i]=NULL;
        }
        isWord=false;
    }
};

class trie{
    public:
    node* root;
    trie()
    {
        root=new node();
    }
    
    void insert(string word)
    {
        node* curr=root;
        for(int i=0;i<word.length();i++)
        {
            if(curr->next[word[i]-'a']==NULL)
            {
                curr->next[word[i]-'a']=new node();
            }
            curr=curr->next[word[i]-'a'];
        }
        curr->isWord=true;
    }
    
    
    void helper(vector<vector<char>>& board,int x,int y,node* curr,vector<string>&ans,string temp)
    {
        int n=board.size();
        int m=board[0].size();
        
        if(x<0 || y<0 || x>=n ||y>=m || board[x][y]=='#')
        {
            return;
        }
        
        if(curr->next[board[x][y]-'a']==NULL)
        {
            return ;
        }
        
        temp+=board[x][y];
        curr=curr->next[board[x][y]-'a'];
        if(curr->isWord)
        {
            ans.push_back(temp);
            curr->isWord=false;
        }
        char c = board[x][y];
        board[x][y] = '#';
        helper(board,x+1,y,curr,ans,temp);
        helper(board,x,y+1,curr,ans,temp);
        helper(board,x-1,y,curr,ans,temp);
        helper(board,x,y-1,curr,ans,temp);
        board[x][y]=c;
    }
    
    void search(vector<vector<char>>& board,int x,int y,vector<string>&ans)
    {
        node* curr=root;
        return helper(board,x,y,root,ans,"");
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        trie* obj=new trie();
        
        for(auto s:words)
        {
            obj->insert(s);
        }
        
        int n=board.size();
        if(n==0)
        {
            return {};
        }
        int m=board[0].size();
        
        vector<string> ans;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                obj->search(board,i,j,ans);
            }
        }
        return ans;
    }
};