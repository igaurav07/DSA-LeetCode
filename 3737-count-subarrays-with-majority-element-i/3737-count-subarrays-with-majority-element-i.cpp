class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
       int n = nums.size();

        vector<long long> pref(n + 1, 0);

        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + (nums[i] == target ? 1 : -1);
        }

        vector<long long> comp = pref;
        sort(comp.begin(), comp.end());
        comp.erase(unique(comp.begin(), comp.end()), comp.end());

        int m = comp.size();
        vector<long long> bit(m + 1, 0);

        auto update = [&](int idx) {
            while (idx <= m) {
                bit[idx]++;
                idx += idx & -idx;
            }
        };

        auto query = [&](int idx) {
            long long res = 0;
            while (idx > 0) {
                res += bit[idx];
                idx -= idx & -idx;
            }
            return res;
        };

        long long ans = 0;

        for (long long x : pref) {
            int pos = lower_bound(comp.begin(), comp.end(), x) - comp.begin() + 1;

            ans += query(pos - 1); // previous prefixes < current prefix

            update(pos);
        }

        return ans; 
    }
};