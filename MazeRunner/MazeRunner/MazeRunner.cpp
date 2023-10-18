#include <iostream>
#include <queue>
#define MAX_N 55
using namespace std;

struct Robot {
	int y;
	int x;
	int di;
};
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

queue<Robot> q;
int arr[MAX_N][MAX_N];
int ans;

int main() {
	int n, m;
	cin >> n >> m;
	int ry, rx, rd;
	cin >> ry >> rx >> rd;
	Robot r = { ry+1, rx+1,rd };
	//for (int i = 1; i <= n; i++) {
	//	for (int j = 1; j <= m; j++) {
	//		cin >> arr[i][j];
	//	}
	//}
	arr[ry + 1][rx + 1] = 3;
	ans += 1;
	
	q.push(r);
	
	while (!q.empty()) {
		
		int cy =  q.front().y;
		int cx = q.front().x;
		int cd = q.front().di;
		if (arr[cy][cx] == 0) {
			arr[cy][cx] = 3;
			ans += 1;
		}
		cout << endl;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cout << arr[i][j] << " ";
			}cout << endl;
		}cout << endl;
		
		
		int flag = 1;
		int flag2 = 0;
		int flag3 = 0;
		int nd = cd + 1; // 북0, 동1, 남2, 서3 -> 동1, 남2, 서3, 북0 
		if (nd >= 4) { nd = 0; }
		
		q.pop();
			
		if (flag) {
			if (nd == 0) { //북쪽
				if (1 <= cy - 1 && cy - 1 <= n && 1 <= cx && cx <= m && arr[cy - 1][cx] == 0) {
					flag2 = 1;
					q.push({ cy - 1,cx, nd });
					
				}
			}
			else if (nd == 1) { //동
				if (1 <= cy && cy <= n && 1 <= cx - 1 && cx - 1 <= m && arr[cy][cx - 1] == 0) {
					q.push({ cy,cx - 1, nd });
					flag2 = 1;
				}
			}
			else if (nd == 2) { //남
				if (1 <= cy + 1 && cy + 1 <= n && 1 <= cx && cx <= m && arr[cy + 1][cx] == 0) {
					q.push({ cy + 1,cx, nd });
					flag2 = 1;
				}
			}
			else { //서
				if (1 <= cy && cy <= n && 1 <= cx + 1 && cx + 1 <= m && arr[cy][cx + 1] == 0) {
					q.push({ cy ,cx + 1, nd });
					flag2 = 1;
				}
			}
		}

		if (flag2 == 0) {
			int flag3 = 0;
			//청소할수 있는 경우 검사
			for (int i = 0; i < 4; i++) {
				int ny = cy + dy[i];
				int nx = cx + dx[i];
				//청소할수있는경우
				if (1 <= ny <= n && 1 <= nx <= m && arr[ny][nx] == 0) {
					flag3 = 1;
					q.push({ cy, cx, nd });
					break;

				}
			}


			if (flag3 == 0) { //청소 못하는 경우
				int by = cy;
				int bx = cx;
				if (cd == 0) { // 북쪽
					by += 1;
					if (1 <= by && by <= n && 1 <= bx && bx <= m && arr[by][bx] != 1) {
						q.push({ by,bx,cd });
					}
				}
				else if (cd == 1) { //동쪽
					bx += 1;
					if (1 <= by && by <= n && 1 <= bx && bx <= m && arr[by][bx] != 1) {
						q.push({ by,bx,cd });
					}
				}
				else if (cd == 2) { //남쪽
					by -= 1;
					if (1 <= by && by <= n && 1 <= bx && bx <= m && arr[by][bx] != 1) {
						q.push({ by,bx,cd });
					}
				}
				else { // 서쪽
					bx -= 1;
					if (1 <= by && by <= n && 1 <= bx && bx <= m && arr[by][bx] != 1) {
						q.push({ by,bx,cd });
					}
				}
			}
		}
	}
	//for (int i = 1; i <= n; i++) {
	//		for (int j = 1; j <= m; j++) {
	//			cout << arr[i][j] << " ";
	//		}cout << endl;
	//	}cout << endl;
	//	

	cout << ans;
}