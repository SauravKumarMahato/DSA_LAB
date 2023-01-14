#include <iostream>
using namespace std;

class LinkedList
{
    class Node
    {
    public:
        double data;
        Node *next;
        Node *prev;
        Node(double data)
        {
            this->data = data;
            this->next = nullptr;
            this->prev = nullptr;
        }
    };

    Node *start;

public:
    LinkedList()
    {
        start = nullptr;
    }

    void ins_at_beg(float data)
    {
        Node *newNode = new Node(data);
        if (start == nullptr)
            start = newNode;
        else
        {
            newNode->next = start;
            start->prev = newNode;
            start = newNode;
        }
    }

    void ins_at_end(float data)
    {
        Node *newNode = new Node(data);
        if (start == nullptr)
            start = newNode;
        else
        {
            Node *temp = start;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    void ins_after_nth_node(int nth_node, float data)
    {
        Node *newNode = new Node(data);
        Node *temp = start;
        int count = 1;
        while (count < nth_node)
        {
            temp = temp->next;
            count++;
        }
        newNode->next = temp->next;
        temp->next->prev = newNode;
        temp->next = newNode;
        newNode->prev = temp;
    }

    void ins_bef_nth_node(int nth_node, float data)
    {
        Node *newNode = new Node(data);
        Node *temp = start;
        if (nth_node == 1)
        {
            newNode->next = temp;
            start = newNode;
        }
        else
        {
            int count = 1;
            while (count < nth_node - 1)
            {
                temp = temp->next;
                count++;
            }

            newNode->next = temp->next;
            temp->next->prev = newNode;
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    void del_from_beg()
    {
        Node *temp = start;
        start = start->next;
        delete temp;
        start->prev = nullptr;
    }

    void del_from_end()
    {
        Node *temp = start;
        while (temp->next->next != nullptr)
            temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
    }

    void del_aft_nth_node(int nth_node)
    {
        Node *temp = start;
        int count = 1;
        while (count < nth_node)
        {
            temp = temp->next;
            count++;
        }
        Node *remove = temp->next;
        temp->next = temp->next->next;
        remove->next->prev = temp;
        delete remove;
    }

    void del_bef_nth_node(int nth_node)
    {
        Node *temp = start;
        int count = 1;
        while (count <=  nth_node - 3 )
        {
            temp = temp->next;
            count++;
        }
        Node *remove = temp->next;
        temp->next = temp->next->next;
        remove->next->prev = temp;
        delete remove;
    }

    void display()
    {
        if (start != nullptr)
        {
            Node *temp = start;
            while (temp->next != nullptr)
            {
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << temp->data << endl;
        }
        else
            cout << "Linked List is empty" << endl;
    }
};

int main()
{
    LinkedList l;
    l.ins_at_end(500);
    l.display();
    l.ins_at_beg(10);
    l.display();
    l.ins_at_beg(2);
    l.display();
    l.ins_at_end(60);
    l.display();
    l.ins_after_nth_node(3, 1000);
    l.display();
    l.ins_after_nth_node(1, 83);
    l.display();
    l.ins_bef_nth_node(4, 983);
    l.display();
    l.ins_bef_nth_node(1, 93);
    l.display();
    l.del_from_beg();
    l.display();
    l.del_from_end();
    l.display();
    l.del_aft_nth_node(3);
    l.display();
    l.del_bef_nth_node(4);
    l.display();
    return 0;
}
