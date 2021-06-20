class Solution {
public:
    void int_to_roman(string &s, int &A)
{
    
    int quot=0;
    
    if(A>=1 && A<4)
    {
        quot=A/1;
        while(quot--)
           s=s+"I";
        A=A%1;
    }
    
    else if(A==4)
    {
        s=s+"IV";
        A=0;
        return;
    }
    
    else if(A>=5 && A<9)
    {
        s=s+"V";
        A=A%5;
        return;
    }
    
    else if(A==9)
    {
        s=s+"IX";
        A=A%9;
        return;
    }
    
    else if(A>=10 && A<40)
    {
        quot=A/10;
        while(quot--)
           s=s+"X";
        A=A%10;
    }
    
    else if(A>=40 && A<50)
    {
        s=s+"XL";
        A=A%40;
        return;
    }
    
    else if(A>=50 && A<90)
    {
        s=s+"L";
        A=A%50;
        return;
    }
    
    else if(A>=90 && A<100)
    {
        s=s+"XC";
        A=A%90;
        return;
    }
    
    else if(A>=100 && A<400)
    {
        quot=A/100;
        while(quot--)
           s=s+"C";
        A=A%100;
    }
    
    else if(A>=400 && A<500)
    {
        s=s+"CD";
        A=A%400;
        return;
    }
    
    else if(A>=500 && A<900)
    {
        s=s+"D";
        A=A%500;
        return;
    }
    
    else if(A>=900 && A<1000)
    {
        s=s+"CM";
        A=A%900;
        return;
    }
    
    else if(A>=1000)
    {
        quot=A/1000;
        while(quot--)
           s=s+"M";
        A=A%1000;
    }
    
}


string intToRoman(int A) {
    
    string s="";
    
    while(A)
        int_to_roman(s,A);
        
    return s;
    
}

};