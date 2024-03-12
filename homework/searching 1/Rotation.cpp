class Solution{
public:	
	int findKRotation(int arr[], int n) {
	    // code here
	    int s = 0;
        int e = n-1;
        while(s < e){
            int mid = s + (e - s)/2;
            if(arr[mid] >= arr[0]){
                s = mid + 1;
            }
            else{
                e = mid;
            }
        }
        if(e == n-1 and arr[n-1] > arr[n-2]){
            return 0;
        }
        else{
            return e;
        }
	}

};
