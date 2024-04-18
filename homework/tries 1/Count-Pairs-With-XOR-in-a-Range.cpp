class TrieNode{
public:
    int count;
    TrieNode* children[2]; //only for 0 and 1

    TrieNode(){
        count = 0;
        for(int i=0 ; i<2 ; i++){
            children[i] = NULL;
        }
    }
};

void insert(TrieNode *root, int N){
    TrieNode* node = root;

    for(int i=31 ; i>=0 ; i--){
        bool bits = (N) & (1 << i);
        if(node->children[bits] == NULL){
            node->children[bits] = new TrieNode();
        }
        node->children[bits]->count+= 1;
        node= node->children[bits];
    }
}

int cntSmaller(TrieNode * root, int N, int K) { 
    int cntPairs = 0; 
    for (int i = 31; i >= 0 && root; i--) {                                                    
        bool x = N & (1 << i); 
        bool y = K & (1 << i); 
        if (y == true) { 
            if(root->children[x]){
                cntPairs  += root->children[x]->count; 
            }
            root = root->children[1 - x]; 
        } 
        else{  
            root = root->children[x]; 
        } 
    } 
    return cntPairs; 
} 

int pairs(vector<int>arr, int n, int k){
    TrieNode *root = new TrieNode(); 
    int cntPairs = 0; 
    for(int i = 0;i < n; i++){ 
        cntPairs += cntSmaller(root, arr[i], k);
        insert(root, arr[i]); 
    } 
    return cntPairs; 
}

class Solution {
public:
    int countPairs(vector<int>& nums, int low, int high) {
        int n = nums.size(); 
	    return pairs(nums, n, high + 1) - pairs(nums, n, low);
    }
};
