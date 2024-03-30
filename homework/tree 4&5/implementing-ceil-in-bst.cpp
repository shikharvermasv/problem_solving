int findCeil(Node* root, int input) {
    
    int res=-1;
    
    while(root!=NULL){
        if(root->data==input){
            return root->data;
        }
        
        if(root->data<input){
            root=root->right;
        }
        
        else{
            if(res==-1) res=root->data;
            else if(root->data-input<res-input)
            res=root->data;
            root= root->left;
        }
    }
    return res;
}
