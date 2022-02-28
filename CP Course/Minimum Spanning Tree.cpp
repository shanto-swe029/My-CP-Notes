/*
            Minimum Spanning Tree
            
           shanto-swe029.github.io
*/

#include <bits/stdc++.h>
using namespace std;

struct edge {
    int from, to, weight;
    
    edge( int u, int v, int w ) : from(u), to(v), weight(w){}
    
    bool operator < (const edge& p ) const {
        return weight < p.weight;
    }
};

std::vector < edge > graph;
std::vector < int > parent;

int findParent( int node ) {
    if( parent[node] == node ) {
        return node;
    }
    return parent[node] = findParent( parent[node] );
}

int MST( int nodeNumber ) {
    sort(graph.begin(), graph.end());
    
    for( int i = 1; i <= nodeNumber; i++ ) {
        parent[i] = i;
    }
    
    int cost = 0;
    
    for( int i = 0; i < graph.size(); i++ ) {
        int from = findParent(graph[i].from);
        int to = findParent(graph[i].to);
        
        if( from != to ) {
            parent[to] = from;
            cost += graph[i].weight;
        }
    }
    return cost;
}

int main()
{
    int nodeCount, edgeCount;
    std::cin >> nodeCount >> edgeCount;
    
    parent.resize(nodeCount+1);
    
    for( int i = 1; i <= edgeCount; i++ ) {
        int u, v, w;
        std::cin >> u >> v >> w;
        
        graph.push_back( edge(u, v, w) );
    }
    
    std::cout << MST( nodeCount );

    return 0;
}
