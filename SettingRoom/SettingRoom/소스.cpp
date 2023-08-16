#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

map<long long, long long> arr;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		long long a, b;
		cin >> a >> b;
		arr[a]++;
		arr[b]--;
	}

	long long current_count = 0;
	long long mx = 0;

	for (const auto& pair : arr) {
		current_count += pair.second;
		mx = max(mx, current_count);
	}

	cout << mx;

	return 0;
}
