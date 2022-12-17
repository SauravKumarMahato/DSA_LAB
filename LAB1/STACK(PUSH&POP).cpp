#include<iostream>
#define MAX 100
using namespace std;
// (A+(B*C-(D/E^F)*G)*H)

template <class T>
class Stack{

private:
    int top;
    T str[MAX];

public:
    Stack();
    T pop();
    void push( T data );
    bool isEmpty();
    bool isFull();
    void display();


};
    template <class T>
    Stack<T>::Stack(){
        top = -1; 
    }

    template <class T> 
    bool Stack<T>::isFull(){
        if (top == (MAX-1) ){ return true ; }
        else{ return false; }
    }

    template <class T> 
    bool Stack<T>::isEmpty(){
        if (top == -1 ){ return true ; }
        else{ return false; }
    }

    template <class T>
    void Stack<T>::push( T data ){
        if (isFull()) {
            cout<< "stack is full, cannot push "<< endl;
        }
        else{
            str[++top] = data ; 
        }
    }

    template <class T>
    T Stack<T>::pop(){
        if (isEmpty()) {
            cout<< "stack is empty, cannot pop "<< endl;
        }
        else{
            cout<< "pop element= "<< str[top] << endl;
            return str[top--]; 
        }
    }

    template <class T>
    void Stack<T>::display(){
        for (size_t i = 0; i <=top; i++)
        {
            cout << "a" << i << "="<< str[i] << endl;
        }
        cout<<endl;
        
    }


int main()
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

