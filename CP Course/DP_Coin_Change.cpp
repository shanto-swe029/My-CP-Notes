#include <bits/stdc++.h>
using namespace std;

#define inf (int)1e9
#define MAX_N 20
#define MAX_W 10000

int mem[MAX_N][MAX_W];
int coins[MAX_N];
int n;

int minCoin( int i, int target ) {
    if( target < 0 ) return inf;
    if( i == n ) {
        if( target == 0 ) return 0;
        return inf;
    }
    if( mem[i][target] != -1 ) {
        return mem[i][target];
    }
    int res_1 = 1 + minCoin(i+1, target - coins[i]);
    int res_2 = minCoin(i+1, target);
    
    return mem[i][target] = min( res_1, res_2 );
}

int helper( int i, int w, int k ) {
    if( w < 0 ) return inf;
    if( i == k ) {
        if( w == 0 ) return 0;
        return inf;
    }
    return mem[i][w];
}

int minCoinIterative( int k, target ) {
    for( int i = n-1; i >= 0; i-- ) {
        for( int w = 0; w <= target; w++ ) {
            int res_1 = 1 + helper(i+1, w-coins[i], k);
            int res_2 = helper(i+1, w, n);
            mem[i][w] = min( res_1, res_2 );
        }
    }
    return mem[0][target];
}

int main()
{
    int target;
    std::cin >> n >> target;
    for( int i = 0; i < n; i++ ) {
        std::cin >> coins[i];
    }
    
    std::cout << minCoin(0, target);

    return 0;
}
