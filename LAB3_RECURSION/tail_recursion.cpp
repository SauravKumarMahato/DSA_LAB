#include<iostream>
using namespace std;

int fibo_tail ( int n, int a = 0 , int b = 1 ) {
    if ( n == 0 ) 
        return a ; 
    else if (  n == 1 )
        return b ;   
    else 
        return fibo_tail(n-1 , b, a + b)  ;
}

int fact_tail( int n , int a = 1 ) {
    if ( n == 0 ) 
        return a; 
    else 
        return fact_tail( n-1 , n*a ) ;
}     

int main()
{
    int n = 0 ;
    cout<< "Enter the number of fibonacci to get: ";
    cin >> n ;

    cout << "The fibonacci series upto "<< n << " terms is : \n ";
    for ( int i = 0 ; i < n ; i++ ) {
        cout << fibo_tail(i) << " " ;       
    }
    
    cout << "\nThe factorial of " << n << " is " << fact_tail(n);
    return 0;
}


