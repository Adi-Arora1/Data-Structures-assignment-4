#include <iostream>
using namespace std;

class Queue {
    int *arr, front, rear, size, capacity;
public:
    Queue(int c) {
        capacity = c;
        arr = new int[c];
        front = rear = 0;
        size = 0;
    }
    bool isEmpty() { return size == 0; }
    bool isFull() { return size == capacity; }

    void enqueue(int x) {
        if (isFull()) { cout << "Queue Full\n"; return; }
        arr[rear] = x;
        rear = (rear + 1) % capacity;
        size++;
    }

    void dequeue() {
        if (isEmpty()) { cout << "Queue Empty\n"; return; }
        front = (front + 1) % capacity;
        size--;
    }

    void peek() {
        if (isEmpty()) cout << "Queue Empty\n";
        else cout << "Front: " << arr[front] << endl;
    }

    void display() {
        if (isEmpty()) { cout << "Queue Empty\n"; return; }
        int cnt = size, i = front;
        while (cnt--) {
            cout << arr[i] << " ";
            i = (i + 1) % capacity;
        }
        cout << endl;
    }
};

int main() {
    int n, choice, val;
    cout << "Enter size of queue: ";
    cin >> n;
    Queue q(n);

    do {
        cout << "\n1.Enqueue 2.Dequeue 3.Peek 4.Display 5.Exit\n";
        cin >> choice;
        switch (choice) {
            case 1: cin >> val; q.enqueue(val); break;
            case 2: q.dequeue(); break;
            case 3: q.peek(); break;
            case 4: q.display(); break;
        }
    } while (choice != 5);
}
