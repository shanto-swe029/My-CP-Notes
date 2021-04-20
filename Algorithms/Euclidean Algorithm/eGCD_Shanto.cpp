/*
    Extended Euclidean Algorithm     :::     Bezout's Identity
    ----------------------------------------------------------
    For two integers A & B find two integers x & y such that
    
                A * x + B * y = gcd(A, B)
    Here, the existence of x & y are ensured by the "Bezout's
    Identity". x & y are called the "Bezout Coefficients".
    ----------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

// using pair
typedef pair<int, int> pii;
pii extendedEuclid(int a, int b) { // returns x, y | ax + by = gcd(a,b)
  if(b == 0) return pii(1, 0);
  else {
    pii d = extendedEuclid(b, a % b);
    return pii(d.second, d.first - d.second * (a / b));
  }
}

// using pointer
void bezoutCoefficient_Shanto(long long A, long long B, long long* x, long long* y, long long* gcd) {
    if(B == 0) {
        (*gcd) = A;
        (*x) = 1;
        (*y) = 0;
    }
    else {
        bezoutCoefficient_Shanto(B, A%B, x, y, gcd);
        long long temp = (*x);
        (*x) = (*y);
        (*y) = temp - (A/B) * (*y);
    }
    return;
}

int main( ) {
    // using pointer
    long long A, B, x, y, gcd;
    long long *px, *py, *pgcd;
    px = &x, py = &y, pgcd = &gcd;
    A = 12, B = 42;
    bezoutCoefficient_Shanto(A, B, px, py, pgcd);
    cout << A << " x (" << x << ") + " << B << " x (" << y << ") = " << gcd << endl;
    
    // using pair
    pii coef;
    coef = extendedEuclid(A, B);
    long long gcd1 = __gcd(A, B);
    long long x1 = coef.first;
    long long y1 = coef.second;
    cout << A << " x (" << x1 << ") + " << B << " x (" << y1 << ") = " << gcd1 << endl;
    
    return 0;
}
