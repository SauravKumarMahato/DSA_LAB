#include <iostream>
#include <cstring>
#define MAX 100

using namespace std;

template <class T>
class Stack
{
private:
    int top;
    T str[MAX];

public:
    Stack();
    T pop();
    void push(T data);
    bool isEmpty();
    bool isFull();
    void display();
    T getTop();
};

template <class T>
Stack<T>::Stack()
{
    top = -1;
}

template <class T>
bool Stack<T>::isFull()
{
    if (top == (MAX - 1))
        return true;
    else
        return false;
}

template <class T>
bool Stack<T>::isEmpty()
{
    if (top == -1)
        return true;
    else
        return false;
}

template <class T>
void Stack<T>::push(T data)
{
    if (isFull())
        throw "stack is full, cannot push ";
    else
        str[++top] = data;
}

template <class T>
T Stack<T>::pop()
{
    if (isEmpty())
        throw "stack is empty, cannot pop ";
    else
        return str[top--];
}

template <class T>
void Stack<T>::display()
{
    for (size_t i = 0; i <= top; i++)
        cout << "a" << i << "=" << str[i] << endl;
    cout << endl;
}

template <class T>
T Stack<T>::getTop()
{
    return str[top];
}

// End of class

int main()
{

    try
    {
        Stack<float> s1;
        s1.push(12.45);
        s1.push(23.34);
        s1.display();
        s1.pop();
        s1.display();
        s1.pop();
        s1.pop();
    }
    catch (const char *err)
    {
        cout << err << endl;
    }

    return 0;
}