vector<pair<int,int>> step = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

bool valid(int i  , int j , int A , int B){
    return i>0 && j>0 && i<=A && j<=B;
}

int Solution::knight(int A, int B, int C, int D, int E, int F) {
    queue<pair<int,int>>q;
    q.push({C,D});
    vector<vector<bool>> vis(A+1 , vector<bool> (B+1,false));
    vis[C][D] = true;
    
    int count = 0;
    while(!q.empty()){
        int n = q.size();
        count++;
        
        for(int i=0 ; i<n ; i++){
            auto temp = q.front();
            q.pop();
            
            if(temp.first == E && temp.second == F){
                return count-1;
            }
            
            for(int j=0 ; j<step.size() ; j++){
                int x = temp.first + step[j].first;
                int y = temp.second + step[j].second;
                
                if(valid(x,y,A,B) && vis[x][y] == false){
                    q.push({x,y});
                    vis[x][y] = true;
                }
            }
        }
    }
    return -1;
}
