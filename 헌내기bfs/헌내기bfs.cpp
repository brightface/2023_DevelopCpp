#include <iostream>
#include <string>
#include <queue>
#include <cstring>
#define MAX_N 610
using namespace std;
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };
char arr[MAX_N][MAX_N];
int check[MAX_N][MAX_N];
struct Info {
	int y;
	int x;
};

int main() {
	int n, m;
	int sy, sx;
	string input;
	cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> input;
			for (int j = 0; j < m; j++) {
				arr[i][j] = input[j];
				if (arr[i][j] == 'I') {
					sy = i;
					sx = j;
				}
		}
	}
	queue<Info> q;
	int cnt = 0;
	q.push({ sy,sx });
	check[sy][sx] = 1;
	while (!q.empty()) {
		int cy = q.front().y;
		int cx = q.front().x;
		q.pop();
		if (arr[cy][cx] == 'P') {
			cnt += 1;
		}
		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (0 <= ny && ny < n && 0 <= nx && nx < m && arr[ny][nx] != 'X' && check[ny][nx] == 0) {
				check[ny][nx] = 1;
				q.push({ ny,nx });

			}
		}
	}
	if (cnt == 0) cout << "TT";
	else cout << cnt;
}