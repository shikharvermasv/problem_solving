class Solution {
public:

    int isPossible(vector<int> &stalls,int mid){
        int arr=stalls[0];
        int count=1;
    
        for(int i=1;i<stalls.size();i++){
            if(abs(arr-stalls[i])<mid){
                continue;
            }
            else{
                arr=stalls[i];
                count++;
            }
        }
        return count;
    }


    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(),stalls.end());
        int low=1;
        int high=stalls[n-1]-stalls[0];
      
        while(low<=high){
            int mid=low+(high-low)/2;
            int cnt=isPossible(stalls,mid);
          
            if(cnt>=k){
                low=mid+1;
              
            }
            else{
                high=mid-1;
            }
        }
        return high;
    }
};
