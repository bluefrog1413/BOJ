#include <iostream>
#include <set>
using namespace std;

set<string> s;
set<string> ans;
int n, m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		s.insert(str);
	}
	for (int i = 0; i < m; i++)
	{
		string str;
		cin >> str;
		if (s.find(str) != s.end()) ans.insert(str);
	}
	cout << ans.size() << '\n';
	for (auto iter = ans.begin(); iter != ans.end(); iter++)
	{
		cout << *iter << '\n';
	}
}