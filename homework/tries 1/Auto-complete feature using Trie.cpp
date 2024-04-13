#include<bits/stdc++.h>
using namespace std;


class TrieNode{
public:
	bool end;
	TrieNode * children[26];
	vector<string>prefix;
	
	TrieNode(){
		end = false;
		for(int i = 0;i<26;i++){
			children[i] = NULL;
		}
		for(int i=0 ; i<prefix.size() ; i++){
			prefix[i] = "";
		}
	}
};


void insert(TrieNode *root, string s){
	TrieNode *node = root;
	for(int i=0 ; i<s.size() ; i++){
		if(node->children[s[i]-'a']==NULL){
			node->children[s[i]-'a'] = new TrieNode();
		}
		node = node->children[s[i]-'a'];
		node->prefix.push_back(s);
	}
	node->end=true;
}

int main(){
	string names[] = { "hello", "dog", "hell", "cat", "a","hel","help","helps","helping"};
	TrieNode* root = new TrieNode();

	for(string n:names){
		insert(root, n);
	}
	TrieNode* node=root; 
	while(true){
		char ch;
		cout<<"enter char";
		cin>>ch;
		if(ch=='*')
		break;
		if(node->children[ch-'a']==NULL){
			cout<<"not found"<<endl;
			break;
		}
		node = node->children[ch-'a'];
		for(auto i:node->prefix){
			cout<<i<<" ";
		}
		cout<<endl;
		
	}
}
