#include "stack.h"

void createStack(Stack &S) {
    S.top = 0;
}

bool isEmpty(Stack S) {
    return S.top == 0;
}

bool isFull(Stack S) {
    return S.top == MAX;
}

void push(Stack &S, infotype x) {
    if (!isFull(S)) {
        S.top++;
        S.info[S.top] = x;
    } else {
        cout << "Stack penuh" << endl;
    }
}

int pop(Stack &S) {
    if (!isEmpty(S)) {
        int x = S.info[S.top];
        S.top--;
        return x;
    }
    return 0;
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    if (isEmpty(S)) {
        cout << "Kosong";
    } else {
        for (int i = S.top; i >= 1; i--) {
            cout << S.info[i] << " ";
        }
    }
    cout << endl;
}

void balikStack(Stack &S) {
    for (int i = 1; i <= S.top / 2; i++) {
        int t = S.info[i];
        S.info[i] = S.info[S.top - i + 1];
        S.info[S.top - i + 1] = t;
    }
}

void pushAscending(Stack &S, infotype x) {
    if (isEmpty(S) || x >= S.info[S.top]) {
        push(S, x);
    } else {
        int t = pop(S);
        pushAscending(S, x);
        push(S, t);
    }
}

void getInputStream(Stack &S) {
    char c;
    while (cin.get(c) && c != '\n') {
        if (c >= '0' && c <= '9') {
            int n = c - '0';
            push(S, n);
        }
    }
}
