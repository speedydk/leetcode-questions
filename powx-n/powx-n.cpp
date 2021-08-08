class Solution {
public:
    
    double powe(double x, int n)
    {
        //base condition
        if(n==0)
            return 1.0;
        
        else if(n==1)
            return x;
        
        double k= powe(x,n/2);
        if(n%2==0)
            return k*k;
        
        else
            return k*k*x;
    }
    
    double myPow(double x, int n) {
        
        if(x==0)
            return x;
        
        double k= powe(x,abs(n));
        return (n<0? 1/(k) : k);
        
    }
};