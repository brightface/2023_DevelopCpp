// InfinityArray.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <map>
using namespace std;
long long n, p, q;
map<long long, long long> arr;

long long  dfs(long long a) {
	if (arr.count(a)) 
		return arr[a];
	
	
	else 
		return arr[a] = dfs(n / p) + dfs(n / q);
	
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	arr[0] = 1;
	cin >> n >> p >> q;
	cout << dfs(n);
}
