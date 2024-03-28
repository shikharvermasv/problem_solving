class Solution {
public:
    TreeNode* leastcommonacc(TreeNode* root , int start , int dest){
        if(root == NULL){
            return NULL;
        }
        if(root->val == start || root->val == dest){
            return root;
        }

        TreeNode* left = leastcommonacc(root->left , start , dest);
        TreeNode* right = leastcommonacc(root->right , start , dest);

        if(left != NULL && right != NULL){
            return root;
        }
        if(left != NULL){
            return left;
        }
        if(right != NULL){
            return right;
        }

        return NULL;
    }

    bool path(TreeNode* root , int key , string& p1){
        if(root == NULL){
            return false;
        }

        if(root->val == key){
            return true;
        }

        p1+='L';
        if(path(root->left , key , p1)){
            return true;
        }
        p1.pop_back();

        if(root->val == key){
            return true;
        }
        p1+='R';
        if(path(root->right , key , p1)){
            return true;
        }

        p1.pop_back();

        return false;
    }

    string getDirections(TreeNode* root, int start, int dest) {
        root = leastcommonacc(root , start , dest);
        string p1="";
        string p2="";

        path(root , start , p1);
        path(root , dest , p2);
        for(int i=0 ; i<p1.size() ; i++){
            p1[i]='U';
        }
        return p1+p2;
    }
};
   
