#include <iostream>
#include <queue>
using namespace std;

class Queue
{
    int *arr;
    int qfront;
    int rear;
    int size;

public:
    Queue()
    {
        size = 100001;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }

    bool isEmpty()
    {
        if (qfront == rear)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void enqueue(int data)
    {
        if (rear == size)
        {
            cout << "Queue us full " << endl;
        }
        else
        {
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue()
    {
        if (qfront == rear)
        {
            return -1;
        }
        else
        {
            int ans = arr[qfront];
            arr[qfront] = -1;
            qfront++;
            if (qfront == rear)
            {
                qfront = 0;
                rear = 0;
            }
            cout<<ans<<endl;
            return ans;
        }
    }

    int front()
    {
        if (qfront == rear)
        {
            return -1;
        }
        else
        {
            return arr[qfront];
        }
    }
};

int main()
{

    Queue q;

    q.enqueue(11);
    cout << "front of q is: " << q.front() << endl;

    q.enqueue(15);
    cout << "front of q is: " << q.front() << endl;

    q.enqueue(13);
    cout << "front of q is: " << q.front() << endl;
    // cout << "size of queue is : " << q.size() << endl;

    q.dequeue();
    q.dequeue();
    q.dequeue();

    // cout << "size of queue is : " << q.size() << endl;

    if (q.isEmpty())
    {
        cout << "Queue is empty " << endl;
    }
    else
    {
        cout << "queue is not empty " << endl;
    }

    return 0;
}