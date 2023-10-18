// Ericson.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string join_date = "2023/12/01/SUN";
string resign_date = "2025/12/31";
vector<string> holidays = { "12/24", "12/25" };
vector<pair<int, int>> hol;

string j_y, j_m, j_d, j_k;
string r_y, r_m, r_d;

int cy, cm, cd, ck;
int j_yy, j_mm, j_DD, j_dd;
int r_yy, r_mm, r_DD, r_dd;
int answer;
//int 
bool resign_check(int cy, int cm, int cd) {
	if (r_yy == cy && r_mm == cm && r_DD == cd) {
		return false;
	}
	return true;
}

bool holi_k(int ck) {
	if (ck == 5 || ck == 6) return true;
	return false;
}

bool holi_check(int cm, int cd) {
	for (int i = 0; i < size(hol); i++) {
		if (hol[i].first == cm && hol[i].second == cd) {
			return true;
		}
	}
	return false;
}

bool checkYear(int year) {
	if (year % 400 == 0) return true;
	if (year % 4 == 0 && year % 100 != 0) return true;
	return false;
}
void cal() {

	if (cm == 1 || cm == 3 || cm == 5 || cm == 7 || cm == 8 || cm == 10 || cm == 12) {
		if (cd > 31) {
			cd = 1;
			cm += 1;
			if (cm > 12) {
				cm = 1; cy += 1;
			}
		}
	}
	else if (cm == 4 || cm == 6 || cm == 9 || cm == 11) {
		if (cd > 30) {
			cd = 1;
			cm += 1;
		}
	}
	else {
		if (cm == 2) {
			if (checkYear(cy)) {
				if (cd > 29) {
					cd = 1;
					cm += 1;
				}
			}
			else {
				if (cd > 28) {
					cd = 1;
					cm += 1;
				}
			}
		}
	}
	if (ck > 6) ck = 0;
}
int main()
{

	for (int i = 0; i < size(holidays); i++) {
		string h_m = "";
		string h_d = "";
		for (int j = 0; j < 3; j++) {
			h_m += holidays[i][j];
		}
		for (int j = 3; j < 5; j++) {
			h_d += holidays[i][j];
		}
		int hm = stoi(h_m);
		int hd = stoi(h_d);
		hol.push_back(make_pair(hm, hd));
	}
	
	for (int i = 0; i < 4; i++) {
		j_y += join_date[i];
	}
	j_yy = stoi(j_y);
	for (int i = 5; i < 7; i++) {
		j_m += join_date[i];
	}
	j_mm = stoi(j_m);
	for (int i = 8; i < 10; i++) {
		j_d += join_date[i];
	}
	j_DD = stoi(j_d);
	for (int i = 11; i < 14; i++) {
		j_k += join_date[i];
	}
	if (j_k == "MON") {
		j_dd = 0;
	}
	else if (j_k == "TUE") {
		j_dd = 1;
	}
	else if (j_k == "WED	") {
		j_dd = 2;
	}
	else if (j_k == "THU") {
		j_dd = 3;
	}
	else if (j_k == "FRI") {
		j_dd = 4;
	}
	else if (j_k == "SAT") {
		j_dd = 5;
	}
	else if (j_k == "SUN") {
		j_dd = 6;
	}
	//resign process
	for (int i = 0; i < 4; i++) {
		r_y += resign_date[i];
	}
	r_yy = stoi(r_y);
	for (int i = 5; i < 7; i++) {
		r_m += resign_date[i];
	}
	r_mm = stoi(r_m);
	for (int i = 8; i < 10; i++) {
		r_d += resign_date[i];
	}
	r_DD = stoi(r_d);
	cy = j_yy;
	cm = j_mm;
	cd = j_DD;
	ck = j_dd;
	int cnt = 1;

	while (resign_check(cy,cm,cd)) {
		//휴일이면 넘긴다.
		if ((holi_k(ck) || holi_check(cm, cd))) {
			cd += 1;
			ck += 1;
			cal();
		}
		else {
			cd += 1;
			ck += 1;
			cnt += 1; //일 하는날
			cal();
		}
		

	}

	//휴일이었으면 그냥 나온다. 은퇴날도 일하는 날이기 때문에 마지막에 +1 해준다.
	if (holi_k(ck) || holi_check(cm, cd)) {
		answer = cnt;
	}
	else {
		answer = cnt + 1;
	}
	cout << answer;
}
