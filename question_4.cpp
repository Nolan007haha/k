#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void interleaveQueue(queue<int>& q) {
    int n = q.size();
    vector<int> firstHalf, secondHalf;

    for (int i = 0; i < n / 2; i++) {
        firstHalf.push_back(q.front());
        q.pop();
    }

    while (!q.empty()) {
        secondHalf.push_back(q.front());
        q.pop();
    }

    for (int i = 0; i < n / 2; i++) {
        q.push(firstHalf[i]);
        q.push(secondHalf[i]);
    }
}

int main() {
    queue<int> q;
    int n, element;
    cout << "Enter the even number of elements : ";
    cin >> n;
    cout << "Enter the elements:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> element;
        q.push(element);
    }

    interleaveQueue(q);

    cout << "Interleaved Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
