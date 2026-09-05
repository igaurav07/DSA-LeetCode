class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> pos_map;
        
        // Group indices by number
        for (int i = 0; i < nums.size(); ++i) {
            pos_map[nums[i]].push_back(i);
        }
        
        int min_dist = INT_MAX;
        
        // For sorted indices i < j < k, dist = 2 * (k - i)
        // To minimize (k - i), check consecutive triplets
        for (const auto& [num, pos] : pos_map) {
            if (pos.size() >= 3) {
                for (size_t i = 0; i + 2 < pos.size(); ++i) {
                    int dist = 2 * (pos[i + 2] - pos[i]);
                    min_dist = min(min_dist, dist);
                }
            }
        }
        
        return (min_dist == INT_MAX) ? -1 : min_dist;
    }
};