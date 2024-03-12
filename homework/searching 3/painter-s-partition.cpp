bool ispossible(vector<int> &boards, int k, int mid){
    int paitCount=1;
    int boardsum =0;
    for(int i=0;i<boards.size();i++){
        if(boardsum+boards[i]<=mid){
          boardsum +=boards[i];
        }
        else{
             paitCount++;
            if( paitCount> k||boards[i]>mid){
                return false;
            }
        boardsum =boards[i];
        }
    }
    return true;
}


int findLargestMinDistance(vector<int> &boards, int k)
{
   int s=0;
   int sum =0;
   int ans=-1;
   for(int i=0;i<boards.size();i++){
       sum+= boards[i];
   } 
   int e=sum;
   int mid= s-(e-s)/2;
   while(s<=e){
       if (ispossible(boards, k, mid)) {
            ans= mid;
            e = mid - 1;   
       }
       else{
           s=mid+1;
       }
       mid = s+(e-s)/2;
   }
   return ans;
}
