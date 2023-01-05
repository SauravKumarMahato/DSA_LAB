#include<iostream>

using namespace std;

void toh(int disks, char A , char C , char B ) {
    if ( disks == 1 ) {
        cout << "Move disks from " << A << " to " << C << endl;
    }
    else{
        toh( disks - 1, A, B, C);
        toh( 1 , A , C , B);
        toh ( disks - 1, B , C , A );
    }

}

int main(){
    int disks = 0;
    cout<< "\nEnter the number of disks to move from source(A)\n to destination(c) using auxiliary (B):" ;    
    cin >> disks ;
    toh(disks, 'A', 'C', 'B' );
    return 0;
}