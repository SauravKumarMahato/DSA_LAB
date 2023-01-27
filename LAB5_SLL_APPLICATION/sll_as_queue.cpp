#include <iostream>
using namespace std;

class LinkedList
{
    class Node
    {
    public:
        float data;
        Node *next;

        Node(float data)
        {
            this->data = data;
            this->next = nullptr;
        }
    };

    Node *start;

public:
    LinkedList()
    {
        start = nullptr;
    }

    void pop(){
        Node *temp = start;
        while ( temp->next->next != nullptr ){
            temp = temp->next ;
        }
        temp->next = nullptr ;
    }

    void push(float val){
        Node *new_node = new Node(val);
        Node *temp = start;
        if( start == nullptr ){
            start = new_node ;
            new_node->next = nullptr ;
        }
        else{
            while( temp->next != nullptr )
                temp = temp->next ;
            temp->next = new_node ;
            new_node->next = nullptr;
        }

    }

    void get_top(){
        Node *temp ;
        while ( temp->next != nullptr ){
            temp = temp->next ;
        }
        cout<< "Top = " << temp->data ;
    }

    void display()
    {
        if (start != nullptr)
        {
            Node *temp = start;
            while (temp->next != nullptr)
            {
                cout << temp->data << "  ";
                temp = temp->next;
            }
            cout << temp->data << endl;
        }
        else
        {
            cout << "Linked List is empty" << endl;
        }
    }
};

int main()
{
    LinkedList l;

    l.push(20);
    l.display();
    l.push(21);
    l.display();
    l.push(22);
    l.display();
    l.push(23);
    l.display();
    /*
    l.pop();
    l.display();
    l.pop();
    l.display();
    */
    l.get_top();
    return 0;
}
