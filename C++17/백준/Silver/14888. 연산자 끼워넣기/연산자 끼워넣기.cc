#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[15];
int isused[15];
int cmd[15];
vector<int> oper;
int cnt[4];
int n;
int MAX = -0x7fffffff;
int MIN = 0x7fffffff;
int idx = 0;

void func(int k) {
	if (k == n-1) {
		int sum = arr[0];
		for (int i = 0; i < k; i++)
		{
			if (cmd[i] == 0) sum += arr[i + 1];
			else if (cmd[i] == 1) sum -= arr[i + 1];
			else if (cmd[i] == 2) sum *= arr[i + 1];
			else sum /= arr[i + 1];
		}
		MAX = max(MAX, sum);
		MIN = min(MIN, sum);
	}
	

	int prev = -1;
	for (size_t i = 0; i < oper.size(); i++)
	{
		if (!isused[i]&& oper[i] != prev) {
			cmd[k] = oper[i];
			isused[i] = true;
			prev = oper[i];
			func(k + 1);
			isused[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < 4; i++)
		cin >> cnt[i];

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < cnt[i]; j++)
			oper.push_back(i);

	sort(oper.begin(), oper.end());
	func(0);
	cout << MAX << '\n';
	cout << MIN << '\n';
}