//this code contains recusive, top-down and bottom-up dp approach
//uncomment the function calls in the main function to use the particular approach
// space complexity in case of dp is O(n^2)
//time complexity in case of dp is O(n^3)
#include <bits/stdc++.h>
using namespace std;
int solve(int *arr, int i, int j)
{
    if (i >= j)
        return 0;
    int ans = INT_MAX;
    for (int k = i; k <= j - 1; k++)
    {
        int tempans = solve(arr, i, k) + solve(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
        ans = min(ans, tempans);
    }
    return ans;
}
int dp_top[1001][1001];
int solve_top_down(int *arr, int i, int j)
{
    if (i >= j)
        return 0;
    if (dp_top[i][j] != -1)
    {
        return dp_top[i][j];
    }
    int ans = INT_MAX;
    for (int k = i; k <= j - 1; k++)
    {
        int tempans = solve_top_down(arr, i, k) + solve_top_down(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
        ans = min(ans, tempans);
    }
    return dp_top[i][j] = ans;
}
int solve_bottomup(int *arr, int n)
{
    int dp[n - 1][n - 1];
    for (int g = 0; g < n - 1; g++)
    {
        for (int i = 0, j = g; j < n - 1; i++, j++)
        {
            if (g == 0)
            {
                dp[i][j] = 0;
            }
            else if (g == 1)
            {
                dp[i][j] = arr[i] * arr[i + 1] * arr[j + 1];
            }
            else
            {
                dp[i][j] = INT_MAX;
                for (int k = i; k < j; k++)
                {
                    // i to k left half k+1,jj right half
                    int left = dp[i][k];
                    int right = dp[k + 1][j];
                    dp[i][j] = min(dp[i][j], left + right + arr[i] * arr[k + 1] * arr[j + 1]);
                }
            }
        }
    }

    return dp[0][n - 2];
}
int main()
{
    int arr[] = {40, 20, 30, 10, 30};
    int n = 5;
    // cout<<solve(arr,1,n-1);
    // memset(dp_top,-1,sizeof dp_top);
    // cout<<solve_top_down(arr,1,n-1);
    cout << solve_bottomup(arr, n);
    return 0;
}