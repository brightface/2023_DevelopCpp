#include <iostream>
#include <string>
#include <map>
#include <iomanip>
#include <cmath> // round 함수를 사용하기 위해 추가
using namespace std;

map<string, float> m;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string str;
    float cnt = 0;
    while (getline(cin, str)) {
        if (str == "") break;
        else {
            cnt++;
            m[str] += 1;
        }
    }
    cout << fixed;
    cout.precision(4);
    for (auto pa : m) {
        cout << pa.first << " ";
        cout << round(((pa.second / cnt) * 100) * 10000) / 10000 << endl;
    }
    cout << "1";
}
