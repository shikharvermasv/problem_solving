class TrieNode{
public:
    bool isend;
    TrieNode* children[26];
    //constructor for the trieNode
    TrieNode(){
        isend = false;
        for(int i=0 ; i<26 ; i++){
            children[i] = NULL;
        }
    }
};

class Trie{
public:
    TrieNode* root = new TrieNode();
    void insert(string word){
        TrieNode* node = root;
        for(int i=0 ; i<word.size() ; i++){
            if(node->children[word[i] - 'a'] == NULL){
                node->children[word[i] - 'a'] = new TrieNode();
            }
            node = node->children[word[i] - 'a'];
        }
        node->isend = true;
    }

    string search(string word){
        TrieNode *node = root;
        if(node->children[word[0]-'a']==NULL)
            return word;

        string ans = "";
        for(auto i: word){
            if(node->isend==true){
                break;
            }
            if(node->children[i-'a']== NULL){
                return word;
            }
            ans += i;
            node = node->children[i-'a'];
        } 
        return ans;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie* root = new Trie();

        for(int i= 0;i<dictionary.size();i++){
            root -> insert(dictionary[i]);
        }

        string word;
        istringstream iss(sentence);
        string ans = "";
        while(getline(iss,word,' ')){
            ans = ans +root->search(word) + " "; 
        }
        ans.pop_back();
        return ans;
    }
};
