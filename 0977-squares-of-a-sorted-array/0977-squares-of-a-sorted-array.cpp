
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);

        int head = 0;
        int tail = n - 1;

        for (int pos = n - 1; pos >= 0; pos--) {
            if (abs(nums[head]) > abs(nums[tail])) {
                result[pos] = nums[head] * nums[head];
                head++;
            } else {
                result[pos] = nums[tail] * nums[tail];
                tail--;
            }
        }

        return result;
    }
};
