class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;

        // Store indices for each number
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }

        int ans = INT_MAX;

        // For every number
        for (auto& [value, indices] : mp) {

            // Need at least 3 occurrences
            if (indices.size() < 3)
                continue;

            // Check every consecutive group of 3
            for (int i = 0; i + 2 < indices.size(); i++) {
                int first = indices[i];
                int third = indices[i + 2];

                int distance = 2 * (third - first);

                ans = min(ans, distance);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};