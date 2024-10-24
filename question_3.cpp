#include <iostream>
#include <deque>
#include <vector>
using namespace std;

void printFirstNegativeInteger(vector<int>& arr, int k) {
    deque<int> dq;
    int n = arr.size();
    for (int i = 0; i < k; i++) {
        if (arr[i] < 0) {
            dq.push_back(i);
        }
    }
    for (int i = k; i <= n; i++) {
        if (!dq.empty()) {
            cout << arr[dq.front()] << " ";
        } else {
            cout << 0 << " ";
        }
        while (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }
        if (i < n && arr[i] < 0) {
            dq.push_back(i);
        }
    }
    cout << endl;
}

int main() {
    vector<int> arr;
    int n, k, element;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the elements:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> element;
        arr.push_back(element);
    }

    cout << "Enter the value of k: ";
    cin >> k;

    cout << "First negative integers for each window of size " << k << ":" << endl;
    printFirstNegativeInteger(arr, k);

    return 0;
}
