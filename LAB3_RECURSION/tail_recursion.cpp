#include<iostream>
using namespace std;

int fibo ( int n, int a , int b  ) {
    if ( n == 0 ) 
        return a ; 
    else if (  n == 1 )
        return b ;   
    else 
        return fibo(n-1 , b, a + b)  ;
}
int fibo_tail(int n ){  return fibo( n , 0, 1 ); }

int fact( int n , int a ) {
    if ( n == 0 ) 
        return a; 
    else 
        return fact( n-1 , n*a ) ;
}     
int fact_tail(int n ){  return fact( n , 1 ); }

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


