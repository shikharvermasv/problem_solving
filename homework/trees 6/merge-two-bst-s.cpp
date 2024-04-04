class Solution
{
    public:
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    void inorder(Node* root , vector<int>& nums){
        if(root == NULL){
            return;
        }
        inorder(root->left , nums);
        nums.push_back(root->data);
        inorder(root->right , nums);
    }
    
    vector<int> merge(Node *root1, Node *root2)
    {
       //Your code here
       vector<int> nums1;
       vector<int> nums2;
       
       inorder(root1 , nums1);
       inorder(root2 , nums2);
       
    //   for(int i=0 ; i<nums2.size() ; i++){
    //       nums1.push_back(nums2[i]);
    //   }
    //   sort(nums1.begin() , nums1.end());
       int i=0 ;
       int j=0;
       vector<int> ans;
       while(i<nums1.size() && j<nums2.size()){
           
           if(nums1[i] == nums2[j]){
               ans.push_back(nums1[i]);
               ans.push_back(nums2[j]);
               i++; 
               j++;
           }
           else if(nums1[i] < nums2[j])
           {
               
               ans.push_back(nums1[i]);
               i++;
           }
           else{
               ans.push_back(nums2[j]);
               j++;
           }
       }
       
       while(i<nums1.size()){
            ans.push_back(nums1[i++]);
       }
       while(j<nums2.size()){
            ans.push_back(nums2[j++]);
       }
       
       return ans;
       
    //   return nums1;
    }
};
