#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n, m;
	cin >> n >> m;
	if (n == m) {
		cout << "YES" << '\n';
		return 0;
	}
	long long l, r;
	if (n % 2 == 0) {
		l = n / 2;
		r = n / 2;
	}
	else {
		l = n / 2;
		r = n / 2 + 1;
	}
	while (true) {
		if (m >= l && m <= r) {
			cout << "YES" << '\n';
			return 0;
		}
		l /= 2;
		r = (r + 1) / 2;
		if (l <= 1 && r <= 1) break;
	}
	cout << "NO" << '\n';
}