#include <iostream>
#define SIZE 5
using namespace std;

template <class T>
class LQueue
{
private:
    T str[SIZE];
    int front, rear;

public:
    LQueue()
    {
        front = 0;
        rear = -1;
    }

    bool isEmpty()
    {
        if (front == rear + 1)
            return true;
        else 
            return false;
    }

    bool isFull()
    {
        if (rear == SIZE - 1 )
            return true;
        else
            return false;
    }
    // Enqueue
    void enqueue(T elem)
    {
        if (isFull())
            throw "Queue is full";
        else
            str[++rear] = elem;
        cout << "enqueue successful" << endl;
    }
    // Dequeue
    T dequeue()
    {
        T temp;
        if (isEmpty())
            throw "Queue is empty";
        else
        {
            temp = str[front];
            front++;
        }
        return temp;
    }
};

int main()
{
    LQueue<int> q;
    try
    {
        for (size_t i = 0; i < SIZE; i++)
            q.enqueue(i);
        for (size_t i = 0; i < SIZE; i++)
            cout << q.dequeue()<< " ";
    }
    catch (const char *err)
    {
        cout << err;
    }

    return 0;
}