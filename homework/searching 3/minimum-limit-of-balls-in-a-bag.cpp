class Solution {
public:

    bool possible(vector<int>& nums,int mid ,int maxOperations){
        int count=0;
        for(int i=0; i<nums.size() ; ++i){
            count+=(nums[i]-1)/mid;
            if(count >maxOperations){
                return 0;
            }
        }
        return 1;
    }
    int minimumSize(vector<int>& nums, int op) {
        int high = *max_element(nums.begin() , nums.end());
        int low = 1;
        int ans=0;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(possible(nums,mid,op)){
                ans = mid;
                high=mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};
