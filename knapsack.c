// C++ implementation of the approach
#include <bits/stdc++.h>
#define C_MAX 30
#define max_arr_len 10
using namespace std;

// To store states of DP
int dp[max_arr_len][C_MAX + 1];

// To check if a state has
// been solved
bool v[max_arr_len][C_MAX + 1];

// Function to compute the states
int findMax(int i, int r, int w[], int n)
{

	// Base case
	if (r < 0)
		return INT_MIN;
	if (i == n)
		return 0;

	// Check if a state has
	// been solved
	if (v[i][r])
		return dp[i][r];

	// Setting a state as solved
	v[i][r] = 1;
	dp[i][r] = max(w[i] + findMax(i + 1, r - w[i], w, n),
				findMax(i + 1, r, w, n));

	// Returning the solved state
	return dp[i][r];
}

// Function to pre-compute the states
// dp[0][0], dp[0][1], .., dp[0][C_MAX]
void preCompute(int w[], int n)
{
	for (int i = C_MAX; i >= 0; i--)
		findMax(0, i, w, n);
}

// Function to answer a query in O(1)
int ansQuery(int w)
{
	return dp[0][w];
}

// Driver code
int main()
{
	int w[] = { 3, 8, 9 };
	int n = sizeof(w) / sizeof(int);

	// Performing required
	// pre-computation
	preCompute(w, n);

	int queries[] = { 11, 10, 4 };
	int q = sizeof(queries) / sizeof(queries[0]);

	// Perform queries
	for (int i = 0; i < q; i++)
		cout << ansQuery(queries[i]) << endl;

	return 0;
}

