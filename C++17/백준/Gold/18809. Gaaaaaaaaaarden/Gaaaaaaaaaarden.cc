#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int board[55][55];
int dist[55][55];
int tmp[55][55];
vector<pair<int, int>> cand;
vector<int> arr;
int n, m, g, r;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int ans;

void inp() {
	cin >> n >> m >> g >> r;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
			tmp[i][j] = board[i][j];
			if (board[i][j] == 2) cand.push_back({ i,j });
		}
	}
}

void solve() {
	for (int i = 0; i < cand.size(); i++)
	{
		if (i < g + r) {
			if (i < g) {
				arr.push_back(1);
			}
			else arr.push_back(2);
		}
		else arr.push_back(0);
	}
	sort(arr.begin(), arr.end());
	do {
		queue<pair<int, int>> Q;
		queue < pair<int, int>> next_Q;
		for (int i = 0; i < arr.size(); i++) {
			if (arr[i] == 1) {
				board[cand[i].first][cand[i].second] = 3; // green
				Q.push({ cand[i].first,cand[i].second });
				dist[cand[i].first][cand[i].second] = 1;
			}
			else if (arr[i] == 2) {
				board[cand[i].first][cand[i].second] = 4; // red
				Q.push({ cand[i].first,cand[i].second });
				dist[cand[i].first][cand[i].second] = 1;
			}
		}
		int cnt = 0;
		while (!Q.empty()) {
			while (!Q.empty()) {
				pair<int, int> cur = Q.front(); Q.pop();
				if (board[cur.first][cur.second] == 5) continue;
				for (int dir = 0; dir < 4; dir++)
				{
					int nx = dx[dir] + cur.first;
					int ny = dy[dir] + cur.second;
					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if (board[nx][ny] == 0 || board[nx][ny] == 5) continue;
					if ((board[nx][ny] == 3 && board[cur.first][cur.second] == 4) || (board[nx][ny] == 4 && board[cur.first][cur.second] == 3)) {
						if (dist[nx][ny] == dist[cur.first][cur.second] + 1) {
							board[nx][ny] = 5;
							cnt++;
							continue;
						}
					}
					if (dist[nx][ny] != 0 && dist[nx][ny] <= dist[cur.first][cur.second] + 1) continue;
					board[nx][ny] = board[cur.first][cur.second];
					dist[nx][ny] = dist[cur.first][cur.second] + 1;
					next_Q.push({ nx,ny });
				}
			}
			Q.swap(next_Q);
		}

		ans = max(ans, cnt);

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				board[i][j] = tmp[i][j];
				dist[i][j] = 0;
			}
		}
	} while (next_permutation(arr.begin(), arr.end()));

	cout << ans << '\n';

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	inp();
	solve();
}