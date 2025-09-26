#include <iostream>
using namespace std;

bool board[35][15];
int n, m, h;
bool found = false;
int idx_x;

void inp() {
	cin >> n >> m >> h;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		board[a][b] = true;
	}
}

bool check(int x, int y) {
	int s = y;
	while (x <= h) {
		if (board[x][y - 1]) y--;
		else if (board[x][y]) y++;
		x++;
	}
	if (s == y) return true; // 처음 세로선의 위치와 마지막 세로선의 위치가 같음
	else return false;
}

void add_one(int k) {
	if (found) return;
	if (k == 1) {
		bool clr = true;
		for (int i = 1; i <= n; i++)
		{
			if (!check(1, i)) {
				clr = false;
				break;
			}
		}
		if (clr) {
			cout << 1 << '\n';
			found = true;
		}
		return;
	}

	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (board[i][j - 1] || board[i][j] || board[i][j + 1]) continue;
			board[i][j] = true;
			add_one(k + 1);
			board[i][j] = false;
		}
	}
}

void add_two(int k) {
	if (found) return;
	if (k == 2) {
		bool clr = true;
		for (int i = 1; i <= n; i++)
		{
			if (!check(1, i)) {
				clr = false;
				break;
			}
		}
		if (clr) {
			cout << 2 << '\n';
			found = true;
		}
		return;
	}

	int st_x = 1;
	if (k != 0) st_x = idx_x;

	for (int i = st_x; i <= h; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (board[i][j - 1] || board[i][j] || board[i][j + 1]) continue;
			board[i][j] = true;
			idx_x = i;
			add_two(k + 1);
			board[i][j] = false;
		}
	}
}

void add_three(int k) {
	if (found) return;
	if (k == 3) {
		bool clr = true;
		for (int i = 1; i <= n; i++)
		{
			if (!check(1, i)) {
				clr = false;
				break;
			}
		}
		if (clr) {
			cout << 3 << '\n';
			found = true;
		}
		return;
	}

	int st_x = 1;
	if (k != 0) st_x = idx_x;

	for (int i = st_x; i <= h; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (board[i][j - 1] || board[i][j] || board[i][j + 1]) continue;
			board[i][j] = true;
			idx_x = i;
			add_three(k + 1);
			board[i][j] = false;
		}
	}
}

void solve() {
	bool clr = true;
	for (int i = 1; i <= n; i++)
	{
		if (!check(1, i)) {
			clr = false;
			break;
		}
	}
	if (clr) {
		cout << 0 << '\n';
		return;
	}

	add_one(0);
	if (found) return;   
	add_two(0);
	if (found) return;   
	add_three(0);
	if (found) return;   

	cout << -1 << '\n'; 
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	inp();
	solve();
}