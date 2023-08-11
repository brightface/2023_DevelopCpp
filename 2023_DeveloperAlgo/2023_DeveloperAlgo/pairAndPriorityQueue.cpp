#include <iostream>
#include <queue>
using namespace std;

int main() {
	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> arr;
	arr.push(make_pair(1,2));
	arr.push(make_pair(2,3));
	arr.push(make_pair(3, 4));
	arr.push({ 5,7 });
	arr.push({ 2,2 });
	while (!arr.empty()) {
		cout<<arr.top().first << " " << arr.top().second<<endl;
		arr.pop();
	}
}