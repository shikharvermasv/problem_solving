#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i = 0;i<n;i++){
      cin>>nums[i];
    }
    int x,y,z;
    cin>>x>>y>>z;

    int ansl[n]; 
    ansl[0] = x * nums[0]; 
    for (int i = 1; i < n; i++){  
        ansl[i] = max(ansl[i - 1], x * nums[i]); 
    }
    int ansr[n]; 
    ansr[n-1] = z * nums[n-1]; 
    for (int i = n - 2; i >= 0; i--){ 
        ansr[i] = max(ansr[i + 1], z * nums[i]); 
    }
  
    int ans = INT_MIN;  
    for (int i = 0; i < n; i++)  
          ans = max(ans, ansl[i] + y * nums[i] + ansr[i]);  
  
    cout<<ans<<endl; 
}
