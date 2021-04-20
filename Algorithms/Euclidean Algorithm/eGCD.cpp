#include <iostream>
using namespace std;

void bezoutCoefficient(long long A, long long B, long long* x, long long* y, long long* gcd) {
    if(B == 0) {
        (*gcd) = A;
        (*x) = 1;
        (*y) = 0;
    }
    else {
        bezoutCoefficient(B, A%B, x, y, gcd);
        long long temp = (*x);
        (*x) = (*y);
        (*y) = temp - (A/B) * (*y);
    }
    return;
}

int main( ) {
    long long A, B, x, y, gcd;
    long long *px, *py, *pgcd;
    
    px = &x, py = &y, pgcd = &gcd;
    A = 12, B = 42;

    bezoutCoefficient(A, B, px, py, pgcd);
    cout << A << " x (" << x << ") + " << B << " x (" << y << ") = " << gcd << endl;
    return 0;
}
