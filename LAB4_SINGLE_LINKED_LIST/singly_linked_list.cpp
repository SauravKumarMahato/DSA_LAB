#include <iostream>
using namespace std;

template <class T>
class LinkedList
{
    template <class t>
    class Node
    {
    public:
        t data;
        Node<t> *next;

        Node(t data)
        {
            this->data = data;
        }
    };

    Node<T> *start;

public:
    LinkedList()
    {
        this->start = nullptr;
    }

    void insAtBeg(T value)
    {
        if (start == nullptr)
        {
            Node<T> *new_node = new Node<T>(value);
            new_node->next = nullptr;
            start = new_node;
        }
        else
        {
            Node<T> *new_node = new Node<T>(value);
            new_node->next = start;
            start = new_node;
        }
    }

    void insAtEnd(T value)
    {
        if (start == nullptr)
        {
            Node<T> *new_node = new Node<T>(value);
            new_node->next = nullptr;
            start = new_node;
        }
        else
        {
            Node<T> *new_node = new Node<T>(value);
            Node<T> *ptr = start;
            while (ptr->next != nullptr)
                ptr = ptr->next;
            ptr->next = new_node;
            new_node->next = nullptr;
        }
    }

    void delAtBeg()
    {
        if (start == nullptr)
        {
            cout << "Empty list, cannot delete ";
        }
        else
        {
            Node<T> *ptr = start;
            start = start->next;
            delete ptr;
        }
    }

    void delAtEnd()
    {
        if (start == nullptr)
        {
            cout << "Empty list, cannot delete ";
        }
        else
        {
            Node<T> *ptr = start;
            Node<T> *preptr = ptr;
            while (ptr->next != nullptr)
                preptr = ptr;
            ptr = ptr->next;
            preptr->next = nullptr;
            delete ptr;
        }
    }
    void insAfter(int position, T value)
    {
        if (start == nullptr)
        {
            Node<T> *new_node = new Node<T>(value);
            new_node->next = nullptr;
            start = new_node;
        }
        else
        {
            int count = 1;
            Node<T> *ptr = start;
            Node<T> *preptr = ptr;
            Node<T> *new_node = new Node<T>(value);
            while (count <= position)
            {
                preptr = ptr;
                ptr = ptr->next;
                count++;
            }
            preptr->next = new_node;
            new_node->next = ptr;
        }
    }

    void insBefore(int position, T value)
    {
        if (start == nullptr)
        {
            Node<T> *new_node = new Node<T>(value);
            new_node->next = nullptr;
            start = new_node;
        }
        else
        {
            if (position == 1) // Only one element in linked list
                insAtBeg(value);
            else
            {
                int count = 1;
                Node<T> *ptr = start;
                Node<T> *preptr = ptr;
                Node<T> *new_node = new Node<T>(value);
                while (count < position)
                {
                    preptr = ptr;
                    ptr = ptr->next;
                    count++;
                }
                preptr->next = new_node;
                new_node->next = ptr;
            }
        }
    }

    void printList()
    {
        Node<T> *ptr = start;
        while (ptr != nullptr)
        {
            cout << ptr->data;
            if (ptr->next != nullptr)
                cout << " -> ";
            ptr = ptr->next;
        }
        cout << "\n";
    }
};

int main()
{

    LinkedList<float> l;
    cout << "\n\nThe linked list in different state is given below: \n\n";

    l.insAtBeg(25);
    l.printList();
    l.insAtBeg(21);
    l.insAtEnd(45);
    l.printList();
    l.delAtBeg();
    l.printList();
    l.insAtEnd(20);
    l.insAtEnd(30);
    l.insAtEnd(40);
    l.insAtEnd(50);
    l.printList();
    l.insAfter(3, 55);
    l.printList();
    l.insBefore(3, 34);
    l.printList();
    l.insBefore(1, 9);
    l.printList();

    cout << "\n\n";
    return 0;
}
