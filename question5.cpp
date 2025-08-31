#include <iostream>
#include <queue>
using namespace std;

// (a) Stack using two queues
class StackTwoQ {
    queue<int> q1, q2;
public:
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) { q2.push(q1.front()); q1.pop(); }
        swap(q1, q2);
    }
    void pop() { if (!q1.empty()) q1.pop(); }
    int top() { return q1.empty() ? -1 : q1.front(); }
    bool empty() { return q1.empty(); }
};

// (b) Stack using one queue
class StackOneQ {
    queue<int> q;
public:
    void push(int x) {
        q.push(x);
        for (int i = 0; i < (int)q.size() - 1; i++) {
            q.push(q.front()); q.pop();
        }
    }
    void pop() { if (!q.empty()) q.pop(); }
    int top() { return q.empty() ? -1 : q.front(); }
    bool empty() { return q.empty(); }
};

int main() {
    StackTwoQ s1; StackOneQ s2;
    s1.push(10); s1.push(20);
    cout << "StackTwoQ Top: " << s1.top() << endl;
    s1.pop();
    cout << "StackTwoQ Top after pop: " << s1.top() << endl;

    s2.push(5); s2.push(15);
    cout << "StackOneQ Top: " << s2.top() << endl;
    s2.pop();
    cout << "StackOneQ Top after pop: " << s2.top() << endl;
}
