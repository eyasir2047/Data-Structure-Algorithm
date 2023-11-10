class Solution {
    // group1[i...] with group2 points occupied in mask
    int solve(int ith, int mask, vector<vector<int>>& cost,
              vector<int>& min2, vector<vector<int>>& mem) {
        if (mem[ith][mask] != -1) {
            return mem[ith][mask];
        }

        int m = cost.size(), n = cost[0].size(), ans;
        if (ith == m) {
            // connect each unoccupied group2 point
            ans = 0;
            for (int j = 0; j < n; j++) {
                if (!(mask & (1 << j))) {
                    ans += min2[j];
                }
            }
        } else {
            ans = INT_MAX;
            // connect group1[ith] to each point in group2
            for (int j = 0; j < n; j++) {
                int val = cost[ith][j] + solve(ith + 1, mask | (1 << j), cost, min2, mem);
                ans = min(ans, val);
            }
        }

        return mem[ith][mask] = ans;
    }
public:
    /*
    Observations:
    1. group1 and group2 has different number of points,
       suppose their size m and n, we know m >= n.
    2. A point in group1 can connect to any point in group2.
       All points in group1 can connect to 1/2/.../n points
       in group2. Let's say dp[i][mask] denote the min cost
       to connect group1[i...m-1] to group2, with mask denote
       unused group2 points as 0 and used as 1. We have:

       dp[i][mask] = min(cost[i][j] + dp[i+1][mask | (1 << j)]), j in [0, n-1]

       Basically group1[i] can connect to any point in group2,
       regardless of whether this point has been used before.
    3. In the end some group2 points might be 0 in mask,
       connect such point to its lowest cost connection in
       group1, and sum up the cost for all such points.

       bitmask dp;
       O(m * 2^n * n) time O(m * 2^n) space, can be optimized to O(2^n) space;
    */
    int connectTwoGroups(vector<vector<int>>& cost) {
        int m = cost.size(), n = cost[0].size();
        // minimum cost for each group2 point
        vector<int> min2(n, 101);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                min2[j] = min(min2[j], cost[i][j]);
            }
        }

        int N = 1 << n;
        // mem[m] is used in the end, to handle unoccupied points in group2
        vector<vector<int>> mem(m + 1, vector<int>(N, -1));
        return solve(0, 0, cost, min2, mem);
    }
};