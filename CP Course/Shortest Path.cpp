#include <bits/stdc++.h>
using namespace std;

#define debug 0

/*
Input:
5 6
0 4 5
0 3 7
1 4 2
1 3 3
1 2 4
2 3 1
0 2

Output:
8
*/

int main()
{
    int n, m;
    std::cin >> n >> m;
    
    vector < vector < pair<int, int> > > graph;
    graph.resize(n);
    
    // storing graph
    int u, v, w;
    for( int i = 0; i < m; i++ ) {
        cin >> u >> v >> w;
        pair<int, int> pp;
        pp.first = v; pp.second = w;
        graph[u].push_back(pp);
        pp.first = u; pp.second = w;
        graph[v].push_back(pp);
    }
    
    int root;
    std::cin >> root;
    
    // cost array 
    int cost[n];
    for( int i = 0; i < n; i++ ) {
        cost[i] = 10000;
    }
    
    queue< int > q;
    q.push(root);
    cost[root] = 0;
    
    while( !q.empty() ){
        int currentNode = q.front(); q.pop();
        
        for( auto node : graph[currentNode] ) {
            
            int nextNode = node.first;
            int nodeCost = node.second;
            if( cost[currentNode] + nodeCost < cost[nextNode] ) {
                //update cost 
                cost[nextNode] = cost[currentNode] + nodeCost;
                q.push(nextNode);
            }
        }
    }
    
    // scan destination node 
    int destinationNode;
    std::cin >> destinationNode;
    
    std::cout << cost[destinationNode] << endl;
}
