#include <bits/stdc++.h>
using namespace std;

const int MAX_NODE 500

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
    int mid = (left + right) / 2;
    update(left, b, mid, i, j, x);
    update(right, mid+1, e, i, j, x);
    tree[node].sum = tree[left].sum + tree[right].sum + (e-b+1) * tree[node].prop;
}

int query( int node, int b, int e, int i, int j, int carry = 0 ) 
{
    if( i > e || j < b ) {
        return 0;
    }
    if( b >= i && j <= e ) {
        return tree[node].sum + carry * (e-b+1);
    }
    
    int left = 2 * node, right = left + 1;
    int mid = (left + right) / 2;
    int p1 = query( left, b, mid, i, j, carry + tree[node].prop );
    int p2 = query( right, mid+1, e, i, j, carry + tree[node].prop );
    
    return p1 + p2;
}

int main()
{
    

    return 0;
}
