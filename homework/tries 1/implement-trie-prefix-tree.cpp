// creating trie node
class Node{
public:
    Node* children[26];
    bool isend;
    Node(){
        isend = false;
        for(int i=0 ; i<26; i++){
            children[i] = NULL;
        }
    }
};
//creating class for trie
class Trie {
public:
    Node* root;
    / defining new trie node
    Trie() {
        root = new Node();
    }
    // inserung element in trie
    void insert(string s) {
        Node* temp = root;
        for(int i=0 ; i<s.size() ; i++){
            int ind = s[i] -'a';
            if(!temp->children[ind]){
                temp->children[ind] = new Node();
            }
            temp = temp->children[ind];
        }
        temp->isend = true;
    }
    
    bool search(string key , bool prefix=false){
        Node *temp = root;
        for (int i=0 ; i<key.size() ; i++) {
            int ind = key[i] - 'a';
            if (!temp->children[ind]) return false;
            temp = temp->children[ind];
        }
        if (prefix==false) return temp->isend;
        return true;
    }
    
    bool startsWith(string prefix) {
        return search(prefix , true);
    }
};
