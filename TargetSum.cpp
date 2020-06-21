#include <bits/stdc++.h>
using namespace std;

int TargetSumWays(vector<int> &nums, int TargetSum)
{

    unordered_map<int, int> dp;
    unordered_map<int, int> next;

    dp[nums[0]]++;
    dp[-nums[0]]++;

    for (int i = 1; i < nums.size(); i++)
    {
        next.clear();
        for (auto mp : dp)
        {
            next[mp.first + nums[i]] += dp[mp.first];
            next[mp.first - nums[i]] += dp[mp.first];
        }
        dp = next;
    }

    int result = dp[TargetSum];
    dp.clear();
    next.clear();
    return result;
}
int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> nums = {1, 1, 1, 1, 1};
    int TargetSum;
    cin >> TargetSum;
    cout << TargetSumWays(nums, TargetSum);
    return 0;
}