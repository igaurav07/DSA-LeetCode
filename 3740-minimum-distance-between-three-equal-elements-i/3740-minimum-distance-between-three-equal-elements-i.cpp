class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, pair<int, int>> mp;
        int ans = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];

            if (mp.find(x) == mp.end()) {
                // first occurrence
                mp[x] = {-1, i};
            } 
            else {
                int secondLast = mp[x].first;
                int last = mp[x].second;

                // This is the 3rd or later occurrence
                if (secondLast != -1) {
                    ans = min(ans, 2 * (i - secondLast));
                }

                // Shift positions
                mp[x] = {last, i};
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};