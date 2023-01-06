#include <iostream>
using namespace std;

class Node
{
public:
    float data;
    Node *next;
};

void insAtBeg(float value, Node *start)
{
    // if ( start == NULL)
    //     cout<< "\nOVERFLOW ERROR!\n";
    // else{
    Node *new_node;
    new_node->data = value;
    new_node->next = NULL;
    start = new_node;
    // }
    cout << ("insAtBeg");
}

void insAtEnd(float value, Node *start)
{
    // if ( start == NULL)
    //     cout<< "\nOVERFLOW ERROR!\n";
    // else{
    Node *new_node;
    new_node->data = value;
    Node *ptr = start;
    while (ptr->next != NULL)
        ptr = ptr->next;
    new_node->next = NULL;
    ptr->next = new_node;
    // }
    cout << "insAtEnd";
}

void printlist(Node *start)
{
    Node *ptr = start;
    while (ptr->next != NULL)
        cout << ptr->data << " ";
}

int main()
{
    Node *start = NULL;
    insAtBeg(25, start);
    insAtEnd(45, start);
    cout << "hello wordl" << endl;
    printlist(start);
    return 0;
}
