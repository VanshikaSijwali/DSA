class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        set<int>st;
        int i=0,j=0;
        vector<int>ans;
        int count=0;
        while(i<A.size())
        {
             if(A[i]==B[i]&&st.find(A[i])==st.end())
            {count++;
            st.insert(A[i]);
            }
            else
            
          {  if(st.find(A[i])!=st.end())
            {count++;}
            else
            {
                st.insert(A[i]);
            }
            if(st.find(B[j])!=st.end())
            {count++;}
            {
                st.insert(B[j]);
            }
           }
           ans.push_back(count);
           i++;
           j++;
        }
        return ans;
        
    }
};