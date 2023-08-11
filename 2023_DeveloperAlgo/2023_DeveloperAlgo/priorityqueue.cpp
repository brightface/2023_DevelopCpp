#include <iostream>
#include <queue>
using namespace std;

int main() {
	int testCases;
	cin >> testCases;
	while (testCases--) {
		long long n = 0;
		cin >> n;

		// 최대힙 - 최소값 부터 하려면 - 넣어 시작 (파이썬은 최소힙)
		priority_queue<long long> arr;
		for (long long i = 0; i < n; i++) {
			long long t;
			cin >> t;
			arr.push(-t);
		}
		long long s = 0;
		//내부적으로 힙이라서 iterator 사용불가.(순서대로) 그래서 벡터로 복사해서 사용.
		while (!arr.empty())
		{
			/*for (auto it = arr.; it != arr.end(); ++it) {

			}*/

			if (arr.size() <= 1) {
				//s += -(arr.top());
				break;
			}
			else {
				long long a, b, tmp = 0;
				a = -(arr.top());
				arr.pop();
				b = -(arr.top());
				arr.pop();
				tmp = a + b;
				arr.push(-tmp);
				s += tmp;
			}
		}
		cout << s << endl;
	
	}

}
