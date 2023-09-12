#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

bool check[1010];
bool check2[1010];
int order[1010];
int order_len;
int clk = 1;
int group[1010];
int group_cnt = 1;
int t[1010];
int n, m;
vector<int> List[1010];
vector<int> reverseList[1010];

void get_time(int node) {
	check[node] = true;
	for (int i = 0; i < List[node].size(); i++) {
		int cur = List[node][i];
		if (check[cur] == false) {
			get_time(cur);
		}
	}
	//t[node] = clk++;
	order[order_len++] = node;
}

void get_groupCnt(int node) {
	check2[node] = true;
	group[node] = group_cnt;

	for (int i = 0; i < List[node].size(); i++) {
		// for (int i = 0; i<reverseList[node].size(); i++){
		  // int cur = reverseList[node][i];
		  // if(check2[cur] == false){
		  //   get_groupCnt(cur);
		  // }
		int cur = List[node][i];
		if (!check2[cur]) get_groupCnt(cur);
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		List[a].push_back(b);
		reverseList[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		if (!check[i]) {

			get_time(i);
		}
	}
	for (int i = order_len - 1; i >= 0; i--) {
		//여기가 노드가 들어가야하는것 아닌가
		//맞네
		if (!check2[order[i]])
		{
			get_groupCnt(order[i]);
			group_cnt++;//여기있어야해 밖에 있으면 안돼
		}

	}
	// for(int i=0; i<=n; i++){
	//   cout<<order[i]<<" ";
	// }cout<<endl;

	// for(int i=0; i<=n; i++){
	//   cout<<group[i]<<" ";
	// }cout<<endl;
	cout << group_cnt - 1;
	return 0;
}