#include <iostream>
using namespace std;

int main() {
	int num = 0;
	for (int i = 0; i < 5; i++)
	{
		int x;
		cin >> x;
		num += x * x;
	}
	cout << num % 10 << '\n';
}