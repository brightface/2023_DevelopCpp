#include <iostream>
#include <queue>
using namespace std;
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };

struct info {
    int num;
    char k;
};

int main() {

    queue<info> que;
    info i, int a, int b;

    cin >> a >> b;
    i.num = a;
    i.k = b;
    que.push(i);
    while (!que.empty()) {

    }

}