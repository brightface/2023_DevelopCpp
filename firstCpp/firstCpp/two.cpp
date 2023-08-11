#include <iostream>
#include <vector>
using namespace std;
//vector<int> dp0(100, 0);
long long int dp0[100] = { 0, 0, 1, 1, 2, 0, };
long long int dp1[100] = { 0, 1, 0, 1, 1, 0, };
int main() {
	int cnt;
	cin >> cnt;
	
	for (int i = 5; i < 100; i++) {
		dp0[i] = dp0[i - 1] + dp1[i - 1];
		dp1[i] = dp0[i - 1];
	}
	cout << dp0[cnt] + dp1[cnt];
}