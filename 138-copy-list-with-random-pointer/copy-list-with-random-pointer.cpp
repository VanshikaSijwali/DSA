/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL)
        {return head;}
        map<Node*,int>mp;
        map<int,Node*>mp2;
        Node* head2=new Node(head->val);
        Node*ptr2=head2;
        Node* ptr=head;
        ptr=ptr->next;
        mp[head]=1;
        mp2[1]=head2;
       int count=2;
        
        while(ptr!=NULL)
        {   
            mp[ptr]=count;
            Node* x=new Node(ptr->val);
            ptr2->next=x;
            mp2[count]=x;
            ptr2=ptr2->next;
            ptr=ptr->next;
            
            count++;

        }
        ptr=head,ptr2=head2;
        while(ptr!=NULL)
        {
            
            if(ptr->random!=NULL)
            {
                int pos=mp[ptr->random];
                Node* rand=mp2[pos];
                ptr2->random=rand;
            }
            ptr=ptr->next;
            ptr2=ptr2->next;
        }
        return head2;
        
    }
};