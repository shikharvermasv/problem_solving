class Solution {
public:
    int shortestSubarray(vector<int> &nums, int k){
        priority_queue<pair<long long, long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> pq;
        long long sum=0;
        long long res=INT_MAX;
        for(long long i=0;i<nums.size();i++){
            sum+=nums[i];

            if(sum>=k){
                res=min(res,i+1);
            }

            while(!pq.empty() && (sum-pq.top().first)>=k){
                
                res =min(res ,i-pq.top().second);
                pq.pop();
            }
            pq.push({sum,i});
        }

        if(res == INT_MAX){
            return -1;
        }
        return res;
    }
};
