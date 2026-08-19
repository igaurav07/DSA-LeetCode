class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        
        unordered_map<int, int> rows;

        // Store reserved seats as bitmask
        for (auto &seat : reservedSeats) {
            int row = seat[0];
            int s = seat[1];

            rows[row] |= (1 << s);
        }

        // Initially, every completely empty row can have 2 groups
        int ans = 2 * (n - rows.size());

        for (auto &[row, mask] : rows) {

            // 2,3,4,5
            bool left = !(mask & (1 << 2)) &&
                        !(mask & (1 << 3)) &&
                        !(mask & (1 << 4)) &&
                        !(mask & (1 << 5));

            // 6,7,8,9
            bool right = !(mask & (1 << 6)) &&
                         !(mask & (1 << 7)) &&
                         !(mask & (1 << 8)) &&
                         !(mask & (1 << 9));

            if (left && right) {
                ans += 2;
            }
            else if (left || right) {
                ans += 1;
            }
            else {
                // 4,5,6,7
                bool middle = !(mask & (1 << 4)) &&
                              !(mask & (1 << 5)) &&
                              !(mask & (1 << 6)) &&
                              !(mask & (1 << 7));

                if (middle)
                    ans += 1;
            }
        }

        return ans;
    }
};