#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#define WRONG { printf("WA"); exit(1); }
#define CORRECT {printf("AC"); exit(0); }
using namespace std;

const int MX = 105;

int D[MX][MX], E[MX][MX];

int main()
{
	
		int n = 100;
		cout << n << '\n';
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				if (x == y) cout << 0 << ' ';
				else if (y == n - 1 || x == n - 1) cout << 4999 << ' ';
				else cout << 10000 << ' ';
			}
			cout << endl;
		}
	
}
