class TrieNode{
public:
    bool isend;
    TrieNode* children[2]; //only for 0 and 1

    TrieNode(){
        isend = false;
        for(int i=0 ; i<2 ; i++){
            children[i] = NULL;
        }
    }
};

class Trie{
public:

    TrieNode* root = new TrieNode();

    void insert(int num){
        TrieNode* node = root;
        for(int i=31 ; i>=0 ; i--){
            int bits = (num>>i) &1;
            if(node->children[bits] == NULL){
                node->children[bits] = new TrieNode();
            }
            node= node->children[bits];
        }
        node->isend = false;
    }

    int check(int num){
        TrieNode* node = root;
        int ans = 0;

        for(int i = 31 ; i>=0 ; i--){
            int bits = (num>>i)&1;
            if(node->children[!bits]){    //ye isliye kar rahe hai jisse maximum mille 
                ans+= 1<<i;
                node=node->children[!bits];
            }
            else{
                node=node->children[bits];
            }
        }
        return ans;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie* root = new Trie();
        int maxi = INT_MIN;

        for(int i=0 ; i<nums.size() ; i++){
            root->insert(nums[i]);
        }

        for(int i=0 ; i<nums.size() ; i++){
            maxi = max(maxi , root->check(nums[i]));
        }

        return maxi;
    }
};
