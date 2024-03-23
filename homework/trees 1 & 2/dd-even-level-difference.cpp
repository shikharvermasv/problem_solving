class Solution{
  public:
    /*You are required to complete this function*/
    int getLevelDiff(Node *root)
    {
       //Your code here
       vector<int> ans ;
       queue<Node*> q;
       q.push(root);
       
       while(!q.empty()){
           int n=q.size();
           int sum=0;
            for(int i=0 ; i<n ; i++){
                Node* node= q.front();
                q.pop();
                if(node->left != NULL){
                    q.push(node->left);
                }
                if(node->right != NULL){
                    q.push(node->right);
                }
                sum+=(node-> data);
            }
            ans.push_back(sum);
       }
       // after we have store all the sum of the levels 
       int n1 = ans.size();
       int sum1=0;
       int sum2=0;
       for(int i=0 ; i<n1 ; i++){
           if(i%2 == 0){
               sum2 += ans[i];
           }
           if(i%2 ==1){
               sum1+=ans[i];
           }
       }
       return sum2-sum1;
       
    }
};
