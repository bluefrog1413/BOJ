#include <iostream>
#include <queue>
using namespace std;

char board[2005][2005];
bool visS[2005][2005];
bool visW[2005][2005];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int r, c;
int x, y;

queue<pair<int, int>> next_s;
queue<pair<int, int>> s;
queue<pair<int, int>> next_w;
queue<pair<int, int>> w;

void inp() {
	cin >> r >> c;
	bool f = 1;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 'L') {
				visW[i][j] = 1;
				w.push({ i,j });
				x = i, y = j; }
			if (board[i][j] == '.') {
				visW[i][j] = 1;
				w.push({ i,j });
			}
		}
	}
}

void solve() {
	int day = 0;
	s.push({ x,y });
	visS[x][y] = 1;
	while (true) {
		while (!s.empty()) {
			pair<int, int> cur = s.front(); s.pop();
			for (int dir = 0; dir < 4; dir++)
			{
				int nx = dx[dir] + cur.first;
				int ny = dy[dir] + cur.second;
				if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
				if (visS[nx][ny]) continue;	

				visS[nx][ny] = 1;

				if (board[nx][ny] == 'L') {
					cout << day << '\n';
					return;
				}
				else if (board[nx][ny] == '.') s.push({ nx,ny });
				else next_s.push({ nx,ny });
			}
		}

		while (!w.empty()) {
			pair<int, int> cur = w.front(); w.pop();
			for (int dir = 0; dir < 4; dir++)
			{
				int nx = dx[dir] + cur.first;
				int ny = dy[dir] + cur.second;
				if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
				if (visW[nx][ny]) continue;
				visW[nx][ny] = 1;
				if (board[nx][ny] == '.') w.push({ nx,ny });
				else {
					next_w.push({ nx,ny });
					board[nx][ny] = '.';
				}
			}
		}
		day++;
		s.swap(next_s);
		w.swap(next_w);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	inp();
	solve();
}