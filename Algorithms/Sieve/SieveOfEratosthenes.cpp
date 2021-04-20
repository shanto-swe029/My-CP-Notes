#include <iostream>
using namespace std;

bool isPrime[10000000];

void sieveOfEratosthenes(int n) {
    for(int i = 0; i <= n;++i) {
        isPrime[i] = true;
    }
    isPrime[0] = false;
    isPrime[1] = false;
    for(int i = 2; i * i <= n; ++i) {
         if(isPrime[i] == true) {
             for(int j = i * i; j <= n ;j += i)
                 isPrime[j] = false;
        }
    }
}

int  main()
{
    sieveOfEratosthenes(100);
    for( int i = 1; i <= 100; i++ ) 
        if( isPrime[i] ) 
            std::cout << i << "\tprime" << endl;
        else 
            std::cout << i << "\tnot prime" << endl;
}
