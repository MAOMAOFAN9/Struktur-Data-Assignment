#include "queue1.h"
#include "queue1.cpp"
#include <iostream>

using namespace std;

int main()
{
    cout << "Hello World" << endl;
    queue Q;
    createQueue(Q);

    cout << "----------------------" << endl;
    cout << " H- T \t | Queue info" << endl;
    cout << "----------------------" << endl;
    printInfo(Q);
    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    dequeue(Q);    printInfo(Q);
    dequeue(Q);    printInfo(Q);
    enqueue(Q, 4); printInfo(Q);
    dequeue(Q);    printInfo(Q);
    dequeue(Q);    printInfo(Q);

    return 0;
}