class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int LIM = 2048;

        vector<bool> pairXor(LIM, false);
        vector<bool> ans(LIM, false);

        int n = nums.size();

        // i <= j
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                pairXor[nums[i] ^ nums[j]] = true;
            }
        }

        // pair xor ^ third element
        for (int x = 0; x < LIM; x++) {
            if (!pairXor[x]) continue;
            for (int k = 0; k < n; k++) {
                ans[x ^ nums[k]] = true;
            }
        }

        int res = 0;
        for (bool x : ans) res += x;
        return res;
    }
};