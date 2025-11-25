#include <iostream>
using namespace std;

int board[2005][2005];
int dp[2005];
int MAX = 0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			dp[j] += board[i][j];

	int a;
	cin >> a;
	for (int i = 0; i < m-a+1; i++)
	{
		int sum = 0;
		for (int j = i; j < i+a; j++)
		{
			sum += dp[j];
		}
		MAX = max(MAX, sum);
	}
	cout << MAX << '\n';
}