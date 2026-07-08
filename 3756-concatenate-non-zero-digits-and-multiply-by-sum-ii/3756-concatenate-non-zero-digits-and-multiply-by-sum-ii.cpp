class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int m = s.size();
        vector<int> pos, digs;
        pos.reserve(m);
        digs.reserve(m);
        
        for (int i = 0; i < m; i++) {
            if (s[i] != '0') {
                pos.push_back(i);
                digs.push_back(s[i] - '0');
            }
        }
        
        int t = digs.size();
        const long long MOD = 1000000007LL;
        
        vector<long long> pow10(t + 1, 1);
        for (int i = 1; i <= t; i++) {
            pow10[i] = pow10[i - 1] * 10 % MOD;
        }
        
        vector<long long> pre(t + 1, 0);
        for (int i = 0; i < t; i++) {
            pre[i + 1] = (pre[i] * 10 + digs[i]) % MOD;
        }
        
        vector<long long> presum(t + 1, 0);
        for (int i = 0; i < t; i++) {
            presum[i + 1] = presum[i] + digs[i];
        }
        
        vector<int> ans;
        ans.reserve(queries.size());
        
        for (auto& q : queries) {
            int l = q[0], r = q[1];
            
            auto it1 = lower_bound(pos.begin(), pos.end(), l);
            int L = it1 - pos.begin();
            
            auto it2 = upper_bound(it1, pos.end(), r);
            int R = (it2 - pos.begin()) - 1;
            
            if (L > R) {
                ans.push_back(0);
                continue;
            }
            
            long long len = R - L + 1;
            long long x = (pre[R + 1] - pre[L] * pow10[len] % MOD + MOD) % MOD;
            long long sm = presum[R + 1] - presum[L];
            ans.push_back(x * (sm % MOD) % MOD);
        }
        return ans;
    }
};