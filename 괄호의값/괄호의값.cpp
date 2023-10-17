#include <vector>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string arr = "";
	cin >> arr;
	vector<char> st;
	int ans = 0;
	int tmp = 1;
	for (int i = 0; i < size(arr); i++)
	{
		
		if (st.empty()) {
			if (arr[i] == ']' || arr[i] == ')') {
				ans = 0;
				break;
			}
		}
		
		if (arr[i] == '(') {
			tmp *= 2;
			st.push_back('(');
			int a = 1;
		}
		
		else if (arr[i] == '[') {
			tmp *= 3;
			st.push_back('[');
		}
		else if (arr[i] == ']') {
			if (arr[i - 1] == '[') {
				ans += tmp;
				tmp = int(tmp / 3); //[]
				if (!st.empty() && st[size(st) - 1] != '[') {
					ans = 0;
					break;
				}
				st.pop_back();
			}
			else { // arr[i-1] == '(', ']', ')'
				tmp = int(tmp / 3);
				
				if (!st.empty() && st[size(st) - 1] != '[' || st.back() == '(') { //st = (] , st = (] st = []
					ans = 0;
					break;
				}
				else {
					st.pop_back(); // a[i-1] == '(' , ']'
					continue;
				}
			}
		}
		else { // )
			if (arr[i - 1] == '(') { //()
				ans += tmp;
				tmp = int(tmp / 2); //[]
				if (!st.empty() && st[size(st) - 1] != '(') {
					ans = 0;
					break;
				}
				st.pop_back();
			}
			else { //arr = [)
				tmp = int(tmp / 2);
				
				if (!st.empty() && st.back() != '(' || st.back() =='[') {
					ans = 0;
					break;
				}
				else {
					st.pop_back();
					continue;
				}
			}

		}
	}
	
	if (!st.empty()) ans = 0;
	cout << ans;
	
}

