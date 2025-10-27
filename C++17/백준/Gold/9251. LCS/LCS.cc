#include <iostream>
using namespace std;

int dp[1005][1005];

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	for (int i = 0; i < s1.size(); i++)
	{
		for (int j = 0; j < s2.size(); j++)
		{
			if (s1[i] == s2[j]) dp[i + 1][j + 1] = dp[i][j] + 1;
			else dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
		}
	}
	int max = 0;
	for (int i = 0; i < s1.size()+1; i++)
	{
		for (int j = 0; j < s2.size()+1; j++)
		{
			if (max < dp[i][j]) max = dp[i][j];
		}
	}
	cout << max << '\n';
}