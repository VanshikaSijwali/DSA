class Solution {
public:
 void solve(string &ans,int n)
 { if(n==0)
 {return;}
    int k=n;
    while(k>=10)
    {k=k/10;}
    if(k==9||k==4)
    {

        if(n>=900)
        {
            ans.push_back('C');
            ans.push_back('M');
            solve(ans,n-900);
        }
        else if(n>=400)
        {
            ans.push_back('C');
            ans.push_back('D');
            solve(ans,n-400);
        }
        else if(n>=90)
        {
            ans.push_back('X');
            ans.push_back('C');
            solve(ans,n-90);
        }
        else if(n>=40)
        {
            ans.push_back('X');
            ans.push_back('L');
            solve(ans,n-40);
        
        }
        else if(n>=9)
        {
            ans.push_back('I');
            ans.push_back('X');
            solve(ans,n-9);
        }
        else if(n>=4)
        {
            ans.push_back('I');
            ans.push_back('V');
            solve(ans,n-4);
        }

    }
    else
    {
        if(n>=1000)
        {
            ans.push_back('M');
            solve(ans,n-1000);
        }
        else if(n>=500)
        {
            ans.push_back('D');
            solve(ans,n-500);
        }
        else if(n>=100)
        {
            ans.push_back('C');
            solve(ans,n-100);
        }
        else if(n>=50)
        {
            ans.push_back('L');
            solve(ans,n-50);
        }
        else if(n>=10)
        {
            ans.push_back('X');
            solve(ans,n-10);
        
        }
        else if(n>=5)
        {
            ans.push_back('V');
            solve(ans,n-5);
        }
        else if(n>=1)
        {
            ans.push_back('I');
            solve(ans,n-1);
        }
    }


 }
    string intToRoman(int num) {
        int n=num;
        string ans="";
        solve(ans,n);
        return ans;
    }
};