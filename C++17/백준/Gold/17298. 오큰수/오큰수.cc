#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int arr[1000005];
vector<int> ans;
stack<int> S;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++)
	{
		if (i == 0) {
			S.push(arr[n - 1 - i]);
			ans.push_back(-1);
		}
		else {
			while (true) {
				if(S.size() == 0) {
					S.push(arr[n - 1 - i]);
					ans.push_back(-1);
					break;
				}
				if (S.top() > arr[n - 1 - i]) {
					ans.push_back(S.top());
					S.push(arr[n - 1 - i]);
					break;
				}
				S.pop();
			}
		}
	}
	for (int i = ans.size()-1; i >= 0; i--)
	{
		cout << ans[i] << ' ';
	}
}