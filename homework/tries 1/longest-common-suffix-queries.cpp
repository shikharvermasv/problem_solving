//declare the trie node
class TrieNode{
public:
    bool isend;
    TrieNode* children[26];
    int mini;
    int ind;

    TrieNode(){
        isend = false;
        for(int i=0 ; i<26 ; i++){
            children[i]=NULL;
        }
        mini = INT_MAX;
        ind = INT_MAX;
    }    
};
// we will make trie class for the inserion and searchini process
class Trie{
public:
    TrieNode* root = new TrieNode();
    void insert(string word , int index){
        TrieNode* node = root;
        for(int i=0 ; i<word.size() ; i++){
            if(node->children[word[i] - 'a'] == NULL){
                node->children[word[i] - 'a'] = new TrieNode();
            }

            if(word.size() < node->children[word[i] - 'a'] -> mini){
                node->children[word[i] - 'a'] -> mini = word.size();
                node->children[word[i] - 'a'] -> ind = index; 
            }
            node = node->children[word[i] - 'a'];
        }
        node->isend = true;
    }

    //searching 

    int search(string word){
        TrieNode *node = root;
        for(int i=0 ; i<word.size() ; i++)
        {   
            if(node->children[word[i] - 'a']!=NULL)
            {
                node = node->children[word[i] - 'a'];
            }
            else
            {
                return node->ind;
            }
        }
        return node->ind ;
    }
};

class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        Trie* root = new Trie();

        int mins = INT_MAX;
        int x = -1;
        for(int i=0 ; i < wordsContainer.size() ; i++){
            if(wordsContainer[i].size() < mins){
                mins = wordsContainer[i].size();
                x=i;
            }
            reverse(wordsContainer[i].begin() , wordsContainer[i].end());
            root->insert(wordsContainer[i],i);
        }
        vector<int> ans;
        for(int i=0 ; i<wordsQuery.size() ; i++){
            reverse(wordsQuery[i].begin() , wordsQuery[i].end());
            if(root->search(wordsQuery[i]) == INT_MAX){
                ans.push_back(x);
            }
            else{
                ans.push_back(root->search(wordsQuery[i]));
            }
        }
        return ans;
    }
};
