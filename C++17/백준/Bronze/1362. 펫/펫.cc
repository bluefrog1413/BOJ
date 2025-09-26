#include <iostream>
using namespace std;

int main() {
	int t = 0;
	while (true) {
		++t;
		int o, w;
		cin >> o >> w;
		if (o == 0 && w == 0) break;
		string cmd;
		int num;
		bool die = false;
		while (true) {
			cin >> cmd >> num;
			if (cmd == "#") {
				if (die) cout << t << " RIP" << '\n';
				else if (w > o / 2 && w < o * 2) cout << t << " :-)" << '\n';
				else cout << t << " :-(" << '\n';
				break;
			}
			else if (cmd == "F") {
				w += num;
			}
			else {
				w -= num;
				if (w <= 0) die = true;
			}
		}
	}
}