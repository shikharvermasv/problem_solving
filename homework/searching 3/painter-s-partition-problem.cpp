int blackbox(vector<int> nums , int k , int mid){
    int count=1;
    int sum=0;

    for(int i=0 ; i<nums.size() ; i++){
        if(sum+nums[i]<=mid){
            sum+=nums[i];
        }
        else{
            count++;
            if( count>k || nums[i]>mid){
                return false;
            }
            sum = nums[i];
        }
    }
    return true;
}

int findLargestMinDistance(vector<int> &nums, int k)
{
    //    Write your code here.
    int low=0;
    int sum=0;
    int ans=-1;
    for(int i=0 ; i<nums.size() ; i++){
        sum+=nums[i];
    }
    int high = sum;
    int mid=low+(high-low)/2;
    while(low<=high){
        if(blackbox(nums,k,mid)){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
        mid=low+(high-low)/2;
    }
    return ans;
}
