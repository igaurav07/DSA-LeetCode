class Solution {
    static constexpr long long MOD = 1e9 + 7;

    using Matrix = vector<vector<long long>>;

    Matrix multiply(const Matrix& A, const Matrix& B) {
        int n = A.size();
        Matrix C(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (!A[i][k]) continue;
                for (int j = 0; j < n; j++) {
                    if (!B[k][j]) continue;
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }

    Matrix power(Matrix base, long long exp) {
        int n = base.size();
        Matrix res(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++) res[i][i] = 1;

        while (exp) {
            if (exp & 1) res = multiply(res, base);
            base = multiply(base, base);
            exp >>= 1;
        }
        return res;
    }

public:
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        if (n == 1) return m;

        int S = 2 * m;

        vector<long long> init(S, 0);

        for (int v = 0; v < m; v++) {
            init[v] = v;             // up
            init[m + v] = m - v - 1; // down
        }

        Matrix T(S, vector<long long>(S, 0));

        for (int v = 0; v < m; v++) {

            // newUp[v] = sum down[u], u < v
            for (int u = 0; u < v; u++)
                T[v][m + u] = 1;

            // newDown[v] = sum up[u], u > v
            for (int u = v + 1; u < m; u++)
                T[m + v][u] = 1;
        }

        Matrix P = power(T, n - 2);

        vector<long long> finalState(S, 0);

        for (int i = 0; i < S; i++) {
            for (int j = 0; j < S; j++) {
                finalState[i] =
                    (finalState[i] + P[i][j] * init[j]) % MOD;
            }
        }

        long long ans = 0;
        for (long long x : finalState)
            ans = (ans + x) % MOD;

        return (int)ans;
    }
};