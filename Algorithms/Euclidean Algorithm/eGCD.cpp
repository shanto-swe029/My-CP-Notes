/*
    Extended Euclidean Algorithm
    ---------------------------------------------------------
    For two integers A & B find two integers x & y such that
    
                A * x + B * y = gcd(A, B)
    ---------------------------------------------------------
*/


#include < iostream >
using namespace std;

long long d, x, y;

void extendedEuclid(long long A, long long B) {
    if(B == 0) {
        d = A;
        x = 1;
        y = 0;
    }
    else {
        extendedEuclid(B, A%B);
        long long temp = x;
        x = y;
        y = temp - (A/B)*y;
    }
}

int main( ) {
	extendedEuclid(16, 10);
	cout << "The GCD of 16 and 10 is " << d << endl;
	cout << "Coefficient x and y are: "<< x <<  "and  " << y << endl;
	return 0;
}
