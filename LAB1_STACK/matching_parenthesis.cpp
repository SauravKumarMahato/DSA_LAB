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

bool check_parenthesis(string expr) {
    Stack<char> s;
    
    for (size_t i = 0; i < expr.length(); i++)
    {
        if( s.isEmpty() )
            s.push(expr[i]);
        else if( ( s.getTop() == '(' && expr[i] == ')' ) ||
            ( s.getTop() == '{' && expr[i] == '}' ) ||
            ( s.getTop() == '[' && expr[i] == ']' ) )
        {
            s.pop();
        }
        else{ continue; }
        
    }

    return ( s.isEmpty() ? true : false );
    
}

int main()
{
    string expression;
    cout << "Enter the expression for parenthesis check: ";
    cin >> expression;

    try{
        cout<< "The given expression has " << ( check_parenthesis(expression) ? "matching" : "no matching" ) << " parenthesis" << endl;
    }
    catch(const char *err){
        cout << err << endl;
    }
    

    return 0;
}
