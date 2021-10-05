//Problem Statement----Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. In other words, given two integer arrays, val[0..n-1] and wt[0..n-1] represent values and weights associated with n items respectively. Also given an integer W which represents knapsack capacity, find out the items such that sum of the weights of those items of a given subset is smaller than or equal to W. You cannot break an item, either pick the complete item or don’t pick it (0-1 property).
#include <iostream>
using namespace std;
int dp[1000][1000];
int knapsack(int number_of_items, int weight[], int value[], int max_wt)
{
	for (int i = 1; i <= number_of_items; i++)
	{
		for (int j = 1; j <= max_wt; j++)
		{
			if (weight[i - 1] > j)
			{
				dp[i][j] = dp[i - 1][j];
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], value[i - 1] + dp[i - 1][j - weight[i - 1]]);
			}
		}
	}
	return dp[number_of_items][max_wt];
}
int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int number_of_items;
	cin >> number_of_items;
	int max_wt;
	cin >> max_wt;
	int weight[number_of_items];
	int value[number_of_items];
	for (int i = 0; i < number_of_items; i++)
	{
		cin >> weight[i];
	}
	for (int i = 0; i < number_of_items; i++)
	{
		cin >> value[i];
	}
	for (int i = 0; i <= number_of_items; i++)
	{
		for (int j = 0; j <= max_wt; j++)
			dp[i][j] = 0;
	}

	int ans = knapsack(number_of_items, weight, value, max_wt);

	cout << ans << endl;
	int wt = max_wt;
	for (int i = number_of_items; i > 0; i--)
	{

		if (ans == 0)
			break;
		if (ans == dp[i - 1][wt])
			continue;
		else
		{
			cout << weight[i - 1] << " ";
			ans = ans - value[i - 1];
			wt = wt - weight[i - 1];
		}
	}

	return 0;
}
