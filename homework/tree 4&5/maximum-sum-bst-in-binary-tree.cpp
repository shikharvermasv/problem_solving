class nodeValue{
     public:
     int min;
     int max;
     int sum;
     nodeValue(int min,int max,int sum)
     {
         this->min=min;
         this->max=max;
         this->sum=sum;
     }
 };
class Solution {
public:
    int ans=0;
    int maxSumBST(TreeNode* root) {
        fun(root);
        return ans;
    }
    nodeValue fun(TreeNode* root)
    {
        if(root==NULL)
        return nodeValue(INT_MAX,INT_MIN,0);
        nodeValue l=fun(root->left);
        nodeValue r=fun(root->right);
        if(root->val>l.max && root->val<r.min)
        {
            ans=max(ans,root->val+l.sum+r.sum);
            return nodeValue(min(root->val,l.min),max(root->val,r.max),l.sum+root->val+r.sum);
        }
        return nodeValue(INT_MIN,INT_MAX,max(l.sum,r.sum));
    }

};
