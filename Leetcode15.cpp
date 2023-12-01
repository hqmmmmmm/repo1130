class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for(int i = 0; i < n; ++i)
        {
            if(i > 0 && nums[i] == nums[i - 1]) continue;

            int j = i + 1, k = n - 1;
            while(j < k)
            {
                if(j > i + 1 && j < k && nums[j] == nums[j - 1])
                {
                    ++j;
                    continue;
                }

                if(j >= k) break;

                if(nums[i] + nums[j] + nums[k] > 0) --k;
                else if(nums[i] + nums[j] + nums[k] < 0) ++j;
                else res.push_back({nums[i], nums[j++], nums[k]});
            }
            // for(; j < k; ++j)
            // {
            //     if(j > i + 1 && nums[j] == nums[j - 1]) continue;

            //     while(j < k && nums[j] + nums[k] > -nums[i]) --k;

            //     if(j == k) break;

            //     if(nums[j] + nums[k] == -nums[i])
            //         res.push_back({nums[i], nums[j], nums[k]});
            // }
        }
        return res;
    }
};
