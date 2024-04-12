class TrieNode{
public:

    bool isend;
    TrieNode* children[26];
    int count ;

    // constructor
    TrieNode(){
        isend = false;
        for(int i=0 ; i<26 ; i++){
            children[i] = NULL;
        }
        count = 0;
    }
};

class Trie{
public:

    TrieNode* root = new TrieNode();

    void insert(string s){
        TrieNode* node=root;

        for(int i=0 ; i<s.size() ; i++){
            if(node->children[s[i] - 'a'] == NULL){
                node->children[s[i] - 'a'] = new TrieNode();
            }
            node->children[s[i] - 'a'] -> count++;
            node = node->children[s[i] - 'a'];
        }
        node->isend = true;
    }

    int sum(string s){
        TrieNode* node = root;
        int ans=0;
        for(int i=0 ; i<s.size() ; i++){
            ans+=node->children[s[i] - 'a']->count;
            node=node->children[s[i] - 'a'];
        }
        return ans;
    }
};


class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie* root = new Trie();

        for(int i=0 ; i<words.size() ; i++){
            root->insert(words[i]);
        }
        vector<int> ans;
        for(int i=0 ; i<words.size() ; i++){
            ans.push_back(root->sum(words[i]));
        }

        return ans;
    }
};
