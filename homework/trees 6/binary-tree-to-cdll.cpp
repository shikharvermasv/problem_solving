class Solution
{
  public:
    //Function to convert binary tree into circular doubly linked list.
    Node *inorder(Node* root , Node* &head , Node* &prev){
        if(root==NULL){
            return root;
        }
        inorder(root->left,head,prev);
        
        if(prev ==NULL){
            head = root;
        }
        else{
            root->left = prev;
            prev->right = root;
        }
        prev = root;
        inorder(root->right,head,prev);
        
        
        prev->right = head;
        head->left = prev;
        
        return head;
    }
    
    Node *bTreeToCList(Node *root)
    {
    //add code here.
        Node* prev = NULL;
        Node* head = NULL;
        return inorder(root , head , prev);
    }
};
