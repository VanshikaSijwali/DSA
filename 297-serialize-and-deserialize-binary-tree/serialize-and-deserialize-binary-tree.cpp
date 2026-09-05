/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s="";
        if(root==NULL)
        {return s+"#";}
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode*temp=q.front();
            q.pop();
            if(temp!=NULL)
            {q.push(temp->left);
            q.push(temp->right);
            s=s+to_string(temp->val);
            s=s+",";}
             else
             {
                s=s+"#,";

             }
        }
        
        return s;

        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
       int num=0;
       queue<TreeNode*>q;
        vector<TreeNode*>temp;
        bool neg=false;
        for(int i=0;i<data.size();i++)
        {  if(data[i]=='-')
        {neg=true;
        num=0;
        }
           
           else if(data[i]=='#')
            {temp.push_back(NULL);
            num=0;
            neg=false;
            i++;}
            else if(data[i]==',')
            {if(neg)
            {num=num*(-1);} 
                TreeNode* v=new TreeNode(num);
            temp.push_back(v);
                num=0;
                neg=false;
                }
                else
                {
                     num=(num*10)+data[i]-'0';
                     
                }

        }
        if(temp[0]==NULL)
        {return NULL;}
        int i=1;

        q.push(temp[0]);
        while(!q.empty()&&i<temp.size()-1)
        {
             TreeNode*ptr=q.front();
             q.pop();
             ptr->left=temp[i];
             if(temp[i]!=NULL)
             {q.push(temp[i]);
             }
             i++;

             ptr->right=temp[i];
             if(temp[i]!=NULL)
             {q.push(temp[i]);
             }
             i++;




        }
        return temp[0];

       


    
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));