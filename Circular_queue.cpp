#include <iostream>
#include <queue>
using namespace std;

class circularQueue
{
    int *arr;
    int front;
    int rear;
    int size;

public:
    // Initialize your data structure.
    circularQueue()
    {
        size = 100001;
        arr = new int[size];
        front = rear = -1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int data)
    {
        // to check whther queue is full
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)))
        {
            // cout << "Queue is Full";
            return false;
        }
        else if (front == -1) // first element to push
        {
            front = rear = 0;
        }
        else if (rear == size - 1 && front != 0)
        {
            rear = 0; // to maintain cyclic nature
        }
        else
        { // normal flow
            rear++;
        }
        // push inside the queue
        arr[rear] = data;

        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue()
    {
        if (front == -1)
        {   // to check queue is empty
            cout << "Queue is Empty " << endl;
            return -1;
        }

        int ans = arr[front];
        arr[front] = -1;

        if (front == rear)
        { 
            // single element is present
            front = rear = -1;
        }
        else if (front == size - 1)
        {
            front = 0; // to maintain cyclic nature
        }
        else
        { // normal flow
            front++;
        }
        cout<<"The Dequeued answer is infront of your MOFOS  "<< ans << endl;
        return ans;
    }
};

int main()
{
    circularQueue obj;
    // int n;
    // cout<<"enter the size of an array";
    // cin>>n;

    // circularQueue(n);


    cout << "front of q is 0 or 1 :  " <<obj.enqueue(11)<< endl;

    // obj.enqueue(15);
    cout << "front of q is 0 or 1 :  "<<obj.enqueue(15) << endl;

    // obj.enqueue(13);
    cout << "front of q is 0 or 1 :  "<<obj.enqueue(17) << endl;
    // cout << "size of queue is : " << q.size() << endl;

    obj.dequeue();
    obj.dequeue();
    obj.dequeue();
    obj.dequeue();

    // cout << "size of queue is : " << q.size() << endl;

    // if (obj.isEmpty())
    // {
    //     cout << "Queue is empty " << endl;
    // }
    // else
    // {
    //     cout << "queue is not empty " << endl;

    return 0;
}
