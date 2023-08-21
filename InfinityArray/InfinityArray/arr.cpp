
#include <iostream>
#include <map>
using namespace std;

long long N, P, Q;

map<long long, long long> cache;



long long func(long long N)

{

	if (cache.count(N))

		return cache[N];

	else

		return cache[N] = func(N / P) + func(N / Q);

}



int main(void)

{

	ios_base::sync_with_stdio(0);

	cin.tie(0);

	cin >> N >> P >> Q;



	cache[0] = 1;

	cout << func(N) << "\n";

	return 0;

}