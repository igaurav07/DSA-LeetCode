class Solution {
public:
    int search(vector<int>& nums, int target, bool first) {
        int s = 0, e = nums.size() - 1;
        int ans = -1;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (nums[mid] == target) {
                ans = mid;

                if (first)
                    e = mid - 1;  // left search
                else
                    s = mid + 1;  // right search
            }
            else if (nums[mid] < target) {
                s = mid + 1;
            }
            else {
                e = mid - 1;
            }
        }

        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = search(nums, target, true);
        int last  = search(nums, target, false);

        return {first, last};
    }
};