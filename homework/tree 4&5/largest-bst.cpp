class Solution{
    public:
    
    //haar root pe check karte hai ki wo bst hai ki nahi
    //if hai then number of node count kar ke return kar denge
    // max node return karenge
    
    int size(Node* root){
        if(!root){
            return 0;
        }
        return size(root->left) + size(root->right) +1;
    }
    
    bool isbst(Node* root , int mini , int maxi){
        if(!root){
            return true;
        }
        
        if(root->data <= mini || root->data >= maxi){
            return false;
        }
        
        return isbst(root->left , mini , root->data) && isbst(root->right , root->data , maxi);
    }
    
    int largestBst(Node *root)
    {
    	//Your code here
    	if(isbst(root , INT_MIN , INT_MAX)){
    	    return size(root);
    	}
    	
    	return max(largestBst(root->left) , largestBst(root->right));
    	
    }
};
