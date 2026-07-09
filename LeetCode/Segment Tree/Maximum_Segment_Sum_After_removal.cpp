class Solution {
public:
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
        int n = nums.size();
        vector<long long> ans(n), sum(n);
        vector<int> parent(n), active(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
            sum[i] = nums[i];
        }

        function<int(int)> find = [&](int x) {
            return parent[x] == x ? x : parent[x] = find(parent[x]);
        };

        auto unite = [&](int a, int b) {
            a = find(a);
            b = find(b);
            if (a != b) {
                parent[b] = a;
                sum[a] += sum[b];
            }
        };

        long long mx = 0;

        for (int i = n - 1; i >= 0; i--) {
            ans[i] = mx;
            int idx = removeQueries[i];
            active[idx] = 1;

            if (idx > 0 && active[idx - 1])
                unite(idx, idx - 1);
            if (idx + 1 < n && active[idx + 1])
                unite(idx, idx + 1);

            mx = max(mx, sum[find(idx)]);
        }

        return ans;
    }
};