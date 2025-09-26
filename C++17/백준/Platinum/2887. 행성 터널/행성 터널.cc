#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
using namespace std;
using ll = long long;
long long ans;
int n;

vector<pair<ll,int>> X;
vector<pair<ll,int>> Y;
vector<pair<ll,int>> Z;
vector<tuple<ll, int, int>> edge;
vector<int> p(300005, -1);

void inp() {
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		ll x, y, z;
		cin >> x >> y >> z;
		X.push_back({ x,i });
		Y.push_back({ y,i });
		Z.push_back({ z,i });
	}
	sort(X.begin(), X.end());
	sort(Y.begin(), Y.end());
	sort(Z.begin(), Z.end());
}

void init_edge() {
	for (int i = 0; i < n - 1; i++)
	{
		ll x1, y1, z1, x2, y2, z2;
		int a, b;
		tie(x1, a) = X[i];
		tie(x2, b) = X[i + 1];
		edge.push_back({ abs(x1 - x2), a, b });
		tie(y1, a) = Y[i];
		tie(y2, b) = Y[i + 1];
		edge.push_back({ abs(y1 - y2), a, b });
		tie(z1, a) = Z[i];
		tie(z2, b) = Z[i + 1];
		edge.push_back({ abs(z1 - z2), a, b });
	}
	sort(edge.begin(), edge.end());
}

int find(int x) {
	if (p[x] < 0) return x;
	return p[x] = find(p[x]);
}

bool uni(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) return false;
	if (p[v] < p[u]) swap(u, v);
	if (p[u] == p[v]) p[u]--;
	p[v] = u;
	return true;
}

void solve() {
	int cnt = 0;
	for (size_t i = 0; i < edge.size(); i++)
	{
		ll cost;
		int a, b;
		tie(cost, a, b) = edge[i];
		if (!uni(a, b)) continue;
		cnt++;
		ans += cost;
		if (cnt == n - 1) break;
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	inp();
	init_edge();
	solve();
}