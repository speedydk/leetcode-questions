class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(int i=0; i<tokens.size(); i++)
        {
            string ch= tokens[i];
            if(ch == "+" || ch == "-" || ch == "*" || ch == "/")
            {
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                
                if(ch == "+")
                    st.push(x+y);
                
                else if(ch == "-")
                    st.push(y-x);
                
                else if(ch == "*")
                    st.push(x*y);
                
                else
                    st.push(y/x);
                
                cout<<st.top()<<endl;
            }
            
            else
            {
                int x = stoi(ch);
                st.push(x);
                cout<<st.top()<<endl;
            }
        }
        return st.top();
    }
};