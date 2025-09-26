#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> adj[300005];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;
int dist[300005];
int n, m, k, x;
const int INF = 0x3f3f3f3f;

void inp() {
	cin >> n >> m >> k >> x;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
	}
}

void solve() {
	fill(dist, dist + n + 1, INF);
	PQ.push({ 0,x });
	dist[x] = 0;
	while (!PQ.empty()) {
		auto cur = PQ.top(); PQ.pop();
		if (dist[cur.second] != cur.first) continue;
		for (auto nxt : adj[cur.second]) {
			if (dist[nxt] > dist[cur.second] + 1) {
				dist[nxt] = dist[cur.second] + 1;
				PQ.push({ dist[nxt],nxt });
			}
		}
	}
	bool exist = false;
	for (int i = 1; i <= n; i++)
	{
		if (dist[i] == k) {
			cout << i << '\n';
			exist = true;
		}
	}
	if (!exist) cout << -1 << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);


	inp();
	solve();
}