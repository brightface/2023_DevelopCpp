#include <iostream>
#include <queue>
using namespace std;

int main() {
	int testCases;
	cin >> testCases;
	while (testCases--) {
		long long n = 0;
		cin >> n;

		// �ִ��� - �ּҰ� ���� �Ϸ��� - �־� ���� (���̽��� �ּ���)
		priority_queue<long long> arr;
		for (long long i = 0; i < n; i++) {
			long long t;
			cin >> t;
			arr.push(-t);
		}
		long long s = 0;
		//���������� ���̶� iterator ���Ұ�.(�������) �׷��� ���ͷ� �����ؼ� ���.
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
