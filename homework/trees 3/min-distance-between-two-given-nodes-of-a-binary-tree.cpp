class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    Node* lca(Node* root,int a,int b)
    {
          if(root==NULL)
          return root;
        if(root->data==a || root->data==b)
        {
            return root ;
        }
        
       Node* left=lca(root->left,a,b);
       Node* right=lca(root->right,a,b);
       
         if(left!=NULL && right!=NULL)
         return root;
         
         if(left!=NULL)
         return left;
         if(right!=NULL)
         return right;
             
         return NULL;
         
        
        
    }
    void disfind(Node* root,int &dis,int val)
    {
        int temp=0;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            
            
            int x=q.size();
            while(x--)
            {
                Node* cur=q.front();
                q.pop();
                if(cur->data==val)
                   {
                       dis=temp;
                       return ;
                   }
                   
                   if(cur->left)
                   q.push(cur->left);
                   if(cur->right)
                   q.push(cur->right);
            }
            temp++;
        }
    }
    int findDist(Node* root, int a, int b) {
        // Your code here
        Node* lc=lca(root,a,b);
        int disa=0,disb=0;
        disfind(lc,disa,a);
        disfind(lc,disb,b);
        
        return disa+disb;
       
    }
};
