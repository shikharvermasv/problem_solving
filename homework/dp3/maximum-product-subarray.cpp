class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = 1, mini = 1;
        if (nums[nums.size() - 1] != 0) {
            maxi = nums[nums.size() - 1];
            mini = maxi;
        }
        int ans = nums[nums.size() - 1];
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] == 0) {
                mini = 1;
                maxi = 1;
                if(ans < 0){
                    ans = 0;
                }
                continue;
            }
            int temp = maxi;
            maxi = max(maxi * nums[i], mini * nums[i]);
            maxi = max(maxi, nums[i]);
            mini = min(temp * nums[i], mini * nums[i]);
            mini = min(mini, nums[i]);
            ans = max(ans, maxi);
        }
        return ans;
    }
};
