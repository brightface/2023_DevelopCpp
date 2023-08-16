
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

map<long long, long long> arr;

int main()
{
	int n = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		long long a, b;
		cin >> a >> b;
		for (long long j = a; j < b; j++) {
			auto iter = arr.find(j);
			if (iter != arr.end()) {
				arr[j] += 1;
			}
				
			else {
				arr[j] = 1;
			}
				
		}
	}
	long long mx= 0;
	for (const auto& pair : arr ) {
		if (mx < pair.second) {
			mx = pair.second;
		}
	}
	cout << mx;
}

