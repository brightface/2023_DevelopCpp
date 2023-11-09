#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n, m;
vector<string> arr;
int dy[] = { 0, 0, -1, 1 };
int dx[] = { 1, -1, 0, 0 };
int d[26];
int cnt = 65;
int ans = 0;
int mx = -1;

void dfs(int y, int x, vector<vector<int>>& check) {
    if (check[y][x] == 1) {
        return;
    }
    else {
        if (d[arr[y][x] - 'A'] == 1) {
            return;
        }
        else {
            if (check[y][x] == 0) {
                check[y][x] = 1;
                d[arr[y][x] - 'A'] = 1;
                ans += 1;
                if (mx < ans) {
                    mx = ans;
                }
                for (int i = 0; i < 4; i++) {
                    int ny = y + dy[i];
                    int nx = x + dx[i];
                    if (0 <= ny && ny < n && 0 <= nx && nx < m && !(ny == 0 && nx == 0)) {
                        if (d[arr[ny][nx] - 'A'] == 0 && check[ny][nx] == 0) {
                            dfs(ny, nx, check);
                        }
                    }
                }
                d[arr[y][x] - 'A'] = 0;
                check[y][x] = 0;
                ans -= 1;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    arr.resize(n);

    for (int i = 0; i < 26; i++) {
        d[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<vector<int>> check(n + 1, vector<int>(m + 1, 0));

    dfs(0, 0, check);

    cout << mx << endl;

    return 0;
}