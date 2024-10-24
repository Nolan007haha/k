#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &stk, int element) {
    if (stk.empty()) {
        stk.push(element);
    } else {
        int topElement = stk.top();
        stk.pop();
        insertAtBottom(stk, element);
        stk.push(topElement);
    }
}

void reverseStack(stack<int> &stk) {
    if (!stk.empty()) {
        int topElement = stk.top();
        stk.pop();
        reverseStack(stk);
        insertAtBottom(stk, topElement);
    }
}

void printStack(stack<int> stk) {
    while (!stk.empty()) {
        cout << stk.top() << " ";
        stk.pop();
    }
    cout << endl;
}

int main() {
    stack<int> stk;
    int n, element;

    cout << "Enter the number of elements in the stack: ";
    cin >> n;

    cout << "Enter the elements from top to bottom:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> element;
        stk.push(element);
    }

    cout << "Original Stack (from top to bottom): ";
    printStack(stk);

    reverseStack(stk);

    cout << "Reversed Stack (from top to bottom): ";
    printStack(stk);

    return 0;
}
