class Solution {
public:
    int first_pos(vector<int>nums , int target){
        int ans=-1;
        int low=0;
        int high=nums.size()-1;
        int mid=low+(high-low)/2;
        while(low<=high){
            if(nums[mid]==target){
                ans=mid;
                high=mid-1;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
            mid=low+(high-low)/2;
        }
        return ans;
    }

    int last_pos(vector<int>nums , int target){
        int low=0;
        int high=nums.size()-1;
        int mid=low+(high-low)/2;
        int ans=-1;
        while(low <= high){
            if(nums[mid]==target){
                ans=mid;
                low=mid+1;
            }
            else if(nums[mid] < target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
            mid=low+(high-low)/2;
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        ans.push_back(first_pos(nums,target));
        ans.push_back(last_pos(nums,target));
        return ans;
    }
};
