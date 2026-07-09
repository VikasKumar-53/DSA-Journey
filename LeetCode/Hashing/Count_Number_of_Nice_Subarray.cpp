class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;

        int odd = 0, ans = 0;

        for (int x : nums) {
            if (x % 2)
                odd++;

            if (mp.count(odd - k))
                ans += mp[odd - k];

            mp[odd]++;
        }

        return ans;
    }
};