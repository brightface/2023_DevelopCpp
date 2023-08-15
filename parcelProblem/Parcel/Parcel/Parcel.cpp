// Parcel.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
using namespace std;

int MAP[205][205];
int dp[205][205];


int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			else dp[i][j] = 100000000;
		}
	}

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		MAP[a][b] = b;
		dp[a][b] = c;
		MAP[b][a] = a;
		dp[b][a] = c;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dp[i][j] > dp[i][k] + dp[k][j]) {
					dp[i][j] = dp[i][k] + dp[k][j];
					MAP[i][j] = MAP[i][k]; //걍 이어버린다. 새로운길 만들어버린다. dp로 계산한후
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (MAP[i][j] == 0) {
				cout << "- ";
			}
			else {
				cout << MAP[i][j] << " ";
			}
		}cout << endl;
	}
}
