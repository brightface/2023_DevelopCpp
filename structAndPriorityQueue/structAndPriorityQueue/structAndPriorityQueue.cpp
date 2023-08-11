#include <queue>
#include <iostream>
using namespace std;

struct Person {
    string name;
    int age;

    // '<' 연산자 오버로딩
    bool operator<(const Person& other) const {
        if (name != other.name) {
            return name > other.name;
        }
        else {
            return age > other.age;
        }
    }
    bool operator>(const Person& other) const {
        if (name != other.name) {
            return name < other.name;
        }
        else {
            return age < other.age;
        }
    }
};
struct cmp {
    bool operator()(pair<int, int>& a, pair<int, int>& b) {
        if (a.first == b.first) {
            return a.second > b.second;
        }
        else {
            return a.first < b.first;
        }
    }
};

priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pair_pq;


/*
위 코드에서는 > 연산자를 오버로딩하였고, greater 대신 사용자 정의 비교 함수 객체 ComparePerson을 사용하여 작은 것부터 나오도록 했습니다. 
이렇게 하면 우선순위 큐에서는 이름이 사전 순으로 낮은 사람이 먼저 나오게 됩니다.
*/
// 비교 함수 객체
struct ComparePerson {
    bool operator()( Person& a,  Person& b) {
        return a < b;
    }
};

int main() {
    //priority_queue<Person, vector<Person>, greater<Person>> pq;
    //greater로 Person 비교 안돼. 구조체안에 머랑 비교할꺼야 연산자 정해줘야돼. 그래서 ComparePerson 구조체로 연산자 정해줬다.
    priority_queue<Person, vector<Person>, ComparePerson> pq;

    pq.push({ "Alice", 25 });
    pq.push({ "Bob", 30 });
    pq.push({ "Charlie", 20 });
    pq.push({ "Alice", 20 });

    while (!pq.empty()) {
        cout << pq.top().name << " " << pq.top().age << endl;
        pq.pop();
    }

    return 0;
}