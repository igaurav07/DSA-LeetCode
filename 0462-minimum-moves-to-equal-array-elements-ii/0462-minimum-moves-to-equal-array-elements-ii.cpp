#include <vector>
#include <algorithm>

class Solution {
public:
    int minMoves2(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() - 1;
        int moves = 0;
        
        while (left < right) {
            moves += nums[right] - nums[left];
            left++;
            right--;
        }
        
        return moves;
    }
};