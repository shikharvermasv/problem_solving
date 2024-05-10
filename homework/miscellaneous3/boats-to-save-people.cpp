class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        int l=0;
        int h = n-1;
        int countboats = 0;
        sort(people.begin() , people.end());
        while(l<=h){
            if(people[l] + people[h] <= limit){ // max of two people can go on the boat
                countboats++;
                l++;
                h--;
            }
            else{
                countboats++;
                h--;
            }
        }
        return countboats;
    }
};
