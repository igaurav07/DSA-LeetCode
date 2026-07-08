class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int m = s.size();
        vector<int> positions;
        vector<int> digits;
        for (int i = 0; i < m; i++) {
            if (s[i] != '0') {
                positions.push_back(i);
                digits.push_back(s[i] - '0');
            }
        }
        int t = digits.size();
        const long long MOD = 1000000007LL;
        
        vector<long long> pow10(t + 1, 1LL);
        for (int i = 1; i <= t; i++) {
            pow10[i] = pow10[i - 1] * 10LL % MOD;
        }
        
        vector<long long> prefix_num(t + 1, 0LL);
        for (int i = 0; i < t; i++) {
            prefix_num[i + 1] = (prefix_num[i] * 10LL + digits[i]) % MOD;
        }
        
        vector<long long> prefix_sum(t + 1, 0LL);
        for (int i = 0; i < t; i++) {
            prefix_sum[i + 1] = prefix_sum[i] + digits[i];
        }
        
        vector<int> ans;
        for (auto& q : queries) {
            int l = q[0], r = q[1];
            
            // Find first non-zero position >= l
            auto it1 = lower_bound(positions.begin(), positions.end(), l);
            int L = it1 - positions.begin();
            
            // Find last non-zero position <= r
            auto it2 = upper_bound(it1, positions.end(), r);
            int R = (it2 - positions.begin()) - 1;
            
            if (L > R) {
                ans.push_back(0);
                continue;
            }
            
            long long len = R - L + 1LL;
            long long xmod = (prefix_num[R + 1] - prefix_num[L] * pow10[len] % MOD + MOD) % MOD;
            long long sm = prefix_sum[R + 1] - prefix_sum[L];
            long long res = xmod * (sm % MOD) % MOD;
            ans.push_back((int)res);
        }
        return ans;
    }
};