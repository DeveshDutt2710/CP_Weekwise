/*
https://leetcode.com/problems/minimum-cost-to-cut-a-stick/

1547_MinimumCosttoCutStick

Given a wooden stick of length n units. The stick is labelled from 0 to n. For example, a stick of length 6 is labelled as follows:


Given an integer array cuts where cuts[i] denotes a position you should perform a cut at.

You should perform the cuts in order, you can change the order of the cuts as you wish.

The cost of one cut is the length of the stick to be cut, the total cost is the sum of costs of all cuts. When you cut a stick, it will be split into two smaller sticks (i.e. the sum of their lengths is the length of the stick before the cut). Please refer to the first example for a better explanation.

Return the minimum total cost of the cuts.
*/


class Solution {
public:
    int dp[102][102] = {};
    int dfs(vector<int>& cuts, int i, int j) 
    {
        if (j - i <= 1)
            return 0;
        if (!dp[i][j]) 
        {
            dp[i][j] = INT_MAX;
            for (auto k = i + 1; k < j; ++k)
            {
                dp[i][j] = min(dp[i][j], cuts[j] - cuts[i] + dfs(cuts, i, k) + dfs(cuts, k, j));
            }
        }
        return dp[i][j];
    }
    int minCost(int n, vector<int>& cuts) 
    {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(begin(cuts), end(cuts));
        return dfs(cuts, 0, cuts.size() - 1);
    }
};