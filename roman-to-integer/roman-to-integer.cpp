class Solution {
public:
    int romanToInt(string A) {
    
    int n=0;
    
    unordered_map<char,int>nums={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
    
    for(int i=0;i<A.length();i++)
    {
        if(i+1<A.length() && nums[A[i]]<nums[A[i+1]])
        {
            n=n+nums[A[i+1]]-nums[A[i]];
            i++;
        }
        
        else
        n=n+nums[A[i]];
    }
    
    return n;
    
}

};