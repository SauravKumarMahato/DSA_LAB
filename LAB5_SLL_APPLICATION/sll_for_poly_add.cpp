/**

 *	 @author: Saurav Kumar Mahato
 *	 @desc: Polynomial addition using singly linked list
 *	 @time: Friday 27-January-2023 20:06:12
 
**/

#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;

class Node
{
public:
    float data;
    float  expo ;
    Node *next;
    Node(float data, float expo)
    {
        this->data = data;
        this->expo = expo ;
    }
};

class LinkedList
{
public:
    Node *start;
    LinkedList()
    {
        this->start = nullptr;
    }

    void insAtEnd(float  value, float coef)
    {
        if (start == nullptr)
        {
            Node *new_node = new Node(value, coef);
            new_node->next = nullptr;
            start = new_node;
        }
        else
        {
            Node *new_node = new Node(value, coef);
            Node *ptr = start;
            while (ptr->next != nullptr)
                ptr = ptr->next;
            ptr->next = new_node;
            new_node->next = nullptr;
        }
    }


    void printList()
    {
        Node *ptr = start;
        while (ptr != nullptr)
        {
            cout << ptr->data << " x^( " << ptr->expo << " ) " ;
            if (ptr->next != nullptr)
                cout << " + ";
            ptr = ptr->next;
        }
        cout << "\n";
    }

    void fill_data(){
        int n =  0;
        cout << "enter the no of terms in polynomial: ";
        cin >> n ;
        double coef, expo = 0 ;
        cout << "enter data in decreaing exponenet" << endl;
        cout << "enter coef and exponent: " << endl;
        while ( n > 0)  {
            cin >> coef;
            cin >> expo ;
            this->insAtEnd(coef, expo) ;   
            n--;
         }
    }
};


int main(){
    LinkedList l, l1, l2;
    l.fill_data();
    l.printList();
    l1.fill_data();
    l1.printList();
    
    // calculating sum 
    Node * first_node = l.start ;
    Node * second_node = l1.start;
    
    // Arranging polynomial in ascending order 
    while( first_node->next != nullptr || second_node->next != nullptr ){
            if ( first_node->expo == second_node->expo ){
                l2.insAtEnd(first_node->data + second_node->data, first_node->expo);
                second_node = second_node->next ;
                first_node = first_node->next ; 
            }
            else{
                if ( first_node->expo > second_node->expo ){
                    l2.insAtEnd(first_node->data, first_node->expo);
                    first_node = first_node->next ;
                }
                else{
                    l2.insAtEnd(second_node->data, second_node->expo);
                    second_node = second_node->next ;
                }
            }
       
    }
    // For last node
    if ( first_node->expo == second_node->expo )
        l2.insAtEnd(first_node->data + second_node->data, first_node->expo);
    else{
        if ( first_node->expo > second_node->expo )
            l2.insAtEnd(first_node->data, first_node->expo);
        else
            l2.insAtEnd(second_node->data, second_node->expo);
    }
    
    l2.printList();

    return 0;
}