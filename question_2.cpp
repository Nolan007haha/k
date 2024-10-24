#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void printNGE(vector<int>& arr) {
    stack<int> s;
    vector<int> nge(arr.size(), -1);

    for (int i = 0; i < arr.size(); i++) {
        while (!s.empty() && arr[s.top()] < arr[i]) {
            nge[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " --> " << nge[i] << endl;
    }
}

int main() {
    vector<int> arr;
    int n, element;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the elements:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> element;
        arr.push_back(element);
    }

    cout << "Next Greater Elements are:" << endl;
    printNGE(arr);

    return 0;
}
