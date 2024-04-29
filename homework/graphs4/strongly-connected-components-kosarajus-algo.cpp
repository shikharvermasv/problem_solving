class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs(int i , vector<vector<int>>& adj , stack<int>& st , vector<int>& vis){
	    vis[i] = 1;
	    for(auto& j : adj[i]){
	        if(!vis[j]){
	            dfs(j , adj , st , vis);
	        }
	    }
	    st.push(i);
	}
	
	void dfs1(int i,vector<int> adjr[] , vector<int>& vis){
	    vis[i] = 1;
	    for(auto j : adjr[i]){
	        if(!vis[j]){
	            dfs1(j , adjr , vis);
	        }
	    }
	}
	
	
    int kosaraju(int v, vector<vector<int>>& adj)
    {
        //code here
        
        // storing the finishing time of thr array in the stack
        vector<int> vis(v , 0);
        stack<int> st;
        for(int i=0 ; i<v ; i++){
            if(!vis[i]){
                dfs( i , adj , st , vis);
            }
        }
        
        // reverse the graph for making it not able to traverse from one scc to another
        
        vector<int> adjr[v];
        for (int i = 0; i < v; i++) {
            vis[i] = 0;
            for (auto it : adj[i]) {
                adjr[it].push_back(i);
            }
        }
        
        // now traversing and counting the coponents
        int count=0;
        while(!st.empty()){
            int temp = st.top();
            st.pop();
            if(!vis[temp]){
                count++;
                dfs1(temp , adjr , vis);
            }
        }
        
        return count;
    }
};
