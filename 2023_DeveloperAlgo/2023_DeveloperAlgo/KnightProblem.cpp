#include <iostream>
#include <queue>
using namespace std;

int dy[8] = { 2, 1, -1, -2, -2, -1, 1,  2 };
int dx[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
struct info {
	int y, x, cnt;
};

int main() {
	int testCases;
	cin >> testCases;

	while (testCases--) {
		int mapSize, ky, kx, ay, ax = 0;
		cin >> mapSize>>ky>>kx>>ay>>ax;
		vector<vector<int>> check(mapSize, vector<int>(mapSize, 0));
		queue<info> que;
		info k;
		k.y = ky;
		k.x = kx;
		k.cnt = 0;
		que.push(k);
		while (!que.empty()) {
			int cy = que.front().y;
			int cx = que.front().x;
			int ccnt = que.front().cnt;
			que.pop();
			if (cy == ay && cx == ax) {
				cout << ccnt<< endl;
				break;
			}
			else {
				for (int i = 0; i < 8; i++) {
					int ny = cy + dy[i];
					int nx = cx + dx[i];
					int ncnt = ccnt + 1;
					if (ny >= 0 && ny < mapSize && nx >= 0 && nx < mapSize && check[ny][nx] == 0) {
						info w = { ny, nx, ncnt };
						check[ny][nx] = 1;
						que.push(w);
					}
				}
			}
		}
	}
}