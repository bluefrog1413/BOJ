#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int indegree[1005];
vector<int> adj[1005];
vector<int> arr;
queue<int> Q;
int tmp[1005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int num;
		cin >> num;
		for (int j = 0; j < num; j++)
		{
			cin >> tmp[j];
		}
		for (int j = 0; j < num-1; j++)
		{
			adj[tmp[j]].push_back(tmp[j + 1]);
			indegree[tmp[j + 1]]++;
		}
	}
	for (int i = 1; i <= n; i++)
		if (indegree[i] == 0) Q.push(i);

	while (!Q.empty()) {
		int cur = Q.front(); Q.pop();
		arr.push_back(cur);
		for (auto nxt : adj[cur]) {
			indegree[nxt]--;
			if (indegree[nxt] == 0) Q.push(nxt);
		}
	}
	if (arr.size() != n) {
		cout << 0 << '\n';
		return 0;
	}

	for (int i = 0; i < n; i++)
		cout << arr[i] << '\n';
}