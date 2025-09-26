#include <iostream>
#include <vector>
using namespace std;

int max_size;
int botton = 0;
vector<int> arr;
bool isused[505];

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	if (m + k > n + 1) {
		cout << -1;
		return 0;
	}
	int a = m, b = k;
	while (true) {
		if (!a || !b) break;
		max_size += a + b - 1;
		a--;
		b--;
	}

	int cnt = 0;
	m--;
	int L = 1, R = n;
	if (max_size < n) {
		cout << -1;
		return 0;
	}
	else {
		while (cnt < n) {
			bool End = 0;
			if (n - cnt <= k - 1) {
				for (int i = n; i >= 1; i--)
				{
					if (!isused[i]) arr.push_back(i);
				}
				End = 1;
			}
			if (End) break;
			for (int i = L + k - 1; i >= L; i--)
			{
				if (cnt == n) break;
				arr.push_back(i);
				cnt++;
				isused[i] = 1;
			}
			L += k;
			k--;
			if (n - cnt <= m) {
				for (int i = 1; i <= n; i++)
				{
					if (!isused[i]) arr.push_back(i);
				}
				End = 1;
			}
			if (End) break;
			for (int i = R - m + 1; i <= R; i++)
			{
				if (cnt == n) break;
				arr.push_back(i);
				cnt++;
				isused[i] = 1;
			}
			m--;
			R -= m;
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << ' ';
	}
}