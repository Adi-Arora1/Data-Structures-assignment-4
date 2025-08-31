#include <iostream>
using namespace std;

class CircularQueue {
    int *arr, front, rear, size;
public:
    CircularQueue(int n) {
        arr = new int[n];
        size = n;
        front = rear = -1;
    }
    bool isEmpty() { return front == -1; }
    bool isFull() { return (rear + 1) % size == front; }

    void enqueue(int x) {
        if (isFull()) { cout << "Queue Full\n"; return; }
        if (isEmpty()) front = 0;
        rear = (rear + 1) % size;
        arr[rear] = x;
    }

    void dequeue() {
        if (isEmpty()) { cout << "Queue Empty\n"; return; }
        if (front == rear) front = rear = -1;
        else front = (front + 1) % size;
    }

    void peek() {
        if (isEmpty()) cout << "Queue Empty\n";
        else cout << "Front: " << arr[front] << endl;
    }

    void display() {
        if (isEmpty()) { cout << "Queue Empty\n"; return; }
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

int main() {
    int n, choice, val;
    cout << "Enter size of circular queue: ";
    cin >> n;
    CircularQueue cq(n);

    do {
        cout << "\n1.Enqueue 2.Dequeue 3.Peek 4.Display 5.Exit\n";
        cin >> choice;
        switch (choice) {
            case 1: cin >> val; cq.enqueue(val); break;
            case 2: cq.dequeue(); break;
            case 3: cq.peek(); break;
            case 4: cq.display(); break;
        }
    } while (choice != 5);
}
