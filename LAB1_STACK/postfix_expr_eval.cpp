#include <iostream>
#include <cstring>
#define MAX 100
// Q.N.     (A+(B*C-(D/E^F)*G)*H)
// ANSWER   ABC*DEF^/G*-H*+
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

int precedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return 0;
}

bool isOperator(char c)
{
    if (c == '^' || c == '+' || c == '-' || c == '*' || c == '/')
        return true;
    else
        return false;
}

int eval_postfix(string postfix)
{
    Stack<int> s;
    for (size_t i = 0; i < postfix.length(); i++)
    {
        if (postfix[i] >= '0' && postfix[i] <= '9')
            s.push(postfix[i] - '0');
        else if (isOperator(postfix[i]))
        {
            int op1 = s.pop();
            int op2 = s.pop();

            if (postfix[i] == '+')
                s.push(op2 + op1);
            else if (postfix[i] == '-')
                s.push(op2 - op1);
            else if (postfix[i] == '/')
                s.push(op2 / op1);
            else if (postfix[i] == '*')
                s.push(op2 * op1);
            else
            {
                throw "enter valid operator in expression ";
            }
        }
    }

    return s.pop();
}

int main()
{
    string postfix;
    cout << "Enter postfix expression to evaluate:  ";
    cin >> postfix;

    try
    {
        cout << "The required postfix evaluated expression is : \n"
             << eval_postfix(postfix);
    }
    catch (const char *err)
    {
        cout << err << endl;
    }

    return 0;
}
