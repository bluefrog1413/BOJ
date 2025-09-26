#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<pair<int, int>> adj[10005];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;
int dist[10005];
int n, d, c;
int INF = 0x3f3f3f3f;

void inp() {
	cin >> n >> d >> c;
	for (int i = 0; i < d; i++)
	{
		int a, b, s;
		cin >> a >> b >> s;
		adj[b].push_back({ s,a });
	}
}

void solve() {
	inp();
	fill(dist, dist + n + 1, INF);
	dist[c] = 0;
	PQ.push({ 0,c });
	while (!PQ.empty()) {
		auto cur = PQ.top(); PQ.pop();
		if (dist[cur.second] != cur.first) continue;
		for (auto nxt : adj[cur.second]) {
			if (dist[nxt.second] > dist[cur.second] + nxt.first) {
				dist[nxt.second] = dist[cur.second] + nxt.first;
				PQ.push({ dist[nxt.second],nxt.second });
			}
		}
	}
	int cnt = 0;
	int MAX = 0;
	for (int i = 1; i <= n; i++)
	{
		if (dist[i] != INF) {
			cnt++;
			MAX = max(MAX, dist[i]);
		}
	}
	cout << cnt << ' ' << MAX << '\n';

	for (int i = 1; i <= n; i++)
		adj[i].clear();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}