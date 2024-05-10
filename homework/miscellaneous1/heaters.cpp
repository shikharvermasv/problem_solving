class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
		int i = 0, j = 0;
		int ans = INT_MAX;

		vector<int> temp(houses.size(), INT_MAX);

		sort(houses.begin(), houses.end());
		sort(heaters.begin(), heaters.end());

		for (i = 0; i < houses.size(); i++) {
			while (j + 1 < heaters.size() && houses[i] >= heaters[j]) {
				j++;
			}
			if (j - 1 >= 0)
				temp[i] = min(abs(houses[i] - heaters[j-1]), abs(houses[i] - heaters[j]));
			else
				temp[i] = abs(houses[i] - heaters[j]);
		}
        ans = temp[0];
		for (i = 1; i < temp.size(); i++){
			ans = max(ans, temp[i]);
        }

		return ans;
    }
};
