#include <iostream>
#include "Double_linked_list.h"

using namespace std;

void ask();
void empty();
void push_front();
void push_back();
void pop_front();
void pop_back();
void erase();

DLL<int> l;

int main() {
    while (true) {
        ask();
        int q;
        cin >> q;
        if (q == 1) empty();
        else if (q == 2) push_front();
        else if (q == 3) push_back();
        else if (q == 4) pop_front();
        else if (q == 5) pop_back();
        else if (q == 6) erase();
        else if (q == 7) break;
        else cout << "incorrect command\n";
        cout << l << endl;
    }
}

void ask() {
    cout << "#####################\n";
    cout << "Choose one of the following comands (enter a number):\n";
    cout << "1) Check if array is empty\n";
    cout << "2) Add element to the beginning\n";
    cout << "3) Add element to the end\n";
    cout << "4) Delete first element\n";
    cout << "5) Delete last element\n";
    cout << "6) Delete first occurrence of element\n";
    cout << "7) End program\n";
}

void empty() {
    cout << (l.empty() ? "Yes" : "No") << endl;
}

void push_front() {
    cout << "Enter value:\n";
    int val;
    cin >> val;
    l.push_front(val);
}

void push_back() {
    cout << "Enter value:\n";
    int val;
    cin >> val;
    l.push_back(val);
}

void pop_front() {
    if (l.empty()) {
        cout << "Array is empty\n";
        return;
    }
    l.pop_front();
}

void pop_back() {
    if (l.empty()) {
        cout << "Array is empty\n";
        return;
    }
    l.pop_back();
}

void erase() {
    if (l.empty()) {
        cout << "Array is empty\n";
        return;
    }
    cout << "Enter value:\n";
    int val;
    cin >> val;
    if (!l.find(val)) {
        cout << "Value is not in the list\n";
        return;
    }
    l.erase(val);
}
