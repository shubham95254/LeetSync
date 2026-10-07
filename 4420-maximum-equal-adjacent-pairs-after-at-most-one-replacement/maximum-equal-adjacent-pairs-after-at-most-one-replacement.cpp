class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        int count = 0;
        map<pair<int, int>, int> mpp;
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] != nums[i + 1]) {
                mpp[{min(nums[i], nums[i + 1]), max(nums[i], nums[i + 1])}]++;
            } else
                count++;
        }
        int maxcount = 0;
        for (auto it : mpp) {
            maxcount = max(maxcount, it.second);
        }
        count += maxcount;
        return count;
    }
};