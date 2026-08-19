class Solution {
public:
    bool checkValidString(string s) {
        int  min=0,max=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {min++;
            max++;}
            else if(s[i]==')')
            {
                if(min==0)
                {
                    if(max==0)
                    {return false;}
                    else
                    {max--;}
                    
                }
                else
                {
                    min--;
                    max--;
                }
            }
            else
            {
                if(min!=0)
                
              {min--;}
                max++;
            }





        }
        return min==0;
        
    }
};