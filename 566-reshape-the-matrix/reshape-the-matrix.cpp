class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int n=mat.size(),m=mat[0].size();
        if(m*n!=r*c)
        {return mat;}
        vector<vector<int>>newm(r,vector<int>(c,0));
        int v=r*c;
        for(int i=0;i<v;i++)
        {
            newm[i/c][i%c]=mat[i/m][i%m];

        }
        return newm;
        
    }
};