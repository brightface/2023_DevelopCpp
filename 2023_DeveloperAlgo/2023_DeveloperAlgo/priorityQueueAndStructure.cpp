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

//priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

int main() {
    priority_queue<Person, vector<Person>, greater<Person>> pq;

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