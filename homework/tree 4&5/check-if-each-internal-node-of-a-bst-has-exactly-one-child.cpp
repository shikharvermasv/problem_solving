// class Solution {
// public:
//     bool check(TreeNode* root){
//       if(root == NULL){
//         return false;
//       }
//       while(root->left != NULL || root->right != NULL){
//         if(root->left && root->right){
//           return false;
//         }
//       }
//       return true;
//     }
// }

uper wala approach mene function let karke kara hai
now doing the compiler wala solution

#include<bits/stdc++.h>
using namespace std;
bool hasOnlyOneChild(vector<int>bst , int n){
    int first, last;

	for (int i=0; i<n-1; i++)
	{
		first = bst[i] - bst[i+1];
		last = bst[i] - bst[n-1];
		if (first*last < 0)
			return false;;
	}
	return true;
}

int main(){
    int n;
	cout << "Enter the number of nodes you want in the tree: ";
	cin >> n;
	
	vector<int>bst;
	cout << "Enter the nodes of the tree: ";

	for(int i=0; i<n; i++) {
		int a;
		cin>>a;
		bst.push_back(a);
    }

	if (hasOnlyOneChild(bst, n) == true )
		cout<<"Yes";
	else
		cout<<"No";
	return 0;
}
