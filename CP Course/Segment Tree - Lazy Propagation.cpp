#include <bits/stdc++.h>
using namespace std;

const int MAX_NODE = 500;

struct info {
    int sum, prop;
} tree[MAX_NODE * 3];

void update( int node, int b, int e, int i, int j, int x ) 
{
    if( i > e || j < b ) {
        return;
    }
    if( b >= i && e <= j ) {
        tree[node].sum += (e-b+1) * x;
        tree[node].prop += x;
        return;
    }
    int left = 2 * node, right = left + 1;
    int mid = (b + e) / 2;
    update(left, b, mid, i, j, x);
    update(right, mid+1, e, i, j, x);
    tree[node].sum = tree[left].sum + tree[right].sum + (e-b+1) * tree[node].prop;
}

int query( int node, int b, int e, int i, int j, int carry = 0 ) 
{
    if( i > e || j < b ) {
        return 0;
    }
    if( b >= i && e <= j ) {
        return tree[node].sum + carry * (e-b+1);
    }
    
    int left = 2 * node, right = left + 1;
    int mid = (b + e) / 2;
    int p1 = query( left, b, mid, i, j, carry + tree[node].prop );
    int p2 = query( right, mid+1, e, i, j, carry + tree[node].prop );
    
    return p1 + p2;
}

int main()
{
    int n;
    std::cin >> n;
    std::vector < int > arr(n+1);
    for( int i = 1; i <= n; i++ ) {
        std::cin >> arr[i];
        update(1, 1, n, i, i, arr[i]);
    }
    
    int choice;
    while( std::cin >> choice ) {
        if( choice == 1 ) {
            int l, r, x;
            std::cin >> l >> r >> x;
            update(1, 1, n, l, r, x);
        }
        else if( choice == 2 ) {
            int l, r;
            std::cin >> l >> r;
            std::cout << query(1, 1, n, l, r) << endl;
        }
        else {
            break;
        }
    }

    return 0;
}
